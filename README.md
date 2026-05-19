# STM32 Nucleo F446RE - Hands-on Examples

<div align="center">

![STM32](https://img.shields.io/badge/STM32F446RE-Nucleo-64-blue)
![Platform](https://img.shields.io/badge/Platform-ARM%20Cortex--M4-green)
![Status](https://img.shields.io/badge/Status-Active-yellow)

</div>

> STM32F446RE "Nucleo-F446RE STM32 Nucleo-64"

This repository contains hands-on work and examples for the STM32 Nucleo microcontroller.

---

## 📋 Table of Contents

- [LED Blink](#1-led-blink)
- [LED Toggle with Bit-Fields](#2-led-toggle-with-bit-fields)
- [Keypad Interface 101](#3-keypad-interface-101)

---

## 1. LED Blink

### Overview
Basic LED blinking example using register-level programming.

### Steps Taken

| Step | Description |
|------|-------------|
| 1 | Find the Register value for the clock to enable the GPIO PORT for the given controller. |
| 2 | Enable the clock register for the given PORT, also look for the LED on which PORT is connected as well as, check the PORT registers. |
| 3 | After enabling the PORT register and set the PORT pin as OUTPUT, then first reset that bit with '0' value always. |
| 4 | To Turn ON the LED just implement logic like below. |
| 5 | To Turn OFF the LED just implement logic like below. |
| 6 | Implement the Delay logic, here have implemented with normal logic with only `for(;;);` loop. |

### Code

**Turn ON the LED:**
```c
GPIOA_1 |= (1<<5);  // if the LED is on 5th bit
```

**Turn OFF the LED:**
```c
GPIOA_1 &= ~(1<<5); // if the LED is ON then it will be Turning OFF by this logic
```

---

### ⚠️ Work In Progress
> USE PROPER DELAY as using TIMER and Using HAL parameters.

---

## 2. LED Toggle with Bit-Fields

### Overview
LED toggle example using dedicated bit-field helper libraries to simplify GPIO register access.

### Notes
- Uses custom bit-field definitions for cleaner read/write operations.
- Helps make register operations more readable than manual bit-masking.
- Demonstrates toggling LED state while preserving a structured hardware access style.

### Key Benefit
Using bit-field libraries improves maintainability by grouping register fields and reducing direct shift/mask expressions.

---

## 3. Keypad Interface 101

### Overview
Keypad interface example demonstrating a 4x3 matrix keypad scan routine.

### Notes
- Configures rows as outputs and columns as inputs with pull-down/up as needed.
- Scans keypad matrix to detect pressed keys reliably.
- Useful for learning GPIO scanning and input debouncing.

---

## 📁 Project Structure

```
STM32_Nucleo_project/
├── Src/              # Source files
├── Inc/              # Header files
├── Startup/          # Startup files
├── Debug/            # Build output
└── README.md         # This file
```

---

*Generated for STM32F446RE Nucleo-64*

