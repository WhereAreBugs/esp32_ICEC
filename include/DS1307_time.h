//
// Created by 神奇bug在哪里 on 2023/2/28.
//
#include <Arduino.h>

#ifndef ESP32_ICEC_TIME_H
#define ESP32_ICEC_TIME_H
struct DS1307_time{
    byte second;
    byte minute;
    byte hour;
    byte dayOfWeek;
    byte dayOfMonth;
    byte month;
    byte year;
};
class DS1307{
private:
    struct DS1307_time currentTime;
    static byte bcdToDec(int read);
public:
    void RTCsetup();
    void readTime();
    DS1307_time getTime();
    bool setTime(DS1307_time time);

};
#endif //ESP32_ICEC_TIME_H
