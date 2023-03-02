//
// Created by 神奇bug在哪里 on 2023/3/1.
//

#ifndef ESP32_ICEC_TOUCHBOUTTON_H
#define ESP32_ICEC_TOUCHBOUTTON_H
#include "Arduino.h"
#include "OneButton.h"
class TouchBoutton {
private:
    OneButton * button1 = new OneButton(12, true);
    OneButton * button2 = new OneButton(13, true);
    OneButton * button3 = new OneButton(14, true);
    OneButton * button4 = new OneButton(15, true);
public:
    void setup();
    virtual void loop() = 0; //disable loop
};


#endif //ESP32_ICEC_TOUCHBOUTTON_H
