#include <Arduino.h>
#include <Wire.h>
#include "serial_IO.h"
#include "displayCore.h"
#include "temperature.h"
#include "settings.h"
#include "Status.h"
#include "DS1307_time.h"
#include "TouchButton.h"
#include "pwmCaputre.h"
#include "alarm.h"
#include "logSystem.h"
volatile bool SYSisOff = true;

//实例化对象
serial_IO serialIo;
temperature temperature;
displayCore displayCore;
SYSManeger sysManeger;
TouchButton touches;
DS1307 ds;
pwmCaputre pwm;
AlarmManagement alarmMana;

void setup() {
    Wire.begin(SDA_PIN,SCL_PIN);
    serialIo.setup();
    /*   SYS指示灯引脚初始化   */
    log(MODULE_MAIN,LOG_LEVEL_DEBUG,"ESP32 setup() started");
    pinMode(2,OUTPUT);
    log(MODULE_MAIN,LOG_LEVEL_DEBUG,"SYS LED pin setted");
    displayCore.setup();
    log(MODULE_MAIN,LOG_LEVEL_DEBUG,"displayCore setup() called");
    temperature.setup();
    log(MODULE_MAIN,LOG_LEVEL_DEBUG,"temperature setup() called");
    touches.setup();
    log(MODULE_MAIN,LOG_LEVEL_DEBUG,"touches setup() called");
    ds.setup();
    log(MODULE_MAIN,LOG_LEVEL_DEBUG,"ds setup() called");
    pwm.setup();
    log(MODULE_MAIN,LOG_LEVEL_DEBUG,"pwm setup() called");
    alarmMana.setup();
    log(MODULE_MAIN,LOG_LEVEL_DEBUG,"alarmMana setup() called");
    log(MODULE_MAIN,LOG_LEVEL_INFO,"ESP32 setup() finished");

}

void loop() {
    /*   SYS循环指示灯开始   */
    if (SYSisOff)
        digitalWrite(2,HIGH);
    else
        digitalWrite(2,LOW);
    SYSisOff = !SYSisOff;
    /*   SYS循环指示灯结束   */
    /*   loop函数开始   */
    serialIo.loop();
//    displayCore.loop();
    sysManeger.loop();
    /*   loop函数结束   */
    /*   读取时间   */
    ds.readTime();
    alarmMana.loop();
}