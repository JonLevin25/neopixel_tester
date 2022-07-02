# neopixel_tester
A simple project to test neopixel strips with an arduino-based board.<br>
Flashes the pixels Red -> Green -> Blue -> White (in that order) to test color order as well.

## Requirements
* PlatformIO
* Arduino-framework compatible MCU
* PCB / Perfboard exposing pin A5 (should work with any digital/analog pin)

Uses (FastLED)[https://github.com/FastLED/FastLED] and (PlatformIO)[https://platformio.org/]

Tested with Arduino Nano, for others simply edit `platformio.ini` + change pin define if necessary
