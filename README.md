# AVR_COTS

**AVR_COTS** is a modular and reusable Component Off-The-Shelf (COTS) library designed for AVR microcontroller projects. It provides a structured architecture that separates hardware abstraction, core drivers, and utility libraries to streamline embedded systems development.

## 🧱 Layers Overview

- **MCAL (Microcontroller Abstraction Layer):**
  - Provides low-level drivers for peripherals such as:
    - Digital I/O (DIO)
    - Analog-to-Digital Converter (ADC)
    - Timers
    - UART
    - SPI
    - I2C
  - Ensures direct interaction with hardware registers.

- **HAL (Hardware Abstraction Layer):**
  - Offers high-level drivers built on top of MCAL.
  - Includes modules like:
    - LCD display
    - Keypad
    - Sensors (e.g., temperature, ultrasonic)
    - Motor control
  - Facilitates easier integration of hardware components.

- **Library:**
  - Contains utility functions and common services such as:
    - Bit manipulation macros
    - Delay functions
    - Mathematical computations
    - String handling
  - Aims to reduce code redundancy and enhance portability.

