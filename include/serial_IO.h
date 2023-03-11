//
// Created by 神奇bug在哪里 on 2023/3/1.
//

#ifndef ESP32_ICEC_SERIAL_IO_H
#define ESP32_ICEC_SERIAL_IO_H
#include "esphome.h"

class serial_IO : public esphome::Component{
private:
    char * buffer = nullptr;
    byte bufferIndex = 0;
    void readCommand();
public:
    void setup() override;
    void loop();

};


#endif //ESP32_ICEC_SERIAL_IO_H
