#  Smart Gate Ultrasonic Servo System (Arduino)

**Author:** kingScarH  
**Language:** C (Arduino)  
**Platform:** Arduino UNO  
**Last Updated:** October 2025  

---

##  Overview
This project automatically opens and closes a gate using an **HC-SR04 Ultrasonic Sensor** and an **SG90 Servo Motor**.  
When a vehicle is detected within a set range, the gate opens automatically, accompanied by **LED** and **buzzer** indicators.  
The system follows industrial-style programming structure and coding conventions.

---

##  Components
| Component | Description |
|------------|-------------|
| Arduino UNO | Main microcontroller board |
| HC-SR04 Ultrasonic Sensor | Vehicle distance detection |
| SG90 Servo Motor | Gate actuator |
| LEDs (Red/Green) | Status indicators |
| Buzzer | Audio alert system |

---

##  Working Principle
1. **Ultrasonic Sensor** continuously measures the distance to detect nearby vehicles.  
2. If a vehicle is within **20 cm**, the **servo** rotates from 180° → 90° (gate open).  
3. The **green LED** turns ON and the **buzzer** beeps twice.  
4. After 3 seconds or when no vehicle is detected, the **servo** returns to 180° (gate closed).  
5. The **red LED** turns ON and the **buzzer** beeps thrice.

---

##  Pin Configuration

| Arduino Pin | Connected To | Description |
|--------------|--------------|--------------|
| 2 | TRIG | Ultrasonic Trigger |
| 3 | ECHO | Ultrasonic Echo |
| 5 | GREEN LED | Gate Open Indicator |
| 6 | RED LED | Gate Closed Indicator |
| 7 | BUZZER | Audio Alert |
| 9 | SERVO | Gate Actuator |

---

##  File Description

| File | Description |
|------|--------------|
| `main.c` | Complete source code written in MISRA C-style format |
| `README.md` | Project documentation and setup guide |

---

##  Code Features
- MISRA-inspired naming conventions  
- Modular structure using static functions  
- Well-commented industrial-style C  
- No magic numbers, clear constants  
 -Compatible with Arduino IDE  

---

##  How to Upload
1. Open **Arduino IDE**  
2. Copy contents of `main.c` into a new sketch  
3. Select **Board: Arduino UNO** and correct **COM Port**  
4. Upload the code  
5. Power your setup and observe automatic gate operation

---

##  Future Enhancements
- Add IR or RFID-based vehicle access  
- Integrate with Wi-Fi for IoT-based logging  
- Implement FSM (Finite State Machine) for multi-gate control  
- Add low-power (sleep) mode with interrupt wakeup  

---

##  License
This project is open-source and free to use for educational and research purposes.  
© 2025 **kingScarH** – All Rights Reserved.
