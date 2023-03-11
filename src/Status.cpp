//
// Created by 神奇bug在哪里 on 2023/3/2.
//
#include "Status.h"
#include "displayCore.h"
#include "logSystem.h"

extern displayCore displayCore;
double alarmTemp = 30.0;

void SYSManeger::setup() {
    status.summary = 0;

}

void SYSManeger::loop() {
    if (status.timeSetNow>=8)
    {
        Serial.println("[ERROR] timeSetNow is out of range!");
        status.timeSetNow=0;
    }
    if (status.currentPage>=8)
    {
        Serial.println("[ERROR] currentPage is out of range!");
        status.currentPage=0;
    }
}

SYSStatus SYSManeger::get_Status() {
    log(MODULE_STATUS,LOG_LEVEL_DEBUG, "status.summary");
    return status;
}

void SYSManeger::set_Status(uint8_t _status) {
    status.summary = _status;

}

void SYSManeger::timeSetNow(uint8_t timeSetNow) {
    this->status.timeSetNow = timeSetNow;
}

