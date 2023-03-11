//
// Created by 神奇bug在哪里 on 2023/3/1.
//

#ifndef ESP32_ICEC_DISPLAYCORE_H
#define ESP32_ICEC_DISPLAYCORE_H
#include "esphome.h"
#include <U8g2lib.h>
#include <MUIU8g2.h>
#include <Wire.h>
#include "TouchButton.h"


extern TimeSet timeSet;

class displayCore : esphome::Component {
private:
    U8G2_SSD1309_128X64_NONAME0_F_SW_I2C * display = nullptr;

public:
    void setup() override;
    void loop() override;
};


#endif //ESP32_ICEC_DISPLAYCORE_H
