ESP32-based wifi beacon logger.

A lot of what people are doing on rasp pi's is overkill and an ESP32 could be used instead.

Use case:
- Log wifi base stations with key information, on a very small size and power device.
- Definitely expandable to add more 802.11 research features. 

Setup:

- Flash project to ESP32 using platformio on VSCode
- In this version, collection routine executes immediately and passes data off the device using serial
- For testing, use the serial-over-usb and serial monitor in VSCode

Project layout:
- Developed in C++ on platformio in VSCode
- device behavior files are in /src/

Flow of control:
- main.cpp:
  - setup() and loop() are called from the framework
  - Establishes serial comms
  - Scans for hidden and visible wifi networks, prints a table with SSID, RSSI, and encryption type
  - In this version, all output is live to a serial receiver (115200)

Documentation
- This readme, and the comments in the /src files

Dependencies:
platformio, including arduino wifi library

Future:
- local storage of logs with sd card expansion or on EEPROM
- automatic wireless data egress over MQTT, or control/retrieval through a wifi webui (station mode for control, enters monitor mode to scan, gpio button to come back to client mode, webui available again to copy off findings)
- LED status indication
