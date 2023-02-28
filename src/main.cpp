#include <Arduino.h>
#include <Wire.h>
#include <U8g2lib.h>
#include <U8x8lib.h>
#include <MUIU8g2.h>


#define dhtPin 18

U8G2_SSD1309_128X64_NONAME0_2_SW_I2C u8g2(U8G2_R0, SCL, SDA);
//实例化全局显示对象

extern TaskHandle_t tempTaskHandle;
/** Ticker for temperature reading */

bool tasksEnabled = false;
/** Pin number for DHT11 data pin */
void tempTask(void *pvParameters);
bool getTemperature();
void triggerGetTemp();
bool initTemp();

void setup() {
// write your initialization code here
    Serial.begin(115200);
    Serial.println();
    Serial.println("DHT ESP32 example with tasks");
    initTemp();
    // Signal end of setup() to tasks
    tasksEnabled = true;

}

void loop() {
// write your code here
    if (!tasksEnabled) {
        // Wait 2 seconds to let system settle down
        delay(2000);
        // Enable task that will read values from the DHT sensor
        tasksEnabled = true;
        if (tempTaskHandle != nullptr) {
            vTaskResume(tempTaskHandle);
        }
    }
    yield();
}