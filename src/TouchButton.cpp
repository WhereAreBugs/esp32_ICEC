//
// Created by 神奇bug在哪里 on 2023/3/1.
//

#include "TouchButton.h"
#include "alarm.h"

const short daysOfMounth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
TimeSet timeSet;
extern SYSManeger sysManeger;
extern DS1307 ds;
extern double alarmTemp;
extern AlarmManagement alarmMana;
void TouchButton::setup() {
    button1->attachClick(button_handle1);
    button1->attachLongPressStop(button_handle1_long_press);
    button1->attachDoubleClick(button_handle1_double_click);
    button2->attachClick(button_handle2);
    button2->attachDuringLongPress(button_handle2_long_press);
    button3->attachClick(button_handle3);
    button3->attachDuringLongPress(button_handle3_long_press);
    button3->attachDoubleClick(button_handle3_double_click);
    button4->attachClick(button_handle4);
    button4->attachDuringLongPress(button_handle4_long_press);
    button4->attachDoubleClick(button_handle4_double_click);
    Serial.println("TouchButton setup complete");
}

bool TouchButton::getAlarmEn() {
    return sysManeger.get_Status().alarmEN;
}

TimeSet TouchButton::getTimeSet() {
    return timeSet;
}

void button_handle1() {
    /*
     * Fn: "切换功能按钮"、"完全关闭闹钟按钮"
     * Fixed: True[该按键的功能将会固定]
     * WARNING: 理论上任何情况下该按钮都会生效
     */
    auto status = sysManeger.get_Status();
    if (status.summary & 0x01) {
        //闹钟开启状态
        sysManeger.set_Status(0x00);
    } else {
        uint8_t result =status.summary;
        if ((result & 0x0e) < 0x0c) {
            result = result + 0x02;
        } else
            result = result & 0xf1;
        //更换页面。若页面超出范围则返回主界面
        sysManeger.set_Status(result);
    }
    if (status.currentPage == 2)
    {
       auto alarm =  alarmMana.getAlarmSet();
       timeSet = {alarm.year(),alarm.month(),alarm.day(),alarm.hour(),alarm.minute(),alarm.second()};
    }

}

void button_handle2() {
    /*
     * Fn: "+1s步进" "温度减"
     * Fixed: False[该按键的功能将会随着页面的变化而变化]
     * WARNING: 该按键在某些页面下不会生效
     */
    SYSStatus status = sysManeger.get_Status();
    uint8_t result = status.summary;
    if ((result & 0x0e) == 0x04 || (result & 0x0e) == 0x0a) {
        //处在调整时间的界面
        if ((result & 0xe0) == 0x00) {
            //当前未处于时间设置状态
            return;
        } else if ((result & 0xe0) == 0x20) {
            //设置年
            if (timeSet.year >= 2099) {
                timeSet.year = 2000;
                return;
            }
            timeSet.year++;
        } else if ((result & 0xe0) == 0x40) {
            //设置月
            if (timeSet.month >= 12) {
                timeSet.month = 1;
                return;
            }
            timeSet.month++;
        } else if ((result & 0xe0) == 0x60) {
            //设置日
            if (timeSet.day >= daysOfMounth[timeSet.month - 1] && timeSet.month != 2) {
                timeSet.day = 1;
                return;
            } else if (timeSet.month == 2 && is_doubleYear(timeSet.year)) {
                if (timeSet.day >= 29) {
                    timeSet.day = 1;
                    return;
                }
            } else if (timeSet.month == 2 && !is_doubleYear(timeSet.year)) {
                if (timeSet.day >= 28) {
                    timeSet.day = 1;
                    return;
                }
            }
            timeSet.day++;
        } else if ((result & 0xe0) == 0x80) {
            //设置时
            if (timeSet.hour >= 23) {
                timeSet.hour = 0;
                return;
            }
            timeSet.hour++;
        } else if ((result & 0xe0) == 0xa0) {
            //设置分
            if (timeSet.minute >= 59) {
                timeSet.minute = 0;
                return;
            }
            timeSet.minute++;
        } else if ((result & 0xe0) == 0xc0) {
            //设置秒
            if (timeSet.second >= 59) {
                timeSet.second = 0;
                return;
            }
            timeSet.second++;
        }
    }

}

void button_handle1_long_press()
/*
 * Fn: "长按保存时间"
 * Fixed: False[该按键的功能将会随着页面的变化而变化]
 * WARNING: 该按键在某些页面下不会生效
 */
{
    uint8_t result = sysManeger.get_Status().summary;
    if ((result & 0x0e) == 0x0a)
        //处在调整时间的界面
    {
        ds.setTime(DateTime(timeSet.year, timeSet.month, timeSet.day,
                            timeSet.hour, timeSet.minute, timeSet.second));
        result = result & 0x11;
        sysManeger.set_Status(result);
    } else if ((result & 0x0e) == 0x04)
        //处在调整闹钟的界面
    {
        alarmMana.setAlarm(DateTime(timeSet.year, timeSet.month, timeSet.day,
                                    timeSet.hour, timeSet.minute, timeSet.second));
    }
}

void button_handle2_long_press()
/*
 * Fn: "一直+1s步进"
 * Fixed: False[该按键的功能将会随着页面的变化而变化]
 * WARNING: 该按键在某些页面下不会生效
 */
{
    uint8_t result = sysManeger.get_Status().summary;
    if ((result & 0x0e) == 0x04 || (result & 0x0e) == 0x0a) {
        //处在调整时间的界面
        if ((result & 0xe0) == 0x00) {
            //当前未处于时间设置状态
            return;
        } else if ((result & 0xe0) == 0x20) {
            //设置年
            if (timeSet.year >= 2099) {
                timeSet.year = 2000;
                return;
            }
            timeSet.year++;
        } else if ((result & 0xe0) == 0x40) {
            //设置月
            if (timeSet.month >= 12) {
                timeSet.month = 1;
                return;
            }
            timeSet.month++;
        } else if ((result & 0xe0) == 0x60) {
            //设置日
            if (timeSet.day >= daysOfMounth[timeSet.month - 1] && timeSet.month != 2) {
                timeSet.day = 1;
                return;
            } else if (timeSet.month == 2 && is_doubleYear(timeSet.year)) {
                if (timeSet.day >= 29) {
                    timeSet.day = 1;
                    return;
                }
            } else if (timeSet.month == 2 && !is_doubleYear(timeSet.year)) {
                if (timeSet.day >= 28) {
                    timeSet.day = 1;
                    return;
                }
            }
            timeSet.day++;
        } else if ((result & 0xe0) == 0x80) {
            //设置时
            if (timeSet.hour >= 23) {
                timeSet.hour = 0;
                return;
            }
            timeSet.hour++;
        } else if ((result & 0xe0) == 0xa0) {
            //设置分
            if (timeSet.minute >= 59) {
                timeSet.minute = 0;
                return;
            }
            timeSet.minute++;
        } else if ((result & 0xe0) == 0xc0) {
            //设置秒
            if (timeSet.second >= 59) {
                timeSet.second = 0;
                return;
            }
            timeSet.second++;
        }
    }
    delay(100);
}

void button_handle3() {
    /*
     * Fn: "+2s步进"
     * Fixed: False[该按键的功能将会随着页面的变化而变化]
     * WARNING: 该按键在某些页面下不会生效
     */
    uint8_t result = sysManeger.get_Status().summary;
    if ((result & 0x0e) == 0x04 || (result & 0x0e) == 0x0a) {
        //处在调整时间的界面
        if ((result & 0xe0) == 0x00) {
            //当前未处于时间设置状态
            return;
        } else if ((result & 0xe0) == 0x20) {
            //设置年
            if (timeSet.year >= 2098) {
                timeSet.year = 2000;
                return;
            }
            timeSet.year += 2;
        } else if ((result & 0xe0) == 0x40) {
            //设置月
            if (timeSet.month >= 11) {
                timeSet.month = 1;
                return;
            }
            timeSet.month += 2;
        } else if ((result & 0xe0) == 0x60) {
            //设置日
            if (timeSet.day >= daysOfMounth[timeSet.month - 1] && timeSet.month != 2) {
                timeSet.day = 1;
                return;
            } else if (timeSet.month == 2 && is_doubleYear(timeSet.year)) {
                if (timeSet.day >= 28) {
                    timeSet.day = 1;
                    return;
                }
            } else if (timeSet.month == 2 && !is_doubleYear(timeSet.year)) {
                if (timeSet.day >= 27) {
                    timeSet.day = 1;
                    return;
                }
            }
            timeSet.day += 2;
        } else if ((result & 0xe0) == 0x80) {
            //设置时
            if (timeSet.hour >= 22) {
                timeSet.hour = 0;
                return;
            }
            timeSet.hour += 2;
        } else if ((result & 0xe0) == 0xa0) {
            //设置分
            if (timeSet.minute >= 58) {
                timeSet.minute = 0;
                return;
            }
            timeSet.minute += 2;
        } else if ((result & 0xe0) == 0xc0) {
            //设置秒
            if (timeSet.second >= 58) {
                timeSet.second = 0;
                return;
            }
            timeSet.second += 2;
        }
    }
    if ((result & 0x0e) == 0x0c) {
        //处在调整温度的界面
        if (alarmTemp < 50) {
            alarmTemp++;
        } else
            alarmTemp = 0;

    }
}

void button_handle3_long_press()
/*
  * Fn: "一直+2s步进"
  * Fixed: False[该按键的功能将会随着页面的变化而变化]
  * WARNING: 该按键在某些页面下不会生效
  */
{
    uint8_t result = sysManeger.get_Status().summary;
    if ((result & 0x0e) == 0x04 || (result & 0x0e) == 0x0a) {
        //处在调整时间的界面
        if ((result & 0xe0) == 0x00) {
            //当前未处于时间设置状态
            return;
        } else if ((result & 0xe0) == 0x20) {
            //设置年
            if (timeSet.year >= 2098) {
                timeSet.year = 2000;
                return;
            }
            timeSet.year += 2;
        } else if ((result & 0xe0) == 0x40) {
            //设置月
            if (timeSet.month >= 11) {
                timeSet.month = 1;
                return;
            }
            timeSet.month += 2;
        } else if ((result & 0xe0) == 0x60) {
            //设置日
            if (timeSet.day >= daysOfMounth[timeSet.month - 1] && timeSet.month != 2) {
                timeSet.day = 1;
                return;
            } else if (timeSet.month == 2 && is_doubleYear(timeSet.year)) {
                if (timeSet.day >= 28) {
                    timeSet.day = 1;
                    return;
                }
            } else if (timeSet.month == 2 && !is_doubleYear(timeSet.year)) {
                if (timeSet.day >= 27) {
                    timeSet.day = 1;
                    return;
                }
            }
            timeSet.day += 2;
        } else if ((result & 0xe0) == 0x80) {
            //设置时
            if (timeSet.hour >= 22) {
                timeSet.hour = 0;
                return;
            }
            timeSet.hour += 2;
        } else if ((result & 0xe0) == 0xa0) {
            //设置分
            if (timeSet.minute >= 58) {
                timeSet.minute = 0;
                return;
            }
            timeSet.minute += 2;
        } else if ((result & 0xe0) == 0xc0) {
            //设置秒
            if (timeSet.second >= 58) {
                timeSet.second = 0;
                return;
            }
            timeSet.second += 2;
        }
    }
    delay(100);
}

void button_handle4() {
    /*
     * Fn: "+5s步进"
     * Fixed: False[该按键的功能将会随着页面的变化而变化]
     * WARNING: 该按键在某些页面下不会生效
     */
    uint8_t result = sysManeger.get_Status().summary;
    if ((result & 0x0e) == 0x04 || (result & 0x0e) == 0x0a) {
        //处在调整时间的界面
        if ((result & 0xe0) == 0x00) {
            //当前未处于时间设置状态
            return;
        } else if ((result & 0xe0) == 0x20) {
            //设置年
            if (timeSet.year >= 2095) {
                timeSet.year = 2000;
                return;
            }
            timeSet.year += 5;
        } else if ((result & 0xe0) == 0x40) {
            //设置月
            if (timeSet.month >= 8) {
                timeSet.month = 1;
                return;
            }
            timeSet.month += 5;
        } else if ((result & 0xe0) == 0x60) {
            //设置日
            if (timeSet.day >= daysOfMounth[timeSet.month - 1] - 5 && timeSet.month != 2) {
                timeSet.day = 1;
                return;
            } else if (timeSet.month == 2 && is_doubleYear(timeSet.year)) {
                if (timeSet.day >= 24) {
                    timeSet.day = 1;
                    return;
                }
            } else if (timeSet.month == 2 && !is_doubleYear(timeSet.year)) {
                if (timeSet.day >= 23) {
                    timeSet.day = 1;
                    return;
                }
            }
            timeSet.day += 5;
        } else if ((result & 0xe0) == 0x80) {
            //设置时
            if (timeSet.hour >= 19) {
                timeSet.hour = 0;
                return;
            }
            timeSet.hour += 5;
        } else if ((result & 0xe0) == 0xa0) {
            //设置分
            if (timeSet.minute >= 55) {
                timeSet.minute = 0;
                return;
            }
            timeSet.minute += 5;
        } else if ((result & 0xe0) == 0xc0) {
            //设置秒
            if (timeSet.second >= 55) {
                timeSet.second = 0;
                return;
            }
            timeSet.second += 5;
        }
    }


}

void button_handle4_long_press()
/*
  * Fn: "一直+5s步进"
  * Fixed: False[该按键的功能将会随着页面的变化而变化]
  * WARNING: 该按键在某些页面下不会生效
  */
{
    uint8_t result = sysManeger.get_Status().summary;
    if ((result & 0x0e) == 0x04 || (result & 0x0e) == 0x0a) {
        //处在调整时间的界面
        if ((result & 0xe0) == 0x00) {
            //当前未处于时间设置状态
            return;
        } else if ((result & 0xe0) == 0x20) {
            //设置年
            if (timeSet.year >= 2095) {
                timeSet.year = 2000;
                return;
            }
            timeSet.year += 5;
        } else if ((result & 0xe0) == 0x40) {
            //设置月
            if (timeSet.month >= 8) {
                timeSet.month = 1;
                return;
            }
            timeSet.month += 5;
        } else if ((result & 0xe0) == 0x60) {
            //设置日
            if (timeSet.day >= daysOfMounth[timeSet.month - 1] - 5 && timeSet.month != 2) {
                timeSet.day = 1;
                return;
            } else if (timeSet.month == 2 && is_doubleYear(timeSet.year)) {
                if (timeSet.day >= 25) {
                    timeSet.day = 1;
                    return;
                }
            } else if (timeSet.month == 2 && !is_doubleYear(timeSet.year)) {
                if (timeSet.day >= 24) {
                    timeSet.day = 1;
                    return;
                }
            }
            timeSet.day += 5;
        } else if ((result & 0xe0) == 0x80) {
            //设置时
            if (timeSet.hour >= 18) {
                timeSet.hour = 0;
                return;
            }
            timeSet.hour += 5;
        } else if ((result & 0xe0) == 0xa0) {
            //设置分
            if (timeSet.minute >= 55) {
                timeSet.minute = 0;
                return;
            }
            timeSet.minute += 5;
        } else if ((result & 0xe0) == 0xc0) {
            //设置秒
            if (timeSet.second >= 55) {
                timeSet.second = 0;
                return;
            }
            timeSet.second += 5;
        }
    }
    delay(100);
}

void button_handle1_double_click()
/*
  * Fn: "开关闹钟功能"
  * Fixed: False[该按键的功能将会随着页面的变化而变化]
  * WARNING: 该按键在某些页面下不会生效
  */

{
    uint8_t result = sysManeger.get_Status().summary;
    if ((result & 0x0e) == 0x04)
        //处在闹钟设置的界面
    {
        result &= 0xfe;
        sysManeger.set_Status(result);
        return;
    }

}

void button_handle3_double_click() {
    /*
     * Fn: "切换正在调整的时间(左)"
     * Fixed: False[该按键的功能将会随着页面的变化而变化]
     * WARNING: 该按键在某些页面下不会生效
     */
    uint8_t result = sysManeger.get_Status().summary;
    if (((result & 0x0e) == 0x04) || ((result & 0x0e) == 0x0a)) {
        //处在调整时间的界面
        if ((result & 0xe0) <= 0x20) {
            //当前处于年份设置状态
            sysManeger.timeSetNow(6);
            return;
        } else {
            sysManeger.timeSetNow(((result & 0xe0) >> 5) - 1);
            return;
        }
    }
}

void button_handle4_double_click() {
    /*
     * Fn: "切换正在调整的时间(右)"
     * Fixed: False[该按键的功能将会随着页面的变化而变化]
     * WARNING: 该按键在某些页面下不会生效
     */
    uint8_t result = sysManeger.get_Status().summary;
    if (((result & 0x0e) == 0x04) || ((result & 0x0e) == 0x0a)) {
        //处在调整时间的界面
        if ((result & 0xe0) >= 0xc0) {
            //当前处于秒设置状态
            sysManeger.timeSetNow(1);
            return;
        } else {
            sysManeger.timeSetNow(((result & 0xe0) >> 5) + 1);
            return;
        }
    }
}

bool is_doubleYear(int a) {
    if (a / 4 == 0 && a / 100 != 0) {
        return true;
    } else {
        if (a / 400 == 0) {
            return true;
        } else {
            return false;
        }
    }
}
