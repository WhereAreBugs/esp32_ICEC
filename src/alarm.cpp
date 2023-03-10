#include "alarm.h"
#include "DS1307_time.h"
#include "Status.h"
#include "settings.h"
#include <Ticker.h>
#include "logSystem.h"
byte alarmCount = 0;
byte ledCount = 0;
extern DS1307 ds;
extern SYSManeger sysManeger;
void AlarmManagement::setAlarm(DateTime time) {
    this->alarmSet = time;
}
void alarmEvent(){
    log(MODULE_ALARM,LOG_LEVEL_DEBUG,"alarm event triggered");
    auto result = sysManeger.get_Status();
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
            sysManeger.set_Status(result.summary);
            alarmCount = 0;
        }
    }
    else if (result.temperatureWarning == 1)
    {
        log(MODULE_ALARM,LOG_LEVEL_DEBUG,"alarm event triggered in temperature warning");
        if (ledCount / 2 == 0 && ledCount < 6)
        {
            digitalWrite(LED_OUTPUT,HIGH);
        }
        else
        {
            digitalWrite(LED_OUTPUT,LOW);
            if (ledCount == 6)
            {
                ledCount = 0;
                result.temperatureWarning = 0;
                sysManeger.set_Status(result.summary);
            }
        }
    }
}
void AlarmManagement::setup() {
    auto i = sysManeger.get_Status();
    i.alarmEN = false;
    sysManeger.set_Status(i.summary);

    pinMode(LED_OUTPUT,OUTPUT);
    pinMode(BUZZER_OUTPUT,OUTPUT);
    digitalWrite(LED_OUTPUT,LOW);
    digitalWrite(BUZZER_OUTPUT,LOW);
    log(MODULE_ALARM,LOG_LEVEL_DEBUG,"alarm pin setup finished");
    Ticker ticker;  //创建一个定时器对象
    ticker.attach(1, alarmEvent);  //每隔1秒执行一次alarmEvent函数

}

void AlarmManagement::loop() {
    if (sysManeger.get_Status().alarmEN) {
        //TODO: change the time judge method
        if (alarmSet == ds.getTime()) {
            log(MODULE_ALARM,LOG_LEVEL_DEBUG,"alarm triggered");
            auto result = sysManeger.get_Status();
            result.alarmEN = 1;
            sysManeger.set_Status(result.summary);
        }
    }
}

bool alarmSet::operator==(const DateTime& dat) const {
    if (hour == dat.hour()&&minute == dat.minute()&&second == dat.second())
        return true;
    else
        return false;
}

alarmSet::alarmSet(byte hour, byte minute, byte second) {
    this->hour = hour;
    this->minute = minute;
    this->second = second;

}

alarmSet::alarmSet() {
    hour = 0;
    minute = 0;
    second = 0;

}




