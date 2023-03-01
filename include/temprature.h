//
// Created by 神奇bug在哪里 on 2023/3/1.
//

#ifndef ESP32_ICEC_TEMPRATURE_H
#define ESP32_ICEC_TEMPRATURE_H
#include "DHTesp.h"
class temprature{

public:
    void setup(int pin);
    bool update();
    float getTemp() const;
    float getHum() const;
    ComfortState getComfortState();

private:
    const int dhtPin = 17;
    DHTesp dht{};
    TempAndHumidity newValues{};
/** Comfort profile */
    ComfortState cf;

};
#endif //ESP32_ICEC_TEMPRATURE_H
