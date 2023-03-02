//
// Created by 神奇bug在哪里 on 2023/3/1.
//

#include "TouchButton.h"
extern SYSManeger sysManeger;
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

DateTime TouchButton::getTimeSet() {
    return timeSet;
}

void button_handle1() {
    /*
     * Fn: "切换功能按钮"、"完全关闭闹钟按钮"
     * Fixed: True[该按键的功能将会固定]
     * WARNING: 理论上任何情况下该按钮都会生效
     */
    if (sysManeger.get_Status().summary&0x01) {
        //闹钟开启状态
        sysManeger.set_Status(0x00);
    } else {
        uint8_t result = sysManeger.get_Status().summary;
        if((result&0x0e)<0x0a){
            result = result + 0x02;
        } else
            result = result & 0xf1;
        //更换页面。若页面超出范围则返回主界面
        sysManeger.set_Status(result);
    }
}

void button_handle2() {
    /*
     * Fn: "+1s步进"
     * Fixed: False[该按键的功能将会随着页面的变化而变化]
     * WARNING: 该按键在某些页面下不会生效
     */
    uint8_t result = sysManeger.get_Status().summary;
    if ((result&0x0e)==0x04||(result&0x0e)==0x0a) {
        //处在调整时间的界面
        if (result&0xe0==){

        }

    }



}

