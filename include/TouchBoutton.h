//
// Created by 神奇bug在哪里 on 2023/3/1.
//

#ifndef ESP32_ICEC_TOUCHBOUTTON_H
#define ESP32_ICEC_TOUCHBOUTTON_H
#include "Arduino.h"
#include "OneButton.h"
#include "settings.h"
class TouchBoutton {
private:
    OneButton * button1 = new OneButton(BUTTON1, true);
    OneButton * button2 = new OneButton(BUTTON2, true);
    OneButton * button3 = new OneButton(BUTTON3, true);
    OneButton * button4 = new OneButton(BUTTON4, true);
public:
    void setup();
    virtual void loop() = 0; //disable loop
};
void button_handle1();
void button_handle2();
void button_handle3();
void button_handle4();
void button_handle1_long_press();
void button_handle2_long_press();
void button_handle3_long_press();
void button_handle4_long_press();

#endif //ESP32_ICEC_TOUCHBOUTTON_H
