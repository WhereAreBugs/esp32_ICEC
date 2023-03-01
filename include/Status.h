//
// Created by 神奇bug在哪里 on 2023/3/1.
//
#ifndef ESP32_ICEC_STATUS_H
#define ESP32_ICEC_STATUS_H
#include <Arduino.h>
union SYSStatus{
    byte alarm : 1;
    byte currentPage : 2; //max:3
    byte func : 2; //max:3
    int sum;
};
class SYSStatusManager{

};
#endif //ESP32_ICEC_STATUS_H
