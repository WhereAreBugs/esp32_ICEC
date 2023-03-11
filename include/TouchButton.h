//
// Created by 神奇bug在哪里 on 2023/3/1.
//

#ifndef ESP32_ICEC_TOUCHBUTTON_H
#define ESP32_ICEC_TOUCHBUTTON_H
#include "Arduino.h"
#include "OneButton.h"
#include "settings.h"
#include "Status.h"
struct TS
{
    TS(uint16_t i, uint8_t i1, uint8_t i2, uint8_t i3, uint8_t i4, uint8_t i5);
    TS();
    int year = 2000;
    byte month = 1;
    byte day = 1;
    byte hour = 0;
    byte minute = 0;
    byte second = 0;
};
typedef struct TS TimeSet;

void button_handle1();
void button_handle2();
void button_handle3();
void button_handle4();
void button_handle2_double_click();
void button_handle1_double_click();
void button_handle3_double_click();
void button_handle4_double_click();
TS getTimeSet();
bool is_doubleYear(int a);
#endif //ESP32_ICEC_TOUCHBUTTON_H
