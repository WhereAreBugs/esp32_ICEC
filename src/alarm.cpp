#include "alarm.h"
#include "DS1307_time.h"
#include "Status.h"
#include "settings.h"
#include <Ticker.h>
byte alarmCount = 0;
byte ledCount = 0;
extern DS1307 ds;
extern SYSManeger sysManeger;
void AlarmManagement::setAlarm(DateTime time) {
    this->alarmSet = time;
}
void alarmEvent(){
    auto result = sysManeger.get_Status();
    if (result.currentPage == 7) {
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
    alarmSet = DateTime(2000,0,0,0,0,0);
    pinMode(LED_OUTPUT,OUTPUT);
    pinMode(BUZZER_OUTPUT,OUTPUT);
    digitalWrite(LED_OUTPUT,LOW);
    digitalWrite(BUZZER_OUTPUT,LOW);
    Ticker ticker;  //创建一个定时器对象
    ticker.attach(1, alarmEvent);  //每隔1秒执行一次alarmEvent函数

}

void AlarmManagement::loop() {
    if (sysManeger.get_Status().alarmEN) {
        //TODO: change the time judge method
        if (alarmSet == ds.getTime()) {
            auto result = sysManeger.get_Status();
            result.alarmEN = 1;
            sysManeger.set_Status(result.summary);
        }
    }
}