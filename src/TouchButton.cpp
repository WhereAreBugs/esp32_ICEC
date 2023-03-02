//
// Created by 神奇bug在哪里 on 2023/3/1.
//

#include "TouchButton.h"

void TouchButton::setup() {
    button1->attachClick(button_handle1);
    button1->attachDuringLongPress(button_handle1_long_press);
    button2->attachClick(button_handle2);
    button2->attachDuringLongPress(button_handle2_long_press);
    button3->attachClick(button_handle3);
    button3->attachDuringLongPress(button_handle3_long_press);
    button4->attachClick(button_handle4);
    button4->attachDuringLongPress(button_handle4_long_press);
    Serial.println("TouchButton setup complete");
}

void button_handle1() {
    /*
     * Fn: "切换功能按钮"、"完全关闭闹钟按钮"
     * Fixed: True[该按键的功能将会固定]
     * WARNING: 理论上任何情况下该按钮都会生效
     */
    if ()
}
