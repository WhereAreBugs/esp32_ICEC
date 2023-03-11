#ifndef ESP32_ICEC_ALARM_H
#define ESP32_ICEC_ALARM_H
#include <Arduino.h>
#include "esphome.h"
#include "RTClib.h"

class AlarmSet{
private:
    byte hour;
    byte minute;
    byte second;
public:
    bool operator==(const DateTime& dat) const;
    bool operator==(const esphome::time::ESPTime& dat) const;
    AlarmSet & operator= (const AlarmSet  & dat) = default;
    AlarmSet & operator= (const DateTime  & dat);
    AlarmSet & operator= (const esphome::time::ESPTime  & dat);
    AlarmSet(byte hour, byte minute, byte second);
    byte getHour() const{return hour;}
    byte getMinute() const{return minute;}
    byte getSecond() const{return second;}
    AlarmSet();
};
void alarmEvent();
AlarmSet getAlarmSet();
void alarm();
void setAlarm(byte hour, byte minute, byte second);
#endif //ESP32_ICEC_ALARM_H