//
// Created by 神奇bug在哪里 on 2023/3/1.
//

#include "displayCore.h"
#include "Fontdata.h"
#include <U8g2wqy.h>
U8G2_SSD1309_128X64_NONAME0_2_SW_I2C u8g2(U8G2_R0, SCL, SDA);
void displayCore::setup() {
    display = &u8g2;
    display->begin();
    display->enableUTF8Print();
    display->clearDisplay();
    display->setCursor(0,8 );
    display->setFont(u8g2_font_unifont_t_chinese3);
    display->print("一二三Booting");
    display->sendBuffer();
}

void displayCore::loop() {

}

void displayCore::SetPage(int page) {

}
