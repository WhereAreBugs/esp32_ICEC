//
// Created by 神奇bug在哪里 on 2023/3/2.
//
#include "Status.h"
#include "Temperature.h"
#include "displayCore.h"
#include "pwmCaputre.h"

extern displayCore displayCore;
extern temperature temperature;
extern pwmCaputre pwm;


void SYSManeger::setup() {
    status.summary = 0;

}

void SYSManeger::loop() {
    if (status.currentPage==0) {
        temperature.loop();
    }
    if (status.currentPage==1) {
        if (!pwm.is_running())
        {pwm.start();}
    }
    if (pwm.is_running()&&status.currentPage!=1) {
        pwm.stop();
    }
    if (status.timeSetNow>=7)
    {
        Serial.println("[ERROR] timeSetNow is out of range!");
        status.timeSetNow=0;
    }
    if (status.currentPage>=6)
    {
        Serial.println("[ERROR] currentPage is out of range!");
        status.currentPage=0;
    }
}

SYSStatus SYSManeger::get_Status() {

    return status;
}

void SYSManeger::set_Status(uint8_t _status) {
    status.summary = _status;

}

void SYSManeger::timeSetNow(uint8_t timeSetNow) {
    this->status.timeSetNow = timeSetNow;
}

