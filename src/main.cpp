#include <Arduino.h>
#include <Wire.h>
#include <U8g2lib.h>
#include <U8x8lib.h>
#include <MUIU8g2.h>



U8G2_SSD1309_128X64_NONAME0_2_SW_I2C u8g2(U8G2_R0, SCL, SDA);
//实例化全局显示对象

void setup() {
// write your initialization code here
    Wire.begin(21,22);
    Serial.begin(115200);
    Serial.println("ESP32 setup() ended");

}

void loop() {
    volatile bool SYSisOff = true;
    /*SYS循环指示灯*/
    if (SYSisOff)
        digitalWrite(2,HIGH);
    else
        digitalWrite(2,LOW);
    delay(1000);

}