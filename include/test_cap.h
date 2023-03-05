//
// Created by 神奇bug在哪里 on 2023/3/5.
//

#ifndef ESP32_ICEC_TEST_CAP_H
#define ESP32_ICEC_TEST_CAP_H

#include "sdkconfig.h"
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include "driver/timer.h"
#include "esp_timer.h"
#include "driver/pcnt.h"

#define EXTI_GPIO_PIN           GPIO_NUM_34

#define TIMER_GROUP             TIMER_GROUP_0
#define TIMER_INDEX             TIMER_0
#define TIMER_INIR              TIMER_INTR_T0

#define PCNT_UNIT               PCNT_UNIT_0
#define PCNT_H_LIM_VAL          30000
#define PCNT_L_LIM_VAL          (-30000)
#define PCNT_INPUT_SIG_IO       GPIO_NUM_34         //脉冲输入GPIO
#define PCNT_INPUT_CTRL_IO      GPIO_NUM_35         //控制GPIO     Control GPIO HIGH = count up, LOW = count down

#define	GET_DUTY_EVENT		    (0X01 << 0)
#define	GET_FREQUENCY_EVENT		(0X01 << 1)

typedef struct
{
    uint64_t   t0_h_time;
    uint64_t   cycle_time;
    int16_t    frequency;
}input_capture_t;

extern input_capture_t cap;

void  capture_duty_install_service(void);
void  capture_duty_uninstall_service(void);
void  capture_frequency_install_service(void);
void  capture_frequency_uninstall_service(void);

#endif //ESP32_ICEC_TEST_CAP_H
