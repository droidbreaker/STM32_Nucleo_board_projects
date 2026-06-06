# STM32 Nucleo F446RE - Hands-on Examples

![STM32](https://img.shields.io/badge/STM32F446RE-Nucleo-64-blue) ![Platform](https://img.shields.io/badge/Platform-ARM%20Cortex--M4-green) ![Status](https://img.shields.io/badge/Status-Active-yellow)

> **STM32F446RE** - Nucleo-64 Development Board

This repository contains hands-on work and examples for the STM32F446RE Nucleo microcontroller.

---

## 📋 Table of Contents

- [LED Blink](#led-blink)
- [LED Toggle with Bit-Fields](#led-toggle-with-bit-fields)
- [Keypad Interface 101](#keypad-interface-101)
- [bit banding excercise](#bit-banding-excercise)
- []

---

## LED Blink

### Overview

Basic LED blinking example using register-level programming.

### Steps Taken

| Step | Description |
| --- | --- |
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

> USE PROPER DELAY — prefer a hardware timer or the HAL delay APIs instead of busy-wait loops.

---

## LED Toggle with Bit-Fields

### Overview

LED toggle example using dedicated bit-field helper libraries to simplify GPIO register access.

### Notes

- Uses custom bit-field definitions for cleaner read/write operations.
- Helps make register operations more readable than manual bit-masking.
- Demonstrates toggling LED state while preserving a structured hardware access style.

### Key Benefit

Using bit-field libraries improves maintainability by grouping register fields and reducing direct shift/mask expressions.

---

## Keypad Interface 101

### Overview

Keypad interface example demonstrating a 4x3 matrix keypad scan routine.

### Notes

- Configures rows as outputs and columns as inputs with pull-down/up as needed.
- Scans keypad matrix to detect pressed keys reliably.
- Useful for learning GPIO scanning and input debouncing.

---

## bit banding excercise

### overview

bit banding excercise for the extracting the particular bit from the registers.

### Notes

Here we are calculating the alias address with the formula , so that we can get direct address of that bit.
Calculate the bit band alias address for the given bit band memory address and bit position.
* Ex: 7th bit position of the memory location 0x20000200 using its alias address

* formula: `Alias_address = alias_base + (32 *(bit_band_memory_addr - bit_band_base))+ bit * 4;` 

here we are using the SRAM address which has only 1MB of bit band memory address region
and it has 32MB of bit band alias addresses. which is starting from 0x2200000

---

## fault handling debugging

### overview

usage fault, bus fault , mem manage fault exceptions handling via proper handler and debuging the issue what went wrong.

### Note

### steps taken : 

steps for implementing the fault handler:
 * 1. enable all the configurable exception : 1. usage fault, 2. bus fault, 3. mem manage fault
 * 2. implement the fault handlers
 * 3. now force the processor and implement the causes.
 * 4. analyze the fault.



## 📁 Project Structure

```
examples/
├── HelloWorld/              # Basic hello world example
├── Add_integer/             # Integer addition example
├── average1/                # Average calculation
├── bit_banding_excercise/   # Bit-banding techniques
├── blink_led_01/            # LED blinking (with HAL)
├── LED_ON/                  # LED control example
├── Led_toggle_bitFields/    # LED toggle using bit-fields
├── Pin_readPA0/             # Pin reading example
├── keypad_interface101/      # Keypad matrix interface
├── Size_Of_example/         # Data type sizing example
├── Src/                     # Common source files
├── Inc/                     # Common header files
├── Startup/                 # Startup files
├── Debug/                   # Build output
└── README.md                # This file
```

---


