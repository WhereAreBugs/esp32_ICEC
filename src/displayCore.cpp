//
// Created by 神奇bug在哪里 on 2023/3/1.
//

#include <Arduino.h>
#include <Wire.h>
#include "serial_IO.h"
#include "displayCore.h"
#include "temperature.h"
#include "settings.h"
#include "Status.h"
#include "DS1307_time.h"
#include "TouchButton.h"
#include "Fontdata.h"
#include "pwmCaputre.h"
byte page1=-1;
extern TouchButton touches;
extern pwmCaputre pwm;
extern SYSStatus get_Status();
double getDistance();
extern SYSManeger sysManeger;
U8G2_SSD1309_128X64_NONAME0_F_SW_I2C u8g2(U8G2_R0, SCL, SDA);


void displayCore::setup() {
    display = &u8g2;
    display->begin();
    display->enableUTF8Print();
    display->clearDisplay();
    display->setCursor(0,30);
    display->setFont(u8g2_font_unifont_t_chinese3);
    display->print("一二三Booting");
    display->sendBuffer();

}

void displayCore::loop() {
    if (display == nullptr)
        return;
    TimeSet text = TouchButton::getTimeSet();
    switch(sysManeger.get_Status().currentPage)
    {
        case 0:
        {
            if(sysManeger.get_Status().currentPage-page1)
            {
                page1=sysManeger.get_Status().currentPage;
                display->clearDisplay();
            }
            display->setCursor(0,16);
            display->print(String(text.year)+"年"+String(text.month)+"月"+String(text.day)+"日");
            display->setCursor(0,32);
            display->print(String(text.hour)+"时"+String(text.minute)+"分"+String(text.second)+"秒");
            display->setCursor(0,48);
            display->print("温度:");
            display->print(String(temp->getTemp())+"˚C"+String(temp->gethua())+"˚F");
            display->setCursor(0,64);
            display->print("湿度:");
            display->print(String(temp->getHum()));
            display->sendBuffer();
        }

        case 1:
        {
            if(sysManeger.get_Status().currentPage-page1!=0)
            {
                page1=sysManeger.get_Status().currentPage;
                display->clearDisplay();
                display->setCursor(0,16);
                display->print("pwm:");
            }

            display->setCursor(0,32);
            display->print("频率:" + String(pwm.pwmInfo.freq) + "周期:" + String(pwm.pwmInfo.T));
            display->setCursor(0,48);
            display->print("高电平:" + String(pwm.pwmInfo.t0_h) + "占空比:" + String(pwm.pwmInfo.duty));
            display->drawHLine(0,49, 64 * pwm.pwmInfo.duty);
            display->drawVLine(0, 64 * pwm.pwmInfo.duty, 15);
            display->drawHLine(0,64,64*(1 - pwm.pwmInfo.duty));
            display->sendBuffer();
            break;
        }
        case 2:
        {
            if(sysManeger.get_Status().currentPage-page1!=0)
            {
                page1=sysManeger.get_Status().currentPage;
                display->clearDisplay();
                display->setCursor(0,16);
                display->print("clockchange:");
                display->setCursor(0,32);
                display->print("");
            }
            display->setCursor((sysManeger.get_Status().timeSetNow-4)*16,32);
            display->print("  ");
            delay(500);
            display->sendBuffer();
            switch(sysManeger.get_Status().timeSetNow)
            {
                case 4:display->print(""); break;
                case 5:display->print(""); break;
                case 6:display->print(""); break;
                default: Serial.println("Display loop: switch error!");
            }
            delay(500);
            display->sendBuffer();
        }
        case 3:
        {
            if(sysManeger.get_Status().currentPage-page1!=0)
            {
                page1=sysManeger.get_Status().currentPage;
                display->clearDisplay();
            }

            display->setCursor(0,16);
            display->print("超声波:");
            display->print(String(getDistance()));
            display->sendBuffer();
            break;
        }
        case 4:
        {
            if(sysManeger.get_Status().currentPage-page1!=0)
            {
                page1=sysManeger.get_Status().currentPage;
                display->clearDisplay();
            }
            display->setCursor(0,16);
            display->print("memeber:");
            display->print("徐 简 魏");
            display->sendBuffer();
            break;
        }
        case 5:
        {
            if(sysManeger.get_Status().currentPage-page1!=0)
            {
                page1=sysManeger.get_Status().currentPage;
                display->clearDisplay();
                display->setCursor(0,16);
                display->print("timechange:");
                display->setCursor(0,32);
                display->print(String(text.year)+"年"+String(text.month)+"月"+String(text.day)+"日");
                display->setCursor(0,48);
                display->print(String(text.hour)+":"+String(text.minute)+":"+String(text.second)+":");
            }
            if(sysManeger.get_Status().timeSetNow<=3)
                display->setCursor((sysManeger.get_Status().timeSetNow-1)*16,32);
            else
                display->setCursor((sysManeger.get_Status().timeSetNow-4)*16,48);
            if(sysManeger.get_Status().timeSetNow==1) display->print("    ");
            else display->print("  ");
            delay(500);
            display->sendBuffer();
            switch(sysManeger.get_Status().timeSetNow)
            {
                case 1:display->print(String(text.year)); break;
                case 2:display->print(String(text.month)); break;
                case 3:display->print(String(text.day)); break;
                case 4:display->print(String(text.hour)); break;
                case 5:display->print(String(text.minute)); break;
                case 6:display->print(String(text.second)); break;
            }
            delay(500);
            display->sendBuffer();
        }

    }


}
