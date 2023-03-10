//
// Created by 神奇bug在哪里 on 2023/3/10.
//

#ifndef ESP32_ICEC_LOGSYSTEM_H
#define ESP32_ICEC_LOGSYSTEM_H

#include <string>
#include <Arduino.h>

enum logLevel{
    LOG_LEVEL_DEBUG,
    LOG_LEVEL_INFO,
    LOG_LEVEL_WARNING,
    LOG_LEVEL_ERROR,
    LOG_LEVEL_FATAL
};
enum module{
    MODULE_MAIN,
    MODULE_SERIAL_IO,
    MODULE_STATUS,
    MODULE_DISPLAYCORE,
    MODULE_TEMPERATURE,
    MODULE_PWM,
    MODULE_ALARM,
    MODULE_TIMESET,
    MODULE_LOGSYSTEM,
    MODULE_DS1307,
    MODULE_TOUCHBUTTON,
    MODULE_UNKNOWN
};
//void log(module module,logLevel level,const char * format,...);
void log(module module,logLevel level,std::string context);
void log(module module, logLevel level, StringSumHelper context);
void log(module module, logLevel level, const char * context);
#endif //ESP32_ICEC_LOGSYSTEM_H
