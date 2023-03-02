//
// Created by 神奇bug在哪里 on 2023/3/1.
//

#ifndef ESP32_ICEC_SERIAL_IO_H
#define ESP32_ICEC_SERIAL_IO_H


class serial_IO {
private:
    char * buffer = nullptr;
    byte bufferIndex = 0;
    void readCommand();
public:
    void setup();
    void loop();

};


#endif //ESP32_ICEC_SERIAL_IO_H
