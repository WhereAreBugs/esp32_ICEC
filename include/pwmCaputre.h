//
// Created by 神奇bug在哪里 on 2023/3/2.
//

#ifndef ESP32_ICEC_PWMCAPUTRE_H
#define ESP32_ICEC_PWMCAPUTRE_H

#include <Arduino.h>
#include <pwm_analyzer.h>


class pwmCaputre {
private:
    PWM_Analyzer *pwm = nullptr;
    struct PWM_INFO {
        uint32_t freq;
        double duty;
    };
    bool running = false;
public:
    void setup();

    void start();

    bool is_running();
    struct PWM_INFO get_info();
    void stop();
};


#endif //ESP32_ICEC_PWMCAPUTRE_H
