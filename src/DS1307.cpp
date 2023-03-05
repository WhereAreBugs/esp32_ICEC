//
// Created by 神奇bug在哪里 on 2023/2/28.
//
#include <Wire.h>
#include <Arduino.h>
#include "DS1307_time.h"
#include "settings.h"

void DS1307::setup() {
    if (! rtc.begin()) {
        Serial.println("Couldn't find RTC");
        Serial.flush();
    }
    if (! rtc.isrunning()) {
        Serial.println("RTC is NOT running, let's set the time!");
        Status = DS1307_ERROR_RESET;
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
       Serial.println("RTC lost confidence in the DateTime!");
   }
}

byte DS1307::bcdToDec(int read) {
    return ((read / 16 * 10) + (read % 16));
}

DateTime DS1307::getTime() {
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
