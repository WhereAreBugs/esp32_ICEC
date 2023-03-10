//
// Created by 神奇bug在哪里 on 2023/3/2.
//
#include <Arduino.h>
#include "settings.h"
#include "test_cap.h"
#include "pwmCaputre.h"
#include "logSystem.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"
EventGroupHandle_t   xEventGroup_Handle = nullptr;
pwmCaputre * this_ = nullptr;
void capture_stak(void *arg)
{
    log(MODULE_PWM,LOG_LEVEL_DEBUG,"capture_stak entered");
    EventBits_t uxBits;
    while(true)
    {
        if (!this_->is_running()) {
            log(MODULE_PWM,LOG_LEVEL_DEBUG,"capture_stak is not start");
            vTaskDelay(1000);
            continue;
        }
        log(MODULE_PWM,LOG_LEVEL_DEBUG,"capture_stak is start");
        capture_duty_install_service();
        uxBits = xEventGroupWaitBits(xEventGroup_Handle,
                                     GET_DUTY_EVENT | GET_FREQUENCY_EVENT,
                                     pdTRUE,
                                     pdFALSE,
                                     portMAX_DELAY);
        if(uxBits & GET_DUTY_EVENT)
        {
            this_->pwmInfo.t0_h = cap.t0_h_time;
            this_->pwmInfo.T = cap.cycle_time;
            this_->pwmInfo.duty = (float)cap.t0_h_time / cap.cycle_time * 100;
    Serial.printf("t0_h_time:%u,cycle_time:%u,duty:%f", cap.t0_h_time, cap.cycle_time, this_->pwmInfo.duty);

            capture_duty_uninstall_service();
            capture_frequency_install_service();
        }
        else if(uxBits & GET_FREQUENCY_EVENT)
        {
            this_->pwmInfo.freq = -cap.frequency;
            Serial.printf("frequency:%u", this_->pwmInfo.freq);
            Serial.println(" Success");
            capture_frequency_uninstall_service();
        }
    }
}

void pwmCaputre::setup() {
    xEventGroup_Handle = xEventGroupCreate();
    xTaskCreate(capture_stak,"capture_stak",1024 * 5,nullptr,5,nullptr);
    this_ = this;
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


#pragma clang diagnostic pop