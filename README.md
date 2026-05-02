# 🚨 ESP32 PIR Motion Alert via WhatsApp

## 📌 Overview

This project uses an **ESP32** and a **PIR motion sensor** to detect movement and send real-time alerts to your **WhatsApp** using the CallMeBot API.

When motion is detected, the ESP32 connects to WiFi and sends a message:

> **"🚨 ALERTA!! MOVIMIENTO DETECTADO 🚨"**

---

## ⚙️ How It Works

1. The ESP32 connects to a WiFi network.
2. A PIR sensor continuously monitors for motion.
3. When motion is detected:

   * The ESP32 triggers an HTTP request.
   * The request is sent to the CallMeBot API.
   * A WhatsApp message is delivered to the configured phone number.
4. A delay mechanism prevents message spam by limiting how often alerts are sent.

---

## 🧰 Hardware Requirements

* ESP32 board
* PIR motion sensor (e.g., HC-SR501 or HC-SR505)
* Jumper wires
* Breadboard (optional)

---

## 🌐 Software Requirements

* Arduino IDE
* ESP32 board support installed
* Required libraries:

  * `WiFi.h`
  * `HTTPClient.h`
  * `UrlEncode.h`

---

## 🔑 Setup

1. Clone or copy this project.
2. Open the `.ino` file in Arduino IDE.
3. Configure your credentials:

   ```cpp
   #define WIFI_SSID "your_wifi_name"
   #define WIFI_PASS "your_wifi_password"

   String apiKey = "your_api_key";
   String mobileNumber = "your_phone_number";
   ```
4. Activate your number with CallMeBot (required before sending messages).
5. Upload the code to your ESP32.

---

## 🚀 Usage

* Power the ESP32.
* Once connected to WiFi, the system starts monitoring motion.
* When movement is detected, you will receive a WhatsApp alert.

---

## ⚠️ Notes

* PIR sensors may stay HIGH for a few seconds after detection.
* A cooldown interval is implemented to avoid message flooding.
* Ensure stable WiFi connectivity for reliable notifications.

---

## 📄 License

This project is open-source. Feel free to use, modify, and distribute it.

If you improve the project, consider submitting a pull request

---
