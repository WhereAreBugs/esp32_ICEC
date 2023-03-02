//
// Created by 神奇bug在哪里 on 2023/3/1.
//

#ifndef ESP32_ICEC_DISPLAYCORE_H
#define ESP32_ICEC_DISPLAYCORE_H
#include <Arduino.h>
#include <U8g2lib.h>
#include <MUIU8g2.h>
#include <Wire.h>
#include "temperature.h"
#include "DS1302.h"
enum pages {mainMenu,timeSet,alarmSet,onAlarm,pwmAnalytic,getDistance,aboutGroup};

class displayCore {
private:
    pages page = mainMenu;
    U8G2_SSD1309_128X64_NONAME0_2_SW_I2C * display = nullptr;
    temperature * temp = nullptr;
    DS1302 * ds = nullptr;

public:
    void setup();
    void loop();
    void SetPage(int page);

};


#endif //ESP32_ICEC_DISPLAYCORE_H
