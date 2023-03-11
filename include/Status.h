//
// Created by 神奇bug在哪里 on 2023/3/1.
//
#ifndef ESP32_ICEC_STATUS_H
#define ESP32_ICEC_STATUS_H

#include <Arduino.h>
#include "esphome.h"
union SYSStatus{
    byte alarmEN : 1;
    /* 0:关闭
     * 1:开启
     * */
    byte currentPage : 3; //max:3
    /* 0:主界面，温度
     * 1:PWM
     * 2:闹钟设置
     * 3:距离
     * 4:关于页面
     * 5:时间设置
     * 6:其他设置
     * ***INFO***
     * 目前在其他设置中规划的只有alarm温度设置
     * 7:闹钟响起！
     * */
    byte temperatureWarning : 1;
    byte timeSetNow : 3;
    /* 0:未设置
     * 1:设置年
     * 2:设置月
     * 3:设置日
     * 4:设置时
     * 5:设置分
     * 6:设置秒
     * 7:设置闹钟en(仅在alarm设置中有效)
     * */
    uint8_t summary = 0;
};
class SYSManeger : esphome::Component{
    /*
     * 用于管理系统部分IO的启用和关闭
     * 1. distance
     * 2. DHT11
     */
private:
    SYSStatus status;
public:
    void setup() override;
    void loop() override;
    SYSStatus get_Status();
    void set_Status(uint8_t _status);
    void timeSetNow(uint8_t timeSetNow);
};


#endif //ESP32_ICEC_STATUS_H
