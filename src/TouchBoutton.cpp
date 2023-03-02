//
// Created by 神奇bug在哪里 on 2023/3/1.
//

#include "TouchBoutton.h"

void TouchBoutton::setup() {
    button1->attachClick(button_handle1);
    button1->attachDuringLongPress(button_handle1_long_press);

}
