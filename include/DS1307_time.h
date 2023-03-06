//
// Created by 神奇bug在哪里 on 2023/2/28.
//

#ifndef ESP32_ICEC_TIME_H
#define ESP32_ICEC_TIME_H

#include <Arduino.h>
#include <RTClib.h>
struct setTime_{
    byte year;
    byte month;
    byte day;
    byte hour;
    byte minute;
    byte second;
};
enum DS1307_status{
    DS1307_OK,
    DS1307_ERROR_CONNECT,
    DS1307_ERROR_RESET,
};
class DS1307{
private:
    DateTime now;
    RTC_DS1307 rtc;
    const char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    DS1307_status Status = DS1307_ERROR_CONNECT;
public:
    void setup();
    void readTime();
    DateTime getTime();
    bool setTime(DateTime time);
    DS1307_status getStatus();

};
#endif //ESP32_ICEC_TIME_H
