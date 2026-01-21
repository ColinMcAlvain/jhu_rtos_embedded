# Software Development for Real-Time Embedded Systems

This repository contains coursework and project implementations for **EN.605.715 – Software Development for Real-Time Embedded Systems**.

The projects progress incrementally from basic embedded hardware control to real-time operating systems and embedded Linux integration. Later projects combine multiple subsystems into a complete quadcopter platform capable of acquiring and transmitting sensor and multimedia data in real time.

---

## Course Context

- **Institution:** Johns Hopkins University  
- **Program:** Engineering for Professionals  
- **Course:** EN.605.715 – Software Development for Real-Time Embedded Systems  
- **Term:** Spring 2026  

---

## Project Scope

This repository includes multiple projects that build upon one another, covering:

- Bare-metal microcontroller development
- Interrupts and real-time control
- RTOS-based concurrency and scheduling
- Embedded Linux development on Raspberry Pi
- Sensor integration (temperature, IMU, GPS)
- Wireless communication (Wi-Fi, Bluetooth)
- Multi-bus communication (I2C, serial)

---

## Repository Structure

Projects are organized by module or project number. Each project directory contains source code, build artifacts, and documentation specific to that stage of development.

---

## Technologies

- C / C++
- Arduino / ESP32
- FreeRTOS
- Raspberry Pi (Embedded Linux)
- I2C, Serial, Wi-Fi, Bluetooth

---

## Usage

This repository is intended for academic and educational purposes. Code is provided as-is and is not intended for production or flight-critical use.

---

## License

This project is licensed under the MIT License.

---

## Project 1 Morse Code LED or LCD System Development
-Project - Hello World

-Develop a C or C++ (or whatever other language you prefer) application
which executes on an Arduino and displays a user typed string, such as
“Hello World”, as Morse Code on an LED (or several LEDs), or an LCD.
Implement all of the Morse Code letters. The word or phrase should typed
and followed by enter and need not be an entire sentence with periods,
commas, apostrophes, or other punctuations.

-Design using a Round Robbin Design where in a loop it waits for a string,
displays it in Morse Code, and only exits the loop if a sentinel is entered,
such as ctrl-z

-This Application can be developed using the VS Code, Arduino Sketch,
AVRDude, AVR Studio, WinAVR, or any other IDE you wish to use.

-Submit per directions in “Project Submission.docx”

---
