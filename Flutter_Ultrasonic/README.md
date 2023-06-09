# Ultrasonic Range Finder
An ultrasonic range finder flutter application to show distance information using BLE.

## Components used:
The following components were used:
- espressif ESP32 ([Datasheet](https://www.espressif.com/sites/default/files/documentation/esp32-wroom-32d_esp32-wroom-32u_datasheet_en.pdf))
- HC-SR04 Ultrasonic Range Sensor ([Datasheet](https://cdn.sparkfun.com/datasheets/Sensors/Proximity/HCSR04.pdf))
- 0.96" OLED Display

*Note: if Arduino IDE may be unable to find the port for the ESP32, check device manager to see if there are any issues the port drivers. 
The following driver may need to be installed: CP210x USB to UART Bridge Virtual COM Port (VCP) drivers*

*- [CP210 Drive](https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers)*

*- [Installation Guide](https://www.pololu.com/docs/0J7/all#2)*

## Project Libraries
The following libraries were imported for use in Arduino IDE:
- [espressif ESP32 libraries](https://espressif.github.io/arduino-esp32/package_esp32_index.json), [raw githubuser library](https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json)
- [Adafruit GFX Library](https://github.com/adafruit/Adafruit-GFX-Library)
- [Adafruit BusIO](https://github.com/adafruit/Adafruit_BusIO)
- [Adafruit SSD1306](https://github.com/adafruit/Adafruit_SSD1306)
