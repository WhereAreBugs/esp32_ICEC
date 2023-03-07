//
// Created by 神奇bug在哪里 on 2023/3/2.
//
#include <Arduino.h>
#include "settings.h"
#include "test_cap.h"
#include "pwmCaputre.h"


EventGroupHandle_t   xEventGroup_Handle = NULL;
pwmCaputre * __this__ = nullptr;
void capture_stak(void *arg)
{
    EventBits_t uxBits;
    while(true)
    {
        if (!__this__->is_running()) {
            vTaskDelay(200);
            yield();
            continue;
        }
        capture_duty_install_service();
        uxBits = xEventGroupWaitBits(xEventGroup_Handle,
                                     GET_DUTY_EVENT | GET_FREQUENCY_EVENT,
                                     pdTRUE,
                                     pdFALSE,
                                     portMAX_DELAY);
        if(uxBits & GET_DUTY_EVENT)
        {
            __this__->pwmInfo.t0_h = cap.t0_h_time;
            __this__->pwmInfo.T = cap.cycle_time;
            __this__->pwmInfo.duty = (float)cap.t0_h_time / cap.cycle_time * 100;
            Serial.printf("t0_h_time:%llu,cycle_time:%llu,duty:%f", __this__->pwmInfo.t0_h, __this__->pwmInfo.T, __this__->pwmInfo.duty);
            Serial.println(" Success");
            capture_duty_uninstall_service();
            capture_frequency_install_service();
        }
        else if(uxBits & GET_FREQUENCY_EVENT)
        {
            __this__->pwmInfo.freq = -cap.frequency;
            Serial.printf("frequency:%u", __this__->pwmInfo.freq);
            Serial.println(" Success");
            capture_frequency_uninstall_service();
        }
    }
}

void pwmCaputre::setup() {
    xEventGroup_Handle = xEventGroupCreate();
    xTaskCreate(capture_stak,"capture_stak",1024 * 5,NULL,5,NULL);
    __this__ = this;
}


bool pwmCaputre::is_running() const {
    return running;
}

void pwmCaputre::start() {
    running = true;

}
void pwmCaputre::stop() {
    running = false;
}

