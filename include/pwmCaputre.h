//
// Created by 神奇bug在哪里 on 2023/3/2.
//

#ifndef ESP32_ICEC_PWMCAPUTRE_H
#define ESP32_ICEC_PWMCAPUTRE_H

#include <Arduino.h>
#include "driver/mcpwm.h"
#include "soc/mcpwm_reg.h"

class pwmCaputre {
private:
    bool running = false;
public:
    void setup();

    void start();
    bool is_running() const;

    void stop();
    struct PWM_INFO {
        uint32_t freq;
        double duty;//占空比
        uint64_t t0_h;//high_time
        uint64_t T;//cycle_time
    }pwmInfo{};
};


#endif //ESP32_ICEC_PWMCAPUTRE_H
