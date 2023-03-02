//
// Created by 神奇bug在哪里 on 2023/3/1.
//

#ifndef ESP32_ICEC_DISPLAYCORE_H
#define ESP32_ICEC_DISPLAYCORE_H
#include <Arduino.h>
#include <U8g2lib.h>
#include <MUIU8g2.h>
#include <Wire.h>
enum pages {main,timeSet,alarmSet,onAlarm,pwmAnalytic,};
U8G2_SSD1309_128X64_NONAME0_2_SW_I2C u8g2(U8G2_R0, SCL, SDA);
class displayCore {
private:
    byte page = 0;
    U8G2_SSD1309_128X64_NONAME0_2_SW_I2C * display = &u8g2;

public:
    void setup();
    void loop();
    void SetPage(int page);

};


#endif //ESP32_ICEC_DISPLAYCORE_H
