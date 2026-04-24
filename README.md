# 📊 Smart Sensor Dashboard --- Arduino + Python Monitoring System

## 📌 Overview

This project is a real-time sensor monitoring system that integrates
**Arduino-based data acquisition** with a **Python dashboard for
visualization and logging**.

The system reads multiple environmental sensors (temperature, humidity,
distance, and light intensity), sends structured data via serial
communication, and displays it live while saving it for further
analysis.

------------------------------------------------------------------------

## 🚀 Features

-   📡 Multi-sensor data acquisition using Arduino\
-   🔌 Real-time serial communication (UART)\
-   📊 Live dashboard with 4 plots (Temperature, Humidity, Distance,
    Light)\
-   💾 Data logging to CSV with timestamps\
-   🧼 Clean modular embedded code using structs and functions\
-   ⚡ Real-time updates using animation

------------------------------------------------------------------------

## 🏗️ System Architecture

Sensors → Arduino → Serial (UART) → Python Dashboard → Plot + CSV
Logging → (MATLAB Analysis - coming soon)

------------------------------------------------------------------------

## 🔌 Hardware Components

-   Arduino Uno\
-   DHT11 (Temperature & Humidity sensor)\
-   HC-SR04 (Ultrasonic distance sensor)\
-   LDR (Light sensor)\
-   Breadboard + resistors + jumper wires

------------------------------------------------------------------------

## 🔧 Sensor Connections

### 🌡️ DHT11

-   VCC → 5V\
-   GND → GND\
-   Data → Digital Pin 3

### 📏 HC-SR04 (Ultrasonic)

-   VCC → 5V\
-   GND → GND\
-   Trig → Pin 9\
-   Echo → Pin 10

### 💡 LDR

-   One side → 5V\
-   Other side → Analog Pin A0\
-   Resistor (10kΩ) → GND (voltage divider)

------------------------------------------------------------------------

## 🧠 Software Components

-   Arduino (C/C++) → Sensor reading & data transmission\
-   Python → Data acquisition, visualization, logging\
-   CSV → Data storage\
-   MATLAB *(to be added)* → Data analysis

------------------------------------------------------------------------

## 📊 Example Data Format

humidity,temperature,distance,light\
45.2,26.1,120.5,350

------------------------------------------------------------------------

## 📷 Dashboard Features

-   4 real-time plots:
    -   Temperature (°C)
    -   Humidity (%)
    -   Distance (cm)
    -   Light (Raw ADC)
-   Last 100 samples displayed (using deque)
-   Auto-updating every 200 ms
-   Exit using keyboard (e.g., press 'q')

------------------------------------------------------------------------

## 📁 Project Structure

/project\
├── arduino/\
│ └── sensor_reading.ino\
├── python/\
│ └── dashboard.py\
├── data/\
│ └── sensor_log.csv\
└── README.md

------------------------------------------------------------------------

## 🎯 What I Learned

-   📡 Interfacing multiple sensors with Arduino\
-   🔌 Serial communication (UART)\
-   🧠 Structuring embedded code using structs and functions\
-   🐍 Python serial communication using pyserial\
-   📊 Real-time data visualization using Matplotlib\
-   💾 Data logging using CSV\
-   ⚡ Event-driven programming\
-   🧼 Writing clean modular code

------------------------------------------------------------------------

## 🔥 Future Improvements

-   📈 MATLAB data analysis\
-   🖥️ GUI dashboard (PyQt / Tkinter)\
-   📡 Wireless communication\
-   🤖 ROS 2 integration\
-   📊 Signal filtering

------------------------------------------------------------------------

## ▶️ How to Run

pip install pyserial matplotlib\
python dashboard.py

------------------------------------------------------------------------

## 💡 Notes

-   Select correct COM port\
-   Close Arduino Serial Monitor before running Python\
-   Use newline='' in CSV to avoid blank lines

------------------------------------------------------------------------

## 👨‍💻 Author

Ahmed Shalash\
Mechatronics Engineer \| Robotics & Automation Enthusiast
