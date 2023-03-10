//
// Created by 神奇bug在哪里 on 2023/2/28.
//
#include <Wire.h>
#include <Arduino.h>
#include "DS1307_time.h"
#include "logSystem.h"
#include "settings.h"

void DS1307::setup() {
    if (! rtc.begin()) {
        Serial.println("Couldn't find RTC");
        Serial.flush();
    }
    if (! rtc.isrunning()) {
        Status = DS1307_ERROR_RESET;
        log(MODULE_DS1307,LOG_LEVEL_WARNING,"RTC is NOT running, let's set the time!");

        // January 21, 2014 at 3am you would call:
        // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
    } else
        Status = DS1307_OK;

}
void DS1307::readTime(){
    //Read the current time
   now = rtc.now();
   if(!now.isValid())
   {
       log(MODULE_DS1307,LOG_LEVEL_WARNING,"RTC is NOT valid");
       Status = DS1307_ERROR_RESET;
   }
   Status = DS1307_OK;
}

DateTime DS1307::getTime() {
    if(!now.isValid())
    {
        log(MODULE_DS1307,LOG_LEVEL_WARNING,"RTC is NOT valid");
        Status = DS1307_ERROR_RESET;
    }
    log(MODULE_DS1307,LOG_LEVEL_DEBUG,"Time is "+String(now.year()) + "-" + String(now.month()) + "-" + String(now.day()) + " " + String(now.hour()) + ":" + String(now.minute()) + ":" + String(now.second()));
    return now;
}

bool DS1307::setTime(DateTime time) {
    String timeStr  = String(time.year()) + "-" + String(time.month()) + "-" + String(time.day()) + " " + String(time.hour()) + ":" + String(time.minute()) + ":" + String(time.second());
    Serial.println(timeStr+"is set");
    rtc.adjust(time);
    return true;

}

DS1307_status DS1307::getStatus() {
    return Status;
}
