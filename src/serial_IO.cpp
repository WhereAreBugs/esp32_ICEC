//
// Created by 神奇bug在哪里 on 2023/3/1.
//
#include "Arduino.h"
#include "serial_IO.h"

void serial_IO::setup() {
    /*  创建一个大小为128个字节的缓冲区  */
    buffer = new char[128];
    Serial.begin(115200);

}

void serial_IO::loop() {
    while (Serial.available())
    {
        char * c = new char;
        Serial.readBytes(c, 1);
        if (*c == '\r'||*c == '\n')
        {
            continue;
        }
        else if (bufferIndex>=127)
        {
            memset(buffer, 0, 128);
            bufferIndex = 0;
            Serial.println("Command too long!");
        }
        else if (*c == '#')
        {
            buffer[bufferIndex] = '\0';
            readCommand();
            bufferIndex = 0;
        }
        else
        {
            buffer[bufferIndex] = *c;
            bufferIndex++;
        }
    }
}

void serial_IO::readCommand() {
    Serial.println(buffer);
}
