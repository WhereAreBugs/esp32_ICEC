#ifndef ESP32_ICEC_ALARM_H
#define ESP32_ICEC_ALARM_H
#include <Arduino.h>
#include "DS1307_time.h"
class AlarmManagement{
private:
    DateTime alarmSet;
    bool en;
public:
    void setAlarm(bool en,DateTime time);
    void setup();
    void loop();
    DateTime getAlarmSet()
    {
        return alarmSet;
    }
};

#endif //ESP32_ICEC_ALARM_H