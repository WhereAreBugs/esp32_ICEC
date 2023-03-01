//
// Created by 神奇bug在哪里 on 2023/2/28.
//
#include <Wire.h>
#include <Arduino.h>
#include "DS1307_time.h"
#define DS1307_ADDRESS 0x68

void DS1307::RTCsetup() {
    Wire.begin();
    Wire.beginTransmission(DS1307_ADDRESS);
    Wire.write(0x00);
    Wire.write(0x00);
    Wire.endTransmission();
}
void DS1307::readTime(){
    //Read the current time
    Wire.beginTransmission(DS1307_ADDRESS);
    Wire.write(0x00);
    Wire.endTransmission();
    Wire.requestFrom(DS1307_ADDRESS, 7);
    byte second = bcdToDec(Wire.read() & 0x7f);
    byte minute = bcdToDec(Wire.read());
    byte hour = bcdToDec(Wire.read() & 0x3f);
    byte dayOfWeek = bcdToDec(Wire.read());
    byte dayOfMonth = bcdToDec(Wire.read());
    byte month = bcdToDec(Wire.read());
    byte year = bcdToDec(Wire.read());
    currentTime = {second,minute,hour,dayOfWeek,dayOfMonth,month,year};
}

byte DS1307::bcdToDec(int read) {
    return ((read / 16 * 10) + (read % 16));
}

DS1307_time DS1307::getTime() {
    return currentTime;
}

bool DS1307::setTime(DS1307_time time) {
    Wire.beginTransmission(DS1307_ADDRESS);

}
