#include <Arduino.h>
#include <Wire.h>
#include "serial_IO.h"
#include "displayCore.h"
#include "temperature.h"
#include "settings.h"
#include "Status.h"
#include "DS1307_time.h"
#include "TouchButton.h"

volatile bool SYSisOff = true;

//实例化对象
serial_IO serialIo;
temperature temperature;
displayCore displayCore;
SYSManeger sysManeger;
TouchButton touches;
DS1307 ds;

void setup() {
    Wire.begin(SDA_PIN,SCL_PIN);
    serialIo.setup();
    /*   SYS指示灯引脚初始化   */
    pinMode(2,OUTPUT);
    Serial.println("ESP32 setup() ended");
    displayCore.setup();
    displayCore.SetPage(mainMenu);
    temperature.setup();
    ds.setup();

}

void loop() {
    /*   SYS循环指示灯开始   */
    if (SYSisOff)
        digitalWrite(2,HIGH);
    else
        digitalWrite(2,LOW);
    SYSisOff = !SYSisOff;
    delay(200);
    serialIo.loop();
    displayCore.loop();
    /*   SYS循环指示灯结束   */
    sysManeger.loop();
    temperature.loop();
    ds.readTime();



}