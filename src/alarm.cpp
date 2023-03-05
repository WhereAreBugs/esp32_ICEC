#include "alarm.h"
#include "DS1307_time.h"
#include "Status.h"

extern DS1307 ds;
extern SYSManeger sysManeger;
void AlarmManagement::setAlarm(bool en, DateTime time) {
    this->en = en;
    this->alarmSet = time;
}

void AlarmManagement::setup() {
    en = false;
    alarmSet = DateTime(2000,0,0,0,0,0);
}

void AlarmManagement::loop() {
    if (en) {
        if (alarmSet == ds.getTime()) {
            auto result = sysManeger.get_Status();
            result.alarmEN = 1;
            sysManeger.set_Status(result.summary);
        }
    }
}