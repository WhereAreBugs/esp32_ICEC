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
#include "DS1307_time.h"


class displayCore {
private:
    U8G2_SSD1309_128X64_NONAME0_F_SW_I2C * display = nullptr;
    temperature * temp = nullptr;
    DS1307 * ds = nullptr;

public:
    void setup();
    void loop();

};


#endif //ESP32_ICEC_DISPLAYCORE_H
