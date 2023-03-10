//
// Created by 神奇bug在哪里 on 2023/3/1.
//


#include <Wire.h>
#include "displayCore.h"
#include "TouchButton.h"
#include "pwmCaputre.h"
#include "logSystem.h"
int page1=-1;
extern TouchButton touches;
//extern pwmCaputre * this_;
extern pwmCaputre pwm;
extern temperature temperature;
extern double getDistance();
U8G2_SSD1309_128X64_NONAME0_F_SW_I2C u8g2(U8G2_R0, SCL, SDA);

extern AlarmManagement alarmMana;

void displayCore::setup() {
    display = &u8g2;
    display->begin();
    display->enableUTF8Print();
    display->clearDisplay();
    display->setCursor(0,30);
    display->setFont(u8g2_font_unifont_t_chinese3);
    display->print("System booting...");
    display->sendBuffer();
    temp = &temperature;
}


void displayCore::loop() {
    TimeSet text = TouchButton::getTimeSet();
    if (display== nullptr)
    {
        log(MODULE_DISPLAYCORE,LOG_LEVEL_ERROR,"display is nullptr!");
        return;
    }
    if (temp == nullptr)
    {
        log(MODULE_DISPLAYCORE,LOG_LEVEL_ERROR,"temp is nullptr!");
        return;
    }
    switch(sysManeger.get_Status().currentPage)
    {
        case 0:
        {
            log(MODULE_DISPLAYCORE,LOG_LEVEL_DEBUG,"page0");
            if(sysManeger.get_Status().currentPage-page1!=0)
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
            log(MODULE_DISPLAYCORE,LOG_LEVEL_DEBUG,"page1");
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
            display->drawHLine(0,49, static_cast<int>(64 * pwm.pwmInfo.duty));
            display->drawVLine(0, static_cast<int>(64 * pwm.pwmInfo.duty), 15);
            display->drawHLine(0,64,static_cast<int>(64*(1 - pwm.pwmInfo.duty)));
            display->sendBuffer();
            break;
        }
        case 2:
        {
            log(MODULE_DISPLAYCORE,LOG_LEVEL_DEBUG,"page2");
            if(sysManeger.get_Status().currentPage-page1!=0)
            {
                page1=sysManeger.get_Status().currentPage;
                display->clearDisplay();
                display->setCursor(0,16);
                display->print("clock change:");
                display->setCursor(0,32);
                display->print(String(alarmMana.getAlarmSet().getHour())+":"+String(alarmMana.getAlarmSet().getMinute())+":"+String(alarmMana.getAlarmSet().getSecond()));
            }
            display->setCursor(0,48);
            if(sysManeger.get_Status().alarmEN) display->print("ON ");
            else display->print("OFF");
            display->setCursor((sysManeger.get_Status().timeSetNow-4)*16,32);
            display->print("  ");
            delay(500);
            display->sendBuffer();
            switch(sysManeger.get_Status().timeSetNow)
            {
                case 4:display->print(String(alarmMana.getAlarmSet().getHour())); break;
                case 5:display->print(String(alarmMana.getAlarmSet().getMinute())); break;
                case 6:display->print(String(alarmMana.getAlarmSet().getSecond())); break;
                default:display->print("error");
            }
            delay(500);
            display->sendBuffer();
        }
        case 3:
        {
            log(MODULE_DISPLAYCORE,LOG_LEVEL_DEBUG,"page3");
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
            log(MODULE_DISPLAYCORE,LOG_LEVEL_DEBUG,"page4");
            if(sysManeger.get_Status().currentPage-page1!=0)
            {
                page1=sysManeger.get_Status().currentPage;
                display->clearDisplay();
            }
            display->setCursor(0,16);
            display->print("member:");
            display->print("徐 简 魏");
            display->sendBuffer();
            break;
        }
        case 5:
        {
            log(MODULE_DISPLAYCORE,LOG_LEVEL_DEBUG,"page5");
            if(sysManeger.get_Status().currentPage-page1!=0)
            {
                page1=sysManeger.get_Status().currentPage;
                display->clearDisplay();
                display->setCursor(0,16);
                display->print("time change:");
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
                default:display->print("error");
            }
            delay(500);
            display->sendBuffer();
        }
        case 6:
        {
            log(MODULE_DISPLAYCORE,LOG_LEVEL_DEBUG,"page6");
            if(sysManeger.get_Status().currentPage-page1!=0)
            {
                page1=sysManeger.get_Status().currentPage;
                display->clearDisplay();
                display->setCursor(0,16);
                display->print("temp:"+String(temp->getTemp())+"˚C");
            }
        }
        case 7:
        {
            log(MODULE_DISPLAYCORE,LOG_LEVEL_DEBUG,"page7");
            if(sysManeger.get_Status().currentPage-page1!=0)
            {
                page1=sysManeger.get_Status().currentPage;
                display->clearDisplay();
                display->setCursor(0,16);
                display->print(String(alarmMana.getAlarmSet().getHour())+":"+String(alarmMana.getAlarmSet().getMinute())+":"+String(alarmMana.getAlarmSet().getSecond()));
            }
        }

        default:
        {
            log(MODULE_DISPLAYCORE,LOG_LEVEL_DEBUG,"page error");
            display->setCursor(0,16);
            display->print("error");
        }

    }


}

