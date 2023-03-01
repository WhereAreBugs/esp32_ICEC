#include "temprature.h"
#ifndef ESP32
#pragma message(THIS EXAMPLE IS FOR ESP32 ONLY!)
#error Select ESP32 board.
#endif


void temprature::setup(int pin) {
    const int * p = &dhtPin;
    * const_cast<int * >(p) = pin;
    /* 覆写DHT的pin */
    dht.setup(dhtPin, DHTesp::DHT11);
    Serial.println("DHT: init done");
}


bool temprature::update() {
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
float temprature::getTemp() const {
    return newValues.temperature;
}

float temprature::getHum() const {
    return newValues.humidity;
}

ComfortState temprature::getComfortState() {
    return cf;
}


