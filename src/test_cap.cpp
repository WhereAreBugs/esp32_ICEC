//
// Created by 神奇bug在哪里 on 2023/3/5.
//
#include "test_cap.h"

extern EventGroupHandle_t xEventGroup_Handle;
esp_timer_handle_t esp_timer_handle;
input_capture_t cap = {0};

static void IRAM_ATTR exti_isr_handler(void *arg)
{
    static uint8_t status = 0;
    static uint8_t count = 0;
    uint8_t gpio_level = gpio_get_level(EXTI_GPIO_PIN);

    if(status == 0 && gpio_level)
    {
        timer_set_counter_value(TIMER_GROUP,TIMER_INDEX,0x00000000ULL);
        status = 1;
    }
    else if(status == 1 && !gpio_level)
    {
        timer_get_counter_value(TIMER_GROUP,TIMER_INDEX,&cap.t0_h_time);
        status = 2;
    }
    else if(status == 2 && gpio_level)
    {
        timer_get_counter_value(TIMER_GROUP,TIMER_INDEX,&cap.cycle_time);
        status = 0;
        count++;
        if(count >= 3)
        {
            status = 3;
            BaseType_t xHigherPriorityTaskWoken, xResult;
            xResult = xEventGroupSetBitsFromISR(xEventGroup_Handle,
                                                GET_DUTY_EVENT,
                                                &xHigherPriorityTaskWoken);
            if(xResult)
            {
                portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
            }
        }
    }
}


static void EXTI_Init(void)
{
    const gpio_config_t   exti_config = {
            .pin_bit_mask   = (1ULL << EXTI_GPIO_PIN),
            .mode           = GPIO_MODE_INPUT,
            .pull_up_en     = GPIO_PULLUP_DISABLE,
            .pull_down_en   = GPIO_PULLDOWN_ENABLE,
            .intr_type      = GPIO_INTR_ANYEDGE,
    };
    gpio_config(&exti_config);

    gpio_install_isr_service(ESP_INTR_FLAG_LEVEL2);
    gpio_isr_handler_add(EXTI_GPIO_PIN,exti_isr_handler,NULL);
}


static void Hardware_Timer_Init(void)
{
    const timer_config_t timer_config = {
            .alarm_en = TIMER_ALARM_DIS,             //到达计数值启动报警（计数值溢出，进入中断）
            .counter_en = TIMER_PAUSE,              //调用timer_init()后不启动计数，调用timer_start()才开始计数
            .counter_dir = TIMER_COUNT_UP,          //向上计数
            .auto_reload = TIMER_AUTORELOAD_EN,     //使能自动重装载
            .divider = 8,                           //分频值
    };
    timer_init(TIMER_GROUP,TIMER_INDEX,&timer_config);

    timer_set_counter_value(TIMER_GROUP,TIMER_INDEX,0x00000000ULL);
    timer_start(TIMER_GROUP,TIMER_INDEX);
}

static void Pcnt_Init(void)
{
    const pcnt_config_t pcnt_config = {
            .pulse_gpio_num = PCNT_INPUT_SIG_IO,
            .ctrl_gpio_num = PCNT_INPUT_CTRL_IO,
            .lctrl_mode = PCNT_MODE_REVERSE,    //如果计数方向低，则反向计数
            .hctrl_mode = PCNT_MODE_KEEP,       //如果高，则保持主计数器模式
            .pos_mode = PCNT_COUNT_INC,         //计算正边沿
            .neg_mode = PCNT_COUNT_DIS,         //计算反边沿
            .counter_h_lim = PCNT_H_LIM_VAL,    //设置最大值
            .counter_l_lim = PCNT_L_LIM_VAL,
            .unit = PCNT_UNIT,
            .channel = PCNT_CHANNEL_0,
    };
    pcnt_unit_config(&pcnt_config);

    pcnt_set_filter_value(PCNT_UNIT, 100); // 第二个参数的注释为PCNT信号的滤波值，计数器在APB_CLK周期的任何持续时间比这短的脉冲将被忽略，当过滤器被启用时。
    pcnt_filter_enable(PCNT_UNIT);

   // pcnt_counter_pause(PCNT_UNIT);          //暂停计数
    //pcnt_counter_clear(PCNT_UNIT);          //清除计数

//    pcnt_counter_resume(PCNT_UNIT);         //开始计数
}

//软件定时器回调函数
static void esp_timer_cb(void *arg)
{
    static uint8_t count = 0;
    BaseType_t xHigherPriorityTaskWoken, xResult;

    pcnt_get_counter_value(PCNT_UNIT,&cap.frequency);                     //每秒钟的脉冲个数就是频率
    pcnt_counter_clear(PCNT_UNIT);
    count++;
    if(count >= 3)
    {
        xResult = xEventGroupSetBitsFromISR(xEventGroup_Handle,
                                            GET_FREQUENCY_EVENT,
                                            &xHigherPriorityTaskWoken);
        if(xResult)
        {
            portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
        }
    }
}

static void Software_Timer_Init(void)
{
    const esp_timer_create_args_t fw_timer = {
            .callback = &esp_timer_cb,
            .arg = NULL,
            .name = "esp_timer",
    };

    esp_timer_create(&fw_timer,&esp_timer_handle);
    esp_timer_start_periodic(esp_timer_handle,1000 * 1000);
}

void  capture_duty_install_service(void)
{
    Hardware_Timer_Init();
    EXTI_Init();
}

void  capture_duty_uninstall_service(void)
{
    gpio_isr_handler_remove(EXTI_GPIO_PIN);
    timer_deinit(TIMER_GROUP,TIMER_INDEX);
}

void  capture_frequency_install_service(void)
{
    Pcnt_Init();
    Software_Timer_Init();
}

void  capture_frequency_uninstall_service(void)
{
    esp_timer_stop(esp_timer_handle);
    esp_timer_delete(esp_timer_handle);
}
