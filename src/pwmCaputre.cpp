//
// Created by 神奇bug在哪里 on 2023/3/2.
//
#include <Arduino.h>
#include "settings.h"
#include "pwmCaputre.h"

PWM_Analyzer pwmAn(PWM_CH1);

void pwmCaputre::setup() {
    pwm = &pwmAn;
    pinMode(PWM_CH1, INPUT);
    pwm->Stop();
}

bool pwmCaputre::is_running() {
    return running;
}

void pwmCaputre::start() {
    running = true;
    if (pwm == nullptr) {
        Serial.println("[警告] [PWMCaputre] 空指针错误");
        return;
    }
    pwm->Restart();
}
void pwmCaputre::stop() {
    running = false;
    if (pwm == nullptr) {
        Serial.println("[警告] [PWMCaputre] 空指针错误");
        return;
    }
    pwm->Stop();
}

pwmCaputre::PWM_INFO pwmCaputre::get_info() {
    if (pwm== nullptr) {
        Serial.println("[警告] [PWMCaputre] 空指针错误");
        return {0, 0};
    }
    if (running) {
        return {pwm->Get_PWM_frequency(), pwm->Get_PWM_duty_cycle()};
    }
    Serial.println("[警告] [PWMCaputre] 未启动");
    return {0, 0};
}
