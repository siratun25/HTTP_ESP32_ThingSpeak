# HTTP_ESP32_ThingSpeak
HTTP/REST API/ESP32/DHT22/ThingSpeak/Cloud Integration

## Project Title
 ESP32 IoT Project with DHT22 & ThingSpeak

## Description
This project demonstrates how to collect temperature and humidity data 
from a DHT22 sensor using ESP32 and send it to ThingSpeak cloud platform 
via HTTP REST API. The data is visualized in real-time on ThingSpeak 
dashboards with gauges and charts.

## Features
- ESP32 WiFi connectivity
- DHT22 temperature and humidity sensor integration
- HTTP REST API communication with ThingSpeak
- Real-time dashboard visualization (Gauge, Chart)
- Server response handling and data logging

## Hardware Required
- ESP32 DevKit v1
- DHT22 sensor
- Jumper wires
- Breadboard (optional)

## Software / Libraries
- Arduino IDE
- DHT sensor library (Adafruit)
- Adafruit Unified Sensor library
- WiFi.h (ESP32 built-in)

## Circuit Diagram
- DHT22 VCC → 3.3V
- DHT22 GND → GND
- DHT22 DATA → GPIO 4
- ESP32 → Computer via USB

## Setup / Installation
1. Install Arduino IDE and required libraries (DHT, Adafruit Sensor, WiFi.h)
2. Connect ESP32 with DHT22 as per circuit diagram
3. Replace your WiFi SSID and Password in code
4. Replace ThingSpeak Write API Key and Channel ID in code
5. Upload the code to ESP32
6. Open Serial Monitor to see sensor readings and server response
7. Data will be sent automatically to ThingSpeak dashboard every 20 seconds

## Usage/ / Dashboard View
- Login to ThingSpeak
- Open your channel dashboard
- View real-time temperature and humidity using Gauge and Chart widgets
- Configure dashboard for view-only sharing if needed
  
