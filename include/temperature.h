//
// Created by 神奇bug在哪里 on 2023/3/1.
//

#ifndef ESP32_ICEC_TEMPERATURE_H
#define ESP32_ICEC_TEMPERATURE_H
#include "DHTesp.h"
class temperature{

public:
    void setup();
    bool loop();
    float getTemp() const;
    float getHum() const;
    ComfortState getComfortState();


private:
    const int dhtPin = 17;
    DHTesp dht{};
    TempAndHumidity newValues{};
/** Comfort profile */
    ComfortState cf{};

};
#endif //ESP32_ICEC_TEMPERATURE_H
