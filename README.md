# v1-Dayak-Translator
First-of-its-kind bidirectional Indonesian ↔ Kenyah Dayak translator preserving Borneo's linguistic heritage through embedded AI

# Dayak Kenyah Language Translator (ESP32)

![ESP32](https://img.shields.io/badge/ESP32-v4.0-blue) ![License](https://img.shields.io/badge/license-MIT-green)

A cultural preservation tool that provides bidirectional translation between Indonesian and Dayak Kenyah languages using an ESP32 microcontroller. Features a web-based interface with real-time translation and phrase support.

## Key Features
- 🔄 **Bidirectional Translation**: Indonesian ↔ Dayak Kenyah
- 📡 **WiFi Connectivity**: Accessible through any web browser
- 🚀 **Real-time Processing**: Instant translation as you type
- 📱 **Responsive Design**: Works on mobile, tablet, and desktop
- 📖 **Phrase Support**: Translates multi-word entries (e.g., "rumah makan" → "amin uman")
- 🌿 **Cultural Preservation**: Maintains traditional vocabulary from the Kenyah tribe of East Kalimantan

## Technical Specifications
- **Dictionary Size**: 500+ entries including:
  - Numbers (1-1,000,000)
  - Common phrases
  - Nature-related terms
  - Cultural-specific vocabulary
- **Color Scheme**: 
  - Primary: `#2D3342` (Dark Blue)
  - Accent: `#689F99` (Teal)
- **Font**: Sans-serif with Google Fonts integration

## Requirements
- ESP32 development board
- Arduino IDE 2.0+
- Libraries:
  - `WiFi.h` (ESP32 core)
  - `WebServer.h` (ESP32 core)
  - [ArduinoJson v6.21.4](https://arduinojson.org/)

## Installation
1. Clone this repository
2. Update WiFi credentials in `esp32_dayak_translator.ino`:
   ```cpp
   const char* ssid = "YOUR_WIFI_SSID";
   const char* password = "YOUR_WIFI_PASS";
