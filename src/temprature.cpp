#include "temperature.h"
#include "settings.h"

#ifndef ESP32
#pragma message(THIS EXAMPLE IS FOR ESP32 ONLY!)
#error Select ESP32 board.
#endif


void temperature::setup() {
    /* 覆写DHT的pin */
    dht.setup(DHTPIN, DHTesp::DHT11);
    Serial.println("DHT: init done");
}


bool temperature::loop() {
   //耗时 250 milliseconds
   //警告: 数据高延迟！
   newValues = dht.getTempAndHumidity();
    // 检查数据是否出现错误
    if (dht.getStatus() != 0) {
        Serial.println("DHT11 error status: " + String(dht.getStatusString()));
        return false;
    }
    return true;
}

//以下为类的访问接口(Interface)
float temperature::getTemp() const {
    return newValues.temperature;
}

float temperature::getHum() const {
    return newValues.humidity;
}

ComfortState temperature::getComfortState() {
    return cf;
}


float temperature::gethua() const{
    float a1;
    a1=getTemp();
    a1=a1*1.8+32;
}