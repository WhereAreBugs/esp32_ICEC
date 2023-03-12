#pragma clang diagnostic push
#pragma ide diagnostic ignored "bugprone-reserved-identifier"
// Auto generated code by esphome
// ========== AUTO GENERATED INCLUDE BLOCK BEGIN ===========
#include "esphome.h"
using namespace esphome;
using std::isnan;
using std::min;
using std::max;
using namespace time;
using namespace switch_;
using namespace binary_sensor;
logger::Logger *logger_logger;
using namespace sensor;
StartupTrigger *startuptrigger;
Automation<> *automation;
ds1307::ReadAction<> *ds1307_readaction;
using namespace i2c;
i2c::ArduinoI2CBus *i2c_arduinoi2cbus;
preferences::IntervalSyncer *preferences_intervalsyncer;
ds1307::DS1307Component *ds1307_time;
interval::IntervalTrigger *interval_intervaltrigger;
Automation<> *automation_2;
LambdaAction<> *lambdaaction;
interval::IntervalTrigger *interval_intervaltrigger_2;
Automation<> *automation_3;
LambdaAction<> *lambdaaction_2;
using namespace output;
gpio::GPIOBinaryOutput *gpio_led;
esp32::ESP32InternalGPIOPin *esp32_esp32internalgpiopin;
gpio::GPIOBinaryOutput *gpio_buz;
esp32::ESP32InternalGPIOPin *esp32_esp32internalgpiopin_2;
output::OutputSwitch *led;
output::OutputSwitch *buz;
gpio::GPIOBinarySensor *button1;
binary_sensor::ClickTrigger *binary_sensor_clicktrigger;
Automation<> *automation_4;
LambdaAction<> *lambdaaction_3;
binary_sensor::DoubleClickTrigger *binary_sensor_doubleclicktrigger;
Automation<> *automation_5;
LambdaAction<> *lambdaaction_4;
esp32::ESP32InternalGPIOPin *esp32_esp32internalgpiopin_3;
gpio::GPIOBinarySensor *button2;
binary_sensor::PressTrigger *binary_sensor_presstrigger;
Automation<> *automation_6;
LambdaAction<> *lambdaaction_5;
binary_sensor::DoubleClickTrigger *binary_sensor_doubleclicktrigger_2;
Automation<> *automation_7;
LambdaAction<> *lambdaaction_6;
esp32::ESP32InternalGPIOPin *esp32_esp32internalgpiopin_4;
gpio::GPIOBinarySensor *button3;
binary_sensor::PressTrigger *binary_sensor_presstrigger_2;
Automation<> *automation_8;
LambdaAction<> *lambdaaction_7;
binary_sensor::DoubleClickTrigger *binary_sensor_doubleclicktrigger_3;
Automation<> *automation_9;
LambdaAction<> *lambdaaction_8;
esp32::ESP32InternalGPIOPin *esp32_esp32internalgpiopin_5;
gpio::GPIOBinarySensor *button4;
binary_sensor::PressTrigger *binary_sensor_presstrigger_3;
Automation<> *automation_10;
LambdaAction<> *lambdaaction_9;
binary_sensor::DoubleClickTrigger *binary_sensor_doubleclicktrigger_4;
Automation<> *automation_11;
LambdaAction<> *lambdaaction_10;
esp32::ESP32InternalGPIOPin *esp32_esp32internalgpiopin_6;
dht::DHT *dht_dht;
esp32::ESP32InternalGPIOPin *esp32_esp32internalgpiopin_7;
sensor::Sensor *temprature;
sensor::SensorRawStateTrigger *sensor_sensorrawstatetrigger;
Automation<float> *automation_12;
LambdaCondition<float> *lambdacondition;
IfAction<float> *ifaction;
switch_::TurnOnAction<float> *switch__turnonaction;
DelayAction<float> *delayaction;
switch_::TurnOffAction<float> *switch__turnoffaction;
DelayAction<float> *delayaction_2;
switch_::TurnOnAction<float> *switch__turnonaction_2;
DelayAction<float> *delayaction_3;
switch_::TurnOffAction<float> *switch__turnoffaction_2;
DelayAction<float> *delayaction_4;
switch_::TurnOnAction<float> *switch__turnonaction_3;
DelayAction<float> *delayaction_5;
switch_::TurnOffAction<float> *switch__turnoffaction_3;
DelayAction<float> *delayaction_6;
sensor::Sensor *humity;
duty_cycle::DutyCycleSensor *duty;
esp32::ESP32InternalGPIOPin *esp32_esp32internalgpiopin_8;
pulse_counter::PulseCounterSensor *pulse_count;
esp32::ESP32InternalGPIOPin *esp32_esp32internalgpiopin_9;
pulse_width::PulseWidthSensor *width;
esp32::ESP32InternalGPIOPin *esp32_esp32internalgpiopin_10;
ultrasonic::UltrasonicSensorComponent *Distance;
esp32::ESP32InternalGPIOPin *esp32_esp32internalgpiopin_11;
esp32::ESP32InternalGPIOPin *esp32_esp32internalgpiopin_12;
#define yield() esphome::yield()
#define millis() esphome::millis()
#define micros() esphome::micros()
#define delay(x) esphome::delay(x)
#define delayMicroseconds(x) esphome::delayMicroseconds(x)
// ========== AUTO GENERATED INCLUDE BLOCK END ==========="
#include "TouchButton.h"
#include "Status.h"
#include "displayCore.h"
#include "alarm.h"
#include "serial_IO.h"
serial_IO * serialIo;
displayCore * display;
SYSManeger * sys;
double tempratureValue;
bool SYSLight;
void setup() {
    // ========== AUTO GENERATED CODE BEGIN ===========
  // esphome:
  //   name: test
  //   on_boot:
  //   - then:
  //     - ds1307.read_time:
  //         id: ds1307_time
  //       type_id: ds1307_readaction
  //     automation_id: automation
  //     trigger_id: startuptrigger
  //     priority: 600.0
  //   build_path: .esphome/build/test
  //   platformio_options: {}
  //   includes: []
  //   libraries: []
  //   name_add_mac_suffix: false
  //   min_version: 2022.12.3
  App.pre_setup("test", __DATE__ ", " __TIME__, false);
  // time:
  // switch:
  // binary_sensor:
  // logger:
  //   level: DEBUG
  //   hardware_uart: UART2
  //   id: logger_logger
  //   baud_rate: 115200
  //   tx_buffer_size: 512
  //   deassert_rts_dtr: false
  //   logs: {}
  logger_logger = new logger::Logger(115200, 512);
  logger_logger->set_uart_selection(logger::UART_SELECTION_UART2);
  logger_logger->pre_setup();
  logger_logger->set_component_source("logger");
  App.register_component(logger_logger);
  // sensor:
  startuptrigger = new StartupTrigger(600.0f);
  startuptrigger->set_component_source("esphome.coroutine");
  App.register_component(startuptrigger);
  automation = new Automation<>(startuptrigger);
  ds1307_readaction = new ds1307::ReadAction<>();
  // i2c:
  //   scl: 21
  //   sda: 22
  //   id: i2c_arduinoi2cbus
  //   frequency: 50000.0
  //   scan: true
  i2c_arduinoi2cbus = new i2c::ArduinoI2CBus();
  i2c_arduinoi2cbus->set_component_source("i2c");
  App.register_component(i2c_arduinoi2cbus);
  i2c_arduinoi2cbus->set_sda_pin(22);
  i2c_arduinoi2cbus->set_scl_pin(21);
  i2c_arduinoi2cbus->set_frequency(50000);
  i2c_arduinoi2cbus->set_scan(true);
  // esp32:
  //   board: esp32dev
  //   framework:
  //     version: 2.0.5
  //     source: ~3.20005.0
  //     platform_version: platformio/espressif32 @ 5.2.0
  //     type: arduino
  //   variant: ESP32
  // preferences:
  //   id: preferences_intervalsyncer
  //   flash_write_interval: 60s
  preferences_intervalsyncer = new preferences::IntervalSyncer();
  preferences_intervalsyncer->set_write_interval(60000);
  preferences_intervalsyncer->set_component_source("preferences");
  App.register_component(preferences_intervalsyncer);
  // time.ds1307:
  //   platform: ds1307
  //   id: ds1307_time
  //   timezone: CST-8
  //   update_interval: 15min
  //   i2c_id: i2c_arduinoi2cbus
  //   address: 0x68
  ds1307_time = new ds1307::DS1307Component();
  ds1307_time->set_update_interval(900000);
  ds1307_time->set_component_source("ds1307.time");
  App.register_component(ds1307_time);
  ds1307_time->set_i2c_bus(i2c_arduinoi2cbus);
  ds1307_time->set_i2c_address(0x68);
  ds1307_time->set_timezone("CST-8");
  // interval:
  //   - interval: 1s
  //     then:
  //     - lambda: !lambda |-
  //         alarmEvent();
  //       type_id: lambdaaction
  //     trigger_id: trigger
  //     automation_id: automation_2
  //     id: interval_intervaltrigger
  //   - interval: 200ms
  //     then:
  //     - lambda: !lambda |-
  //         alarm();
  //       type_id: lambdaaction_2
  //     trigger_id: trigger_2
  //     automation_id: automation_3
  //     id: interval_intervaltrigger_2
  interval_intervaltrigger = new interval::IntervalTrigger();
  interval_intervaltrigger->set_component_source("interval");
  App.register_component(interval_intervaltrigger);
  automation_2 = new Automation<>(interval_intervaltrigger);
  lambdaaction = new LambdaAction<>([=]() -> void {
      #line 30 "./test.yaml"
      alarmEvent();
  });
  automation_2->add_actions({lambdaaction});
  interval_intervaltrigger->set_update_interval(1000);
  interval_intervaltrigger_2 = new interval::IntervalTrigger();
  interval_intervaltrigger_2->set_component_source("interval");
  App.register_component(interval_intervaltrigger_2);
  automation_3 = new Automation<>(interval_intervaltrigger_2);
  lambdaaction_2 = new LambdaAction<>([=]() -> void {
      #line 34 "./test.yaml"
      alarm();
  });
  automation_3->add_actions({lambdaaction_2});
  interval_intervaltrigger_2->set_update_interval(200);
  // output:
  // output.gpio:
  //   platform: gpio
  //   pin:
  //     number: 23
  //     mode:
  //       output: true
  //       input: false
  //       open_drain: false
  //       pullup: false
  //       pulldown: false
  //     drive_strength: 20.0
  //     inverted: false
  //     id: esp32_esp32internalgpiopin
  //   id: gpio_led
  gpio_led = new gpio::GPIOBinaryOutput();
  gpio_led->set_component_source("gpio.output");
  App.register_component(gpio_led);
  esp32_esp32internalgpiopin = new esp32::ESP32InternalGPIOPin();
  esp32_esp32internalgpiopin->set_pin(::GPIO_NUM_23);
  esp32_esp32internalgpiopin->set_inverted(false);
  esp32_esp32internalgpiopin->set_drive_strength(::GPIO_DRIVE_CAP_2);
  esp32_esp32internalgpiopin->set_flags(gpio::Flags::FLAG_OUTPUT);
  gpio_led->set_pin(esp32_esp32internalgpiopin);
  // output.gpio:
  //   platform: gpio
  //   pin:
  //     number: 27
  //     mode:
  //       output: true
  //       input: false
  //       open_drain: false
  //       pullup: false
  //       pulldown: false
  //     drive_strength: 20.0
  //     inverted: false
  //     id: esp32_esp32internalgpiopin_2
  //   id: gpio_buz
  gpio_buz = new gpio::GPIOBinaryOutput();
  gpio_buz->set_component_source("gpio.output");
  App.register_component(gpio_buz);
  esp32_esp32internalgpiopin_2 = new esp32::ESP32InternalGPIOPin();
  esp32_esp32internalgpiopin_2->set_pin(::GPIO_NUM_27);
  esp32_esp32internalgpiopin_2->set_inverted(false);
  esp32_esp32internalgpiopin_2->set_drive_strength(::GPIO_DRIVE_CAP_2);
  esp32_esp32internalgpiopin_2->set_flags(gpio::Flags::FLAG_OUTPUT);
  gpio_buz->set_pin(esp32_esp32internalgpiopin_2);
  // switch.output:
  //   platform: output
  //   output: gpio_led
  //   id: led
  //   disabled_by_default: false
  //   restore_mode: RESTORE_DEFAULT_OFF
  //   name: led
  //   internal: true
  led = new output::OutputSwitch();
  App.register_switch(led);
  led->set_name("led");
  led->set_disabled_by_default(false);
  led->set_internal(true);
  led->set_restore_mode(switch_::SWITCH_RESTORE_DEFAULT_OFF);
  led->set_component_source("output.switch");
  App.register_component(led);
  led->set_output(gpio_led);
  // switch.output:
  //   platform: output
  //   output: gpio_buz
  //   id: buz
  //   disabled_by_default: false
  //   restore_mode: RESTORE_DEFAULT_OFF
  //   name: buz
  //   internal: true
  buz = new output::OutputSwitch();
  App.register_switch(buz);
  buz->set_name("buz");
  buz->set_disabled_by_default(false);
  buz->set_internal(true);
  buz->set_restore_mode(switch_::SWITCH_RESTORE_DEFAULT_OFF);
  buz->set_component_source("output.switch");
  App.register_component(buz);
  buz->set_output(gpio_buz);
  // binary_sensor.gpio:
  //   platform: gpio
  //   pin:
  //     number: 18
  //     mode:
  //       input: true
  //       output: false
  //       open_drain: false
  //       pullup: false
  //       pulldown: false
  //     drive_strength: 20.0
  //     inverted: false
  //     id: esp32_esp32internalgpiopin_3
  //   id: button1
  //   on_click:
  //   - then:
  //     - lambda: !lambda |-
  //         button_handle1();
  //       type_id: lambdaaction_3
  //     automation_id: automation_4
  //     trigger_id: binary_sensor_clicktrigger
  //     min_length: 50ms
  //     max_length: 350ms
  //   on_double_click:
  //   - then:
  //     - lambda: !lambda |-
  //         button_handle1_double_click();
  //       type_id: lambdaaction_4
  //     automation_id: automation_5
  //     trigger_id: binary_sensor_doubleclicktrigger
  //     min_length: 50ms
  //     max_length: 350ms
  //   disabled_by_default: false
  //   name: button1
  //   internal: true
  button1 = new gpio::GPIOBinarySensor();
  App.register_binary_sensor(button1);
  button1->set_name("button1");
  button1->set_disabled_by_default(false);
  button1->set_internal(true);
  binary_sensor_clicktrigger = new binary_sensor::ClickTrigger(button1, 50, 350);
  automation_4 = new Automation<>(binary_sensor_clicktrigger);
  lambdaaction_3 = new LambdaAction<>([=]() -> void {
      #line 58 "./test.yaml"
      button_handle1();
  });
  automation_4->add_actions({lambdaaction_3});
  binary_sensor_doubleclicktrigger = new binary_sensor::DoubleClickTrigger(button1, 50, 350);
  automation_5 = new Automation<>(binary_sensor_doubleclicktrigger);
  lambdaaction_4 = new LambdaAction<>([=]() -> void {
      #line 62 "./test.yaml"
      button_handle1_double_click();
  });
  automation_5->add_actions({lambdaaction_4});
  button1->set_component_source("gpio.binary_sensor");
  App.register_component(button1);
  esp32_esp32internalgpiopin_3 = new esp32::ESP32InternalGPIOPin();
  esp32_esp32internalgpiopin_3->set_pin(::GPIO_NUM_18);
  esp32_esp32internalgpiopin_3->set_inverted(false);
  esp32_esp32internalgpiopin_3->set_drive_strength(::GPIO_DRIVE_CAP_2);
  esp32_esp32internalgpiopin_3->set_flags(gpio::Flags::FLAG_INPUT);
  button1->set_pin(esp32_esp32internalgpiopin_3);
  // binary_sensor.gpio:
  //   platform: gpio
  //   pin:
  //     number: 19
  //     mode:
  //       input: true
  //       output: false
  //       open_drain: false
  //       pullup: false
  //       pulldown: false
  //     drive_strength: 20.0
  //     inverted: false
  //     id: esp32_esp32internalgpiopin_4
  //   id: button2
  //   on_press:
  //   - then:
  //     - lambda: !lambda |-
  //         button_handle2();
  //       type_id: lambdaaction_5
  //     automation_id: automation_6
  //     trigger_id: binary_sensor_presstrigger
  //   on_double_click:
  //   - then:
  //     - lambda: !lambda |-
  //         button_handle2_double_click();
  //       type_id: lambdaaction_6
  //     automation_id: automation_7
  //     trigger_id: binary_sensor_doubleclicktrigger_2
  //     min_length: 50ms
  //     max_length: 350ms
  //   disabled_by_default: false
  //   name: button2
  //   internal: true
  button2 = new gpio::GPIOBinarySensor();
  App.register_binary_sensor(button2);
  button2->set_name("button2");
  button2->set_disabled_by_default(false);
  button2->set_internal(true);
  binary_sensor_presstrigger = new binary_sensor::PressTrigger(button2);
  automation_6 = new Automation<>(binary_sensor_presstrigger);
  lambdaaction_5 = new LambdaAction<>([=]() -> void {
      #line 70 "./test.yaml"
      button_handle2();
  });
  automation_6->add_actions({lambdaaction_5});
  binary_sensor_doubleclicktrigger_2 = new binary_sensor::DoubleClickTrigger(button2, 50, 350);
  automation_7 = new Automation<>(binary_sensor_doubleclicktrigger_2);
  lambdaaction_6 = new LambdaAction<>([=]() -> void {
      #line 74 "./test.yaml"
      button_handle2_double_click();
  });
  automation_7->add_actions({lambdaaction_6});
  button2->set_component_source("gpio.binary_sensor");
  App.register_component(button2);
  esp32_esp32internalgpiopin_4 = new esp32::ESP32InternalGPIOPin();
  esp32_esp32internalgpiopin_4->set_pin(::GPIO_NUM_19);
  esp32_esp32internalgpiopin_4->set_inverted(false);
  esp32_esp32internalgpiopin_4->set_drive_strength(::GPIO_DRIVE_CAP_2);
  esp32_esp32internalgpiopin_4->set_flags(gpio::Flags::FLAG_INPUT);
  button2->set_pin(esp32_esp32internalgpiopin_4);
  // binary_sensor.gpio:
  //   platform: gpio
  //   pin:
  //     number: 13
  //     mode:
  //       input: true
  //       output: false
  //       open_drain: false
  //       pullup: false
  //       pulldown: false
  //     drive_strength: 20.0
  //     inverted: false
  //     id: esp32_esp32internalgpiopin_5
  //   id: button3
  //   on_press:
  //   - then:
  //     - lambda: !lambda |-
  //         button_handle3();
  //       type_id: lambdaaction_7
  //     automation_id: automation_8
  //     trigger_id: binary_sensor_presstrigger_2
  //   on_double_click:
  //   - then:
  //     - lambda: !lambda |-
  //         button_handle3_double_click();
  //       type_id: lambdaaction_8
  //     automation_id: automation_9
  //     trigger_id: binary_sensor_doubleclicktrigger_3
  //     min_length: 50ms
  //     max_length: 350ms
  //   disabled_by_default: false
  //   name: button3
  //   internal: true
  button3 = new gpio::GPIOBinarySensor();
  App.register_binary_sensor(button3);
  button3->set_name("button3");
  button3->set_disabled_by_default(false);
  button3->set_internal(true);
  binary_sensor_presstrigger_2 = new binary_sensor::PressTrigger(button3);
  automation_8 = new Automation<>(binary_sensor_presstrigger_2);
  lambdaaction_7 = new LambdaAction<>([=]() -> void {
      #line 81 "./test.yaml"
      button_handle3();
  });
  automation_8->add_actions({lambdaaction_7});
  binary_sensor_doubleclicktrigger_3 = new binary_sensor::DoubleClickTrigger(button3, 50, 350);
  automation_9 = new Automation<>(binary_sensor_doubleclicktrigger_3);
  lambdaaction_8 = new LambdaAction<>([=]() -> void {
      #line 85 "./test.yaml"
      button_handle3_double_click();
  });
  automation_9->add_actions({lambdaaction_8});
  button3->set_component_source("gpio.binary_sensor");
  App.register_component(button3);
  esp32_esp32internalgpiopin_5 = new esp32::ESP32InternalGPIOPin();
  esp32_esp32internalgpiopin_5->set_pin(::GPIO_NUM_13);
  esp32_esp32internalgpiopin_5->set_inverted(false);
  esp32_esp32internalgpiopin_5->set_drive_strength(::GPIO_DRIVE_CAP_2);
  esp32_esp32internalgpiopin_5->set_flags(gpio::Flags::FLAG_INPUT);
  button3->set_pin(esp32_esp32internalgpiopin_5);
  // binary_sensor.gpio:
  //   platform: gpio
  //   pin:
  //     number: 14
  //     mode:
  //       input: true
  //       output: false
  //       open_drain: false
  //       pullup: false
  //       pulldown: false
  //     drive_strength: 20.0
  //     inverted: false
  //     id: esp32_esp32internalgpiopin_6
  //   id: button4
  //   on_press:
  //   - then:
  //     - lambda: !lambda |-
  //         button_handle4();
  //       type_id: lambdaaction_9
  //     automation_id: automation_10
  //     trigger_id: binary_sensor_presstrigger_3
  //   on_double_click:
  //   - then:
  //     - lambda: !lambda |-
  //         button_handle4_double_click();
  //       type_id: lambdaaction_10
  //     automation_id: automation_11
  //     trigger_id: binary_sensor_doubleclicktrigger_4
  //     min_length: 50ms
  //     max_length: 350ms
  //   disabled_by_default: false
  //   name: button4
  //   internal: true
  button4 = new gpio::GPIOBinarySensor();
  App.register_binary_sensor(button4);
  button4->set_name("button4");
  button4->set_disabled_by_default(false);
  button4->set_internal(true);
  binary_sensor_presstrigger_3 = new binary_sensor::PressTrigger(button4);
  automation_10 = new Automation<>(binary_sensor_presstrigger_3);
  lambdaaction_9 = new LambdaAction<>([=]() -> void {
      #line 92 "./test.yaml"
      button_handle4();
  });
  automation_10->add_actions({lambdaaction_9});
  binary_sensor_doubleclicktrigger_4 = new binary_sensor::DoubleClickTrigger(button4, 50, 350);
  automation_11 = new Automation<>(binary_sensor_doubleclicktrigger_4);
  lambdaaction_10 = new LambdaAction<>([=]() -> void {
      #line 96 "./test.yaml"
      button_handle4_double_click();
  });
  automation_11->add_actions({lambdaaction_10});
  button4->set_component_source("gpio.binary_sensor");
  App.register_component(button4);
  esp32_esp32internalgpiopin_6 = new esp32::ESP32InternalGPIOPin();
  esp32_esp32internalgpiopin_6->set_pin(::GPIO_NUM_14);
  esp32_esp32internalgpiopin_6->set_inverted(false);
  esp32_esp32internalgpiopin_6->set_drive_strength(::GPIO_DRIVE_CAP_2);
  esp32_esp32internalgpiopin_6->set_flags(gpio::Flags::FLAG_INPUT);
  button4->set_pin(esp32_esp32internalgpiopin_6);
  // sensor.dht:
  //   platform: dht
  //   pin:
  //     number: 32
  //     mode:
  //       input: true
  //       output: false
  //       open_drain: false
  //       pullup: false
  //       pulldown: false
  //     drive_strength: 20.0
  //     inverted: false
  //     id: esp32_esp32internalgpiopin_7
  //   temperature:
  //     id: temprature
  //     on_raw_value:
  //     - then:
  //       - if:
  //           condition:
  //             lambda: !lambda |-
  //               return id(temprature).state >= tempratureValue;
  //             type_id: lambdacondition
  //           then:
  //           - switch.turn_on:
  //               id: led
  //             type_id: switch__turnonaction
  //           - delay: 1s
  //             type_id: delayaction
  //           - switch.turn_off:
  //               id: led
  //             type_id: switch__turnoffaction
  //           - delay: 1s
  //             type_id: delayaction_2
  //           - switch.turn_on:
  //               id: led
  //             type_id: switch__turnonaction_2
  //           - delay: 1s
  //             type_id: delayaction_3
  //           - switch.turn_off:
  //               id: led
  //             type_id: switch__turnoffaction_2
  //           - delay: 1s
  //             type_id: delayaction_4
  //           - switch.turn_on:
  //               id: led
  //             type_id: switch__turnonaction_3
  //           - delay: 1s
  //             type_id: delayaction_5
  //           - switch.turn_off:
  //               id: led
  //             type_id: switch__turnoffaction_3
  //           - delay: 1s
  //             type_id: delayaction_6
  //         type_id: ifaction
  //       automation_id: automation_12
  //       trigger_id: sensor_sensorrawstatetrigger
  //     disabled_by_default: false
  //     force_update: false
  //     unit_of_measurement: °C
  //     accuracy_decimals: 1
  //     device_class: temperature
  //     state_class: measurement
  //     name: temprature
  //     internal: true
  //   humidity:
  //     id: humity
  //     disabled_by_default: false
  //     force_update: false
  //     unit_of_measurement: '%'
  //     accuracy_decimals: 0
  //     device_class: humidity
  //     state_class: measurement
  //     name: humity
  //     internal: true
  //   id: dht_dht
  //   model: AUTO_DETECT
  //   update_interval: 60s
  dht_dht = new dht::DHT();
  dht_dht->set_update_interval(60000);
  dht_dht->set_component_source("dht.sensor");
  App.register_component(dht_dht);
  esp32_esp32internalgpiopin_7 = new esp32::ESP32InternalGPIOPin();
  esp32_esp32internalgpiopin_7->set_pin(::GPIO_NUM_32);
  esp32_esp32internalgpiopin_7->set_inverted(false);
  esp32_esp32internalgpiopin_7->set_drive_strength(::GPIO_DRIVE_CAP_2);
  esp32_esp32internalgpiopin_7->set_flags(gpio::Flags::FLAG_INPUT);
  dht_dht->set_pin(esp32_esp32internalgpiopin_7);
  temprature = new sensor::Sensor();
  App.register_sensor(temprature);
  temprature->set_name("temprature");
  temprature->set_disabled_by_default(false);
  temprature->set_internal(true);
  temprature->set_device_class("temperature");
  temprature->set_state_class(sensor::STATE_CLASS_MEASUREMENT);
  temprature->set_unit_of_measurement("\302\260C");
  temprature->set_accuracy_decimals(1);
  temprature->set_force_update(false);
  sensor_sensorrawstatetrigger = new sensor::SensorRawStateTrigger(temprature);
  automation_12 = new Automation<float>(sensor_sensorrawstatetrigger);
  lambdacondition = new LambdaCondition<float>([=](float x) -> bool {
      #line 106 "./test.yaml"
      return temprature->state >= tempratureValue;
  });
  ifaction = new IfAction<float>(lambdacondition);
  switch__turnonaction = new switch_::TurnOnAction<float>(led);
  delayaction = new DelayAction<float>();
  delayaction->set_component_source("sensor");
  App.register_component(delayaction);
  delayaction->set_delay(1000);
  switch__turnoffaction = new switch_::TurnOffAction<float>(led);
  delayaction_2 = new DelayAction<float>();
  delayaction_2->set_component_source("sensor");
  App.register_component(delayaction_2);
  delayaction_2->set_delay(1000);
  switch__turnonaction_2 = new switch_::TurnOnAction<float>(led);
  delayaction_3 = new DelayAction<float>();
  delayaction_3->set_component_source("sensor");
  App.register_component(delayaction_3);
  delayaction_3->set_delay(1000);
  switch__turnoffaction_2 = new switch_::TurnOffAction<float>(led);
  delayaction_4 = new DelayAction<float>();
  delayaction_4->set_component_source("sensor");
  App.register_component(delayaction_4);
  delayaction_4->set_delay(1000);
  switch__turnonaction_3 = new switch_::TurnOnAction<float>(led);
  delayaction_5 = new DelayAction<float>();
  delayaction_5->set_component_source("sensor");
  App.register_component(delayaction_5);
  delayaction_5->set_delay(1000);
  switch__turnoffaction_3 = new switch_::TurnOffAction<float>(led);
  delayaction_6 = new DelayAction<float>();
  delayaction_6->set_component_source("sensor");
  App.register_component(delayaction_6);
  delayaction_6->set_delay(1000);
  ifaction->add_then({switch__turnonaction, delayaction, switch__turnoffaction, delayaction_2, switch__turnonaction_2, delayaction_3, switch__turnoffaction_2, delayaction_4, switch__turnonaction_3, delayaction_5, switch__turnoffaction_3, delayaction_6});
  automation_12->add_actions({ifaction});
  dht_dht->set_temperature_sensor(temprature);
  humity = new sensor::Sensor();
  App.register_sensor(humity);
  humity->set_name("humity");
  humity->set_disabled_by_default(false);
  humity->set_internal(true);
  humity->set_device_class("humidity");
  humity->set_state_class(sensor::STATE_CLASS_MEASUREMENT);
  humity->set_unit_of_measurement("%");
  humity->set_accuracy_decimals(0);
  humity->set_force_update(false);
  dht_dht->set_humidity_sensor(humity);
  dht_dht->set_dht_model(dht::DHT_MODEL_AUTO_DETECT);
  // sensor.duty_cycle:
  //   platform: duty_cycle
  //   pin:
  //     number: 34
  //     mode:
  //       input: true
  //       output: false
  //       open_drain: false
  //       pullup: false
  //       pulldown: false
  //     drive_strength: 20.0
  //     inverted: false
  //     id: esp32_esp32internalgpiopin_8
  //   id: duty
  //   disabled_by_default: false
  //   force_update: false
  //   unit_of_measurement: '%'
  //   icon: mdi:percent
  //   accuracy_decimals: 1
  //   state_class: measurement
  //   update_interval: 60s
  //   name: duty
  //   internal: true
  duty = new duty_cycle::DutyCycleSensor();
  App.register_sensor(duty);
  duty->set_name("duty");
  duty->set_disabled_by_default(false);
  duty->set_internal(true);
  duty->set_icon("mdi:percent");
  duty->set_state_class(sensor::STATE_CLASS_MEASUREMENT);
  duty->set_unit_of_measurement("%");
  duty->set_accuracy_decimals(1);
  duty->set_force_update(false);
  duty->set_update_interval(60000);
  duty->set_component_source("duty_cycle.sensor");
  App.register_component(duty);
  esp32_esp32internalgpiopin_8 = new esp32::ESP32InternalGPIOPin();
  esp32_esp32internalgpiopin_8->set_pin(::GPIO_NUM_34);
  esp32_esp32internalgpiopin_8->set_inverted(false);
  esp32_esp32internalgpiopin_8->set_drive_strength(::GPIO_DRIVE_CAP_2);
  esp32_esp32internalgpiopin_8->set_flags(gpio::Flags::FLAG_INPUT);
  duty->set_pin(esp32_esp32internalgpiopin_8);
  // sensor.pulse_counter:
  //   platform: pulse_counter
  //   pin:
  //     number: 34
  //     mode:
  //       input: true
  //       output: false
  //       open_drain: false
  //       pullup: false
  //       pulldown: false
  //     drive_strength: 20.0
  //     inverted: false
  //     id: esp32_esp32internalgpiopin_9
  //   id: pulse_count
  //   disabled_by_default: false
  //   force_update: false
  //   unit_of_measurement: pulses/min
  //   icon: mdi:pulse
  //   accuracy_decimals: 2
  //   state_class: measurement
  //   count_mode:
  //     rising_edge: INCREMENT
  //     falling_edge: DISABLE
  //   use_pcnt: true
  //   internal_filter: 13us
  //   update_interval: 60s
  //   name: pulse_count
  //   internal: true
  pulse_count = new pulse_counter::PulseCounterSensor(true);
  App.register_sensor(pulse_count);
  pulse_count->set_name("pulse_count");
  pulse_count->set_disabled_by_default(false);
  pulse_count->set_internal(true);
  pulse_count->set_icon("mdi:pulse");
  pulse_count->set_state_class(sensor::STATE_CLASS_MEASUREMENT);
  pulse_count->set_unit_of_measurement("pulses/min");
  pulse_count->set_accuracy_decimals(2);
  pulse_count->set_force_update(false);
  pulse_count->set_update_interval(60000);
  pulse_count->set_component_source("pulse_counter.sensor");
  App.register_component(pulse_count);
  esp32_esp32internalgpiopin_9 = new esp32::ESP32InternalGPIOPin();
  esp32_esp32internalgpiopin_9->set_pin(::GPIO_NUM_34);
  esp32_esp32internalgpiopin_9->set_inverted(false);
  esp32_esp32internalgpiopin_9->set_drive_strength(::GPIO_DRIVE_CAP_2);
  esp32_esp32internalgpiopin_9->set_flags(gpio::Flags::FLAG_INPUT);
  pulse_count->set_pin(esp32_esp32internalgpiopin_9);
  pulse_count->set_rising_edge_mode(pulse_counter::PULSE_COUNTER_INCREMENT);
  pulse_count->set_falling_edge_mode(pulse_counter::PULSE_COUNTER_DISABLE);
  pulse_count->set_filter_us(13);
  // sensor.pulse_width:
  //   platform: pulse_width
  //   pin:
  //     number: 34
  //     mode:
  //       input: true
  //       output: false
  //       open_drain: false
  //       pullup: false
  //       pulldown: false
  //     drive_strength: 20.0
  //     inverted: false
  //     id: esp32_esp32internalgpiopin_10
  //   id: width
  //   disabled_by_default: false
  //   force_update: false
  //   unit_of_measurement: s
  //   icon: mdi:timer-outline
  //   accuracy_decimals: 3
  //   state_class: measurement
  //   update_interval: 60s
  //   name: width
  //   internal: true
  width = new pulse_width::PulseWidthSensor();
  App.register_sensor(width);
  width->set_name("width");
  width->set_disabled_by_default(false);
  width->set_internal(true);
  width->set_icon("mdi:timer-outline");
  width->set_state_class(sensor::STATE_CLASS_MEASUREMENT);
  width->set_unit_of_measurement("s");
  width->set_accuracy_decimals(3);
  width->set_force_update(false);
  width->set_update_interval(60000);
  width->set_component_source("pulse_width.sensor");
  App.register_component(width);
  esp32_esp32internalgpiopin_10 = new esp32::ESP32InternalGPIOPin();
  esp32_esp32internalgpiopin_10->set_pin(::GPIO_NUM_34);
  esp32_esp32internalgpiopin_10->set_inverted(false);
  esp32_esp32internalgpiopin_10->set_drive_strength(::GPIO_DRIVE_CAP_2);
  esp32_esp32internalgpiopin_10->set_flags(gpio::Flags::FLAG_INPUT);
  width->set_pin(esp32_esp32internalgpiopin_10);
  // sensor.ultrasonic:
  //   platform: ultrasonic
  //   trigger_pin:
  //     number: 26
  //     mode:
  //       output: true
  //       input: false
  //       open_drain: false
  //       pullup: false
  //       pulldown: false
  //     drive_strength: 20.0
  //     inverted: false
  //     id: esp32_esp32internalgpiopin_11
  //   echo_pin:
  //     number: 25
  //     mode:
  //       input: true
  //       output: false
  //       open_drain: false
  //       pullup: false
  //       pulldown: false
  //     drive_strength: 20.0
  //     inverted: false
  //     id: esp32_esp32internalgpiopin_12
  //   id: Distance
  //   update_interval: 1s
  //   disabled_by_default: false
  //   force_update: false
  //   unit_of_measurement: m
  //   icon: mdi:arrow-expand-vertical
  //   accuracy_decimals: 2
  //   state_class: measurement
  //   timeout: 2.0
  //   pulse_time: 10us
  //   name: Distance
  //   internal: true
  Distance = new ultrasonic::UltrasonicSensorComponent();
  App.register_sensor(Distance);
  Distance->set_name("Distance");
  Distance->set_disabled_by_default(false);
  Distance->set_internal(true);
  Distance->set_icon("mdi:arrow-expand-vertical");
  Distance->set_state_class(sensor::STATE_CLASS_MEASUREMENT);
  Distance->set_unit_of_measurement("m");
  Distance->set_accuracy_decimals(2);
  Distance->set_force_update(false);
  Distance->set_update_interval(1000);
  Distance->set_component_source("ultrasonic.sensor");
  App.register_component(Distance);
  esp32_esp32internalgpiopin_11 = new esp32::ESP32InternalGPIOPin();
  esp32_esp32internalgpiopin_11->set_pin(::GPIO_NUM_26);
  esp32_esp32internalgpiopin_11->set_inverted(false);
  esp32_esp32internalgpiopin_11->set_drive_strength(::GPIO_DRIVE_CAP_2);
  esp32_esp32internalgpiopin_11->set_flags(gpio::Flags::FLAG_OUTPUT);
  Distance->set_trigger_pin(esp32_esp32internalgpiopin_11);
  esp32_esp32internalgpiopin_12 = new esp32::ESP32InternalGPIOPin();
  esp32_esp32internalgpiopin_12->set_pin(::GPIO_NUM_25);
  esp32_esp32internalgpiopin_12->set_inverted(false);
  esp32_esp32internalgpiopin_12->set_drive_strength(::GPIO_DRIVE_CAP_2);
  esp32_esp32internalgpiopin_12->set_flags(gpio::Flags::FLAG_INPUT);
  Distance->set_echo_pin(esp32_esp32internalgpiopin_12);
  Distance->set_timeout_us(11660.0f);
  Distance->set_pulse_time_us(10);
  ds1307_readaction->set_parent(ds1307_time);
  automation->add_actions({ds1307_readaction});
  // =========== AUTO GENERATED CODE END ============
    display = new displayCore();
    sys = new SYSManeger();
    serialIo = new serial_IO();
    App.register_component(display);
    App.register_component(sys);
    App.register_component(serialIo);
    pinMode(2,OUTPUT);
    App.setup();



}

void loop() {
    App.loop();
    if (SYSLight)
        digitalWrite(2,LOW);
    else
        digitalWrite(2,HIGH);
    SYSLight = !SYSLight;

}

#pragma clang diagnostic pop