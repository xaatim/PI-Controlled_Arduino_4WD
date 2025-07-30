# 🚗 Pi-Controlled Arduino 4WD Car

[![Python](https://img.shields.io/badge/Python-3.10-blue?logo=python)](https://www.python.org/)
[![Arduino](https://img.shields.io/badge/Arduino-Motor%20Control-00979D?logo=arduino)](https://www.arduino.cc/)
[![Gamepad](https://img.shields.io/badge/Control-Keyboard%20%7C%20Gamepad-green)]()
[![Status](https://img.shields.io/badge/Status-Completed-brightgreen)]()

---

## 📖 Overview

The **Pi-Controlled Arduino 4WD Car** is a modular robotics platform that combines the **computational power of Raspberry Pi** with the **precise motor control of Arduino**. It can be controlled using **keyboard inputs** or a **gamepad**, making it a great base for robotics experiments, autonomous navigation projects, or custom IoT applications.

---

## 🎯 Key Features

- **Dual-Layer Control:**
  - **Raspberry Pi** for high-level processing & control.
  - **Arduino** for low-level motor control.
- **Multiple Control Modes:**
  - **Keyboard Control** – Direct commands via terminal.
  - **Gamepad Controller** – Smooth driving experience.
- **Modular Design:** Easy to integrate additional sensors (e.g., ultrasonic, camera).
- **Serial Communication:** Pi-Arduino data exchange via **PySerial**.

---

## 🧰 Tech Stack

- **Hardware:** Arduino, Raspberry Pi, 4WD Chassis, Motor Driver (L298N)
- **Programming:** Python (control scripts), Arduino C (firmware)
- **Libraries:**
  - `pyserial` – For Pi-Arduino communication
  - `pygame` – For gamepad input
- **Optional:** USB Camera (for computer vision expansion)

---

## 🗂 Project Structure

```

Pi-Controlled\_Arduino\_4WD/
│
├── .vscode/               \# VSCode workspace settings
├── arduino\_firmware/      \# Arduino sketches and firmware
├── python\_control/        \# Python control scripts
│   ├── gamepad\_controller.py    \# Gamepad control script
│   ├── keyboard\_controller.py   \# Keyboard control script
│   └── main.py                  \# Main execution script
├── extras/                \# Diagrams, photos, videos, etc.
├── .gitignore
└── README.md

````

---

## ⚙️ Installation & Setup

1.  **Clone the repository**
    ```bash
    git clone [https://github.com/xaatim/PI-Controlled_Arduino_4WD.git](https://github.com/xaatim/PI-Controlled_Arduino_4WD.git)
    cd PI-Controlled_Arduino_4WD
    ```

2.  **Install Python dependencies**

    ```bash
    pip install pyserial pygame
    ```

3.  **Upload Arduino Firmware**
    Navigate to the `arduino_firmware/` directory, open the sketch in Arduino IDE, and upload your motor control firmware to the Arduino.

4.  **Run the controller**

    ```bash
    python python_control/main.py
    ```

    Select your desired mode (**keyboard** or **gamepad**).

---

## 🎮 Control Options

* **Keyboard Controls:**

    * `W` – Forward
    * `S` – Backward
    * `A` – Left
    * `D` – Right
    * `Q` – Quit

* **Gamepad:**

    * Joystick for directional movement.
    * Buttons for speed control (configurable in `python_control/gamepad_controller.py`).

---

## 📷 Visuals

You can add diagrams, photos, and videos of the car in the [`extras/`](./extras) folder (e.g., chassis CAD, wiring diagrams, test runs).

---

## 🚀 Future Improvements

* Add **autonomous navigation** (line following, obstacle avoidance).
* Integrate **camera & computer vision** for object tracking.
* Add **IoT remote control** (via Blynk or MQTT).

---

## 📄 License

This project is licensed under the **MIT License**. See [`LICENSE`](./LICENSE) for details.

---

## 👤 Author

**Hatim Ahmed Hassan** – 2025
For inquiries or collaborations: **[xayari229@gmail.com](mailto:xayari229@gmail.com)**
