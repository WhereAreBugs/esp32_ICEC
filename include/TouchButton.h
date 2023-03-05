//
// Created by 神奇bug在哪里 on 2023/3/1.
//

#ifndef ESP32_ICEC_TOUCHBUTTON_H
#define ESP32_ICEC_TOUCHBUTTON_H
#include "Arduino.h"
#include "OneButton.h"
#include "settings.h"
#include "Status.h"
#include "DS1307_time.h"
struct TS
{
    int year = 2000;
    byte month = 1;
    byte day = 1;
    byte hour = 0;
    byte minute = 0;
    byte second = 0;
};
typedef struct TS TimeSet;
class TouchButton {
private:
    OneButton * button1 = new OneButton(BUTTON1, true);
    OneButton * button2 = new OneButton(BUTTON2, true);
    OneButton * button3 = new OneButton(BUTTON3, true);
    OneButton * button4 = new OneButton(BUTTON4, true);

public:
    void setup();
    static bool getAlarmEn();
    static TimeSet getTimeSet();
};
void button_handle1();
void button_handle2();
void button_handle3();
void button_handle4();
void button_handle1_long_press();
void button_handle2_long_press();
void button_handle3_long_press();
void button_handle4_long_press();
void button_handle1_double_click();
void button_handle3_double_click();
void button_handle4_double_click();

bool is_runnina(int a);
#endif //ESP32_ICEC_TOUCHBUTTON_H
