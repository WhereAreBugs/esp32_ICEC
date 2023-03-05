//
// Created by 神奇bug在哪里 on 2023/3/1.
//
#include "Arduino.h"
#include "serial_IO.h"
#include "DS1307_time.h"
extern DS1307 ds;
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
        if (buffer== nullptr)
        {
            Serial.println("[严重错误] Buffer is null!");
            return;
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
    unsigned short year=9999,month=9999,day=9999,hour=9999,minute=9999,second=9999;
    sscanf(buffer,"ICEC%hu年%hu月%hu日%hu时%hu分%hu秒",&year,&month,&day,&hour,&minute,&second);
    if (year>2000&&year<2100&&month>0&&month<13&&day>0&&day<32&&hour<24&&minute<60&&second<60)
    {
        DateTime time = DateTime(year,month,day,hour,minute,second);
        ds.setTime(time);
        Serial.println("Time set!");
    }
    else
    {
        Serial.println("Time format error!");
    }

}
