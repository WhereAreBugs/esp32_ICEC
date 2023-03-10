#ifndef ESP32_ICEC_ALARM_H
#define ESP32_ICEC_ALARM_H
#include <Arduino.h>
#include "DS1307_time.h"
class alarmSet{
private:
    byte hour;
    byte minute;
    byte second;
public:
    bool operator==(const DateTime& dat) const;
    alarmSet & operator= (const alarmSet  & dat) = default;
    alarmSet & operator= (alarmSet dat) = default;
    alarmSet(byte hour, byte minute, byte second);
    alarmSet();
};
class AlarmManagement{
private:
    alarmSet alarmSet;
public:
    void setAlarm(DateTime time);
    void setup();
    void loop();
    class alarmSet getAlarmSet()
    {
        return alarmSet;
    }
};

#endif //ESP32_ICEC_ALARM_H