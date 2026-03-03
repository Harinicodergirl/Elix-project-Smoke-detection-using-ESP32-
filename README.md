# Gas Detection and Monitoring System Using ESP32 and MQ-2 Sensor

## Project Overview

This project implements a real-time Gas Detection and Monitoring System using the ESP32 microcontroller and the MQ-2 gas sensor. The system detects combustible gases such as LPG, methane, propane, hydrogen, and smoke. When gas concentration exceeds a predefined threshold, it activates local alerts and updates a cloud dashboard for remote monitoring.

The system is suitable for residential, laboratory, and small industrial safety applications.

## Objectives

- Detect gas leakage in real time  
- Trigger immediate local alerts  
- Enable remote monitoring through Wi-Fi  
- Improve safety using an automated detection mechanism  

## Hardware Components

- ESP32 Development Board  
- MQ-2 Gas Sensor Module  
- Buzzer  
- LED Indicator (Exhaust Fan Indicator)  
- Resistors (for voltage division if required)  
- Breadboard and connecting wires  

**Note:**  
The MQ-2 operates at 5V, while ESP32 GPIO pins are 3.3V tolerant. A voltage divider was used when interfacing the analog output with the ESP32.

## Working Principle

1. The MQ-2 continuously monitors gas concentration.
2. The ESP32 reads the sensor output and compares it with a predefined threshold.
3. If gas levels exceed the threshold:
   - The buzzer is activated.
   - The LED indicator turns ON.
   - Sensor data is sent to the cloud dashboard via Wi-Fi.

## Features

- Real-time gas detection  
- Instant local alert system  
- IoT-based remote monitoring  
- Adjustable threshold levels  

## Future Enhancements

- Integration of email notification alerts  
- Replacement of the exhaust fan indicator LED with a motor to automatically activate ventilation  
- Creating a Dashboard for mobile application to send realtime alerts   

## Conclusion

This Gas Detection and Monitoring System provides a cost-effective and scalable solution for detecting hazardous gas leaks. By integrating embedded systems with IoT communication, the project enhances safety through automated alerts and remote monitoring capabilities.
