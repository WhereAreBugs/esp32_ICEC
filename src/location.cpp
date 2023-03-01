//
// Created by 神奇bug在哪里 on 2023/2/28.
//
#include <Arduino.h>
#define trigPin  12 //定义Trig引脚
#define echoPin  13 //定义Echo引脚

void setup_location() {
  // 设置引脚模式
  pinMode(trigPin, OUTPUT); //设置Trig引脚为输出
  pinMode(echoPin, INPUT); //设置Echo引脚为输入
}

double getDistance(){
    digitalWrite(trigPin, LOW); //Trig引脚输出低电平
    delayMicroseconds(2); //延时2微秒
    digitalWrite(trigPin, HIGH); //Trig引脚输出高电平
    delayMicroseconds(10); //延时10微秒
    digitalWrite(trigPin, LOW); //Trig引脚输出低电平
    double duration; //定义持续时间
    double distance; //定义距离
    duration = pulseIn(echoPin, HIGH); //计算持续时间
    distance = duration * 0.034 / 2; //计算距离
    return distance;
}