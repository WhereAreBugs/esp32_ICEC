//
// Created by 神奇bug在哪里 on 2023/3/1.
//
#ifndef ESP32_ICEC_STATUS_H
#define ESP32_ICEC_STATUS_H
#include <Arduino.h>
union SYSStatus{
    byte alarmEN : 1;
    byte currentPage : 3; //max:3
    /* 0:主界面，温度
     * 1:时间设置
     * 2:PWM
     * 3:闹钟
     * 4:距离
     * 5:关于页面
     * 6:未定义
     * 7:未定义
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
     * 7:未定义
     * */
    uint64_t summary = 0;
};
class SYSManeger{
    /*
     * 用于管理系统部分IO的启用和关闭
     * 1. distance
     * 2. DHT11
     * 3.
     */
private:
    SYSStatus status;
public:
    void setup();
    void loop();
};


#endif //ESP32_ICEC_STATUS_H
