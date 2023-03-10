//
// Created by 神奇bug在哪里 on 2023/3/10.
//
#include "logSystem.h"
#include <Arduino.h>
#include <cstdarg>
#include "settings.h"
void log(module module, logLevel level, const char *format, ...) {
    if (level < DEBUG_LEVEL) {
        return;
    }
    Serial.printf("[%s][%s]", module == MODULE_MAIN ? "MAIN" : module == MODULE_SERIAL_IO ? "SERIAL_IO" : module == MODULE_STATUS ? "STATUS" : module == MODULE_DISPLAYCORE ? "DISPLAYCORE" : module == MODULE_TEMPERATURE ? "TEMPERATURE" : module == MODULE_PWM ? "PWM" : module == MODULE_ALARM ? "ALARM" : module == MODULE_TIMESET ? "TIMESET" : module == MODULE_LOGSYSTEM ? "LOGSYSTEM" : "UNKNOWN", level == LOG_LEVEL_DEBUG ? "DEBUG" : level == LOG_LEVEL_INFO ? "INFO" : level == LOG_LEVEL_WARNING ? "WARNING" : level == LOG_LEVEL_ERROR ? "ERROR" : level == LOG_LEVEL_FATAL ? "FATAL" : "UNKNOWN");
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
    Serial.println();
}

void log(module module, logLevel level, std::string context) {
    if (level < DEBUG_LEVEL) {
        return;
    }
    Serial.printf("[%s][%s]", module == MODULE_MAIN ? "MAIN" : module == MODULE_SERIAL_IO ? "SERIAL_IO" : module == MODULE_STATUS ? "STATUS" : module == MODULE_DISPLAYCORE ? "DISPLAYCORE" : module == MODULE_TEMPERATURE ? "TEMPERATURE" : module == MODULE_PWM ? "PWM" : module == MODULE_ALARM ? "ALARM" : module == MODULE_TIMESET ? "TIMESET" : module == MODULE_LOGSYSTEM ? "LOGSYSTEM" : "UNKNOWN", level == LOG_LEVEL_DEBUG ? "DEBUG" : level == LOG_LEVEL_INFO ? "INFO" : level == LOG_LEVEL_WARNING ? "WARNING" : level == LOG_LEVEL_ERROR ? "ERROR" : level == LOG_LEVEL_FATAL ? "FATAL" : "UNKNOWN");
    Serial.println(context.c_str());
}

