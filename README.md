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
- [fault handling debugging](#fault-handling-debugging)
- [system exception experiment](#system-exception-experiment)
- [SVC handler operations excercise](#svc-handler-operations-excercise)
- [task schedular](#task-scheduler)
- [scheduling toggle LED](#scheduling-toggle-led)
- [scheduling toggle LED with PendSV exception](#scheduling-toggle-LED-with-PendSV-exception)


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

---
## system exception experiment

### Overview

This project demonstrates how to trigger an SVC exception from thread mode, handle it in the SVC handler, and return modified data to the calling code. It also enables configurable fault exceptions so the handler flow can be observed.

### Notes

- Uses an SVC instruction from the main program to enter handler mode.
- Extracts the SVC number from the stacked return address by inspecting the instruction opcode.
- Increments the extracted value and writes it back to the saved R0 register value.
- Enables Usage Fault, Bus Fault, and MemManage Fault in the System Handler Control and Status Register.

### Steps Taken

1. Write a function that executes an SVC instruction from thread mode.
2. Implement the SVC handler and its C support function to inspect the saved stack frame.
3. Decode the SVC number from the return address and increment it by 4.
4. Store the updated value back into the R0 slot of the stack frame.
5. Print the result in the main program to verify the exception-handling flow.

---

## SVC handler operations excercise

### Overview

This project uses supervisor calls to perform arithmetic operations from handler mode and return the result to the calling function.

### Notes

- Each arithmetic helper function issues a different SVC number.
- The SVC handler decodes the request and performs the corresponding operation.
- The result is returned by writing it back into the saved R0 value in the stack frame.

### Steps Taken

1. Create helper functions for addition, subtraction, multiplication, and division that trigger distinct SVC instructions.
2. Implement the SVC handler to extract the SVC number from the instruction address.
3. Use a switch statement to select the correct arithmetic operation.
4. Read the operands from the saved stack frame and compute the result.
5. Store the result back so the calling function can print it.

---

## task schedular

### Overview

This project implements a simple cooperative scheduler using SysTick and process stack pointer switching for multiple tasks.

### Notes

- Initializes dummy exception context for each task stack.
- Switches from MSP to PSP in thread mode for task execution.
- Uses round-robin scheduling to rotate between tasks.

### Steps Taken

1. Define multiple task handlers for different tasks.
2. Allocate private stack regions and initialize each task's dummy stack frame.
3. Configure SysTick to generate periodic interrupts.
4. Switch the processor to use PSP for thread-mode execution.
5. Save and restore task context during each timer interrupt.

---

## scheduling toggle LED

### Overview

This project extends the scheduler concept to toggle different LEDs while switching between multiple tasks.

### Notes

- Each task controls a different LED.
- The tasks blink at different rates to demonstrate preemptive-style scheduling.
- The scheduler preserves context while switching between tasks.

### Steps Taken

1. Initialize the LED hardware and task stack areas.
2. Register task handlers for the LED tasks.
3. Configure SysTick for periodic task switching.
4. Use PSP-based context switching to run the tasks.
5. Observe the LED blinking pattern as the scheduler rotates between tasks.

---

## scheduling toggle LED with PendSV exception

### Overview

This project demonstrates a task scheduler that uses PendSV for context switching and a task control block to manage task state and stack pointers.

### Notes

- Uses a TCB structure to track each task's PSP and state.
- Supports blocking delays so tasks can wait before becoming runnable again.
- Performs the actual context switch inside the PendSV handler.

### Steps Taken

1. Create a task control block for each task and store its PSP and state.
2. Initialize each task's stack with a dummy exception frame and task entry address.
3. Configure SysTick and enable processor faults.
4. Implement the PendSV handler to save and restore task context.
5. Add delay and scheduling logic so blocked tasks are skipped until they become ready again.

---


