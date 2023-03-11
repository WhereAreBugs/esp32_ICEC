#include "alarm.h"
#include "../include/Status.h"
#include "../include/settings.h"
#include "../include/logSystem.h"
#include "RTClib.h"
bool tiggered = false;
byte alarmCount = 0;
AlarmSet alarmSet;
extern SYSManeger *  sys;
extern esphome::ds1307::DS1307Component *ds1307_time;
void setAlarm(DateTime time) {
    alarmSet = time;
}
void alarmEvent(){

    auto result = sys->get_Status();
    if (result.currentPage == 7) {
        log(MODULE_ALARM,LOG_LEVEL_DEBUG,"alarm event triggered in alarm page");
        if (alarmCount < 3)
        {
            digitalWrite(BUZZER_OUTPUT,HIGH);
        }
        else
        {
            digitalWrite(BUZZER_OUTPUT,LOW);
            result.currentPage = 0;
            sys->set_Status(result.summary);
            alarmCount = 0;
        }
    }
}

AlarmSet getAlarmSet() {
    return alarmSet;
}


void alarm() {
    if (tiggered) {
        return;
    }
    if (sys->get_Status().alarmEN) {
        if (alarmSet == ds1307_time->now()) {
            log(MODULE_ALARM,LOG_LEVEL_DEBUG,"alarm triggered");
            auto result = sys->get_Status();
            result.alarmEN = 1;
            sys->set_Status(result.summary);
        }
    }
}

void setAlarm(byte hour, byte minute, byte second) {
    alarmSet = DateTime(2000, 1, 1, hour, minute, second);

}

bool AlarmSet::operator==(const DateTime& dat) const {
    if (hour == dat.hour()&&minute == dat.minute()&&second == dat.second())
        return true;
    else
        return false;
}

AlarmSet::AlarmSet(byte hour, byte minute, byte second) {
    this->hour = hour;
    this->minute = minute;
    this->second = second;

}

AlarmSet::AlarmSet() {
    hour = 0;
    minute = 0;
    second = 0;

}

AlarmSet &AlarmSet::operator=(const DateTime &dat) {
    this->hour = dat.hour();
    this->minute = dat.minute();
    this->second = dat.second();
    return *this;
}

AlarmSet &AlarmSet::operator=(const esphome::time::ESPTime &dat) {
    this->hour = dat.hour;
    this->minute = dat.minute;
    this->second = dat.second;
    return *this;
}

bool AlarmSet::operator==(const esphome::time::ESPTime &dat) const {
    if (hour == dat.hour&&minute == dat.minute&&second == dat.second)
        return true;
    else
        return false;
}




