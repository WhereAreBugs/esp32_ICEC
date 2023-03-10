#ifndef ESP32_ICEC_ALARM_H
#define ESP32_ICEC_ALARM_H
#include <Arduino.h>
#include "DS1307_time.h"
class AlarmSet{
private:
    byte hour;
    byte minute;
    byte second;
public:
    bool operator==(const DateTime& dat) const;
    AlarmSet & operator= (const AlarmSet  & dat) = default;
    AlarmSet & operator= (const DateTime  & dat);
    AlarmSet(byte hour, byte minute, byte second);
    byte getHour() const{return hour;}
    byte getMinute() const{return minute;}
    byte getSecond() const{return second;}

    AlarmSet();
};
class AlarmManagement{
private:
    AlarmSet alarmSet;
public:
    void setAlarm(DateTime time);
    void setup();
    void loop();
    class AlarmSet getAlarmSet()
    {
        return alarmSet;
    }
};

#endif //ESP32_ICEC_ALARM_H