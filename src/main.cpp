#include <Arduino.h>
#include <Wire.h>
#include "serial_IO.h"
volatile bool SYSisOff = true;


//实例化全局显示对象
serial_IO serialIo;
void setup() {
// write your initialization code here
    Wire.begin(21,22);
    serialIo.setup();
    /*   SYS指示灯引脚初始化   */
    pinMode(2,OUTPUT);
    Serial.println("ESP32 setup() ended");

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

    /*   SYS循环指示灯结束   */


}