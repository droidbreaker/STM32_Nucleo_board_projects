# STM32F446 Bare-Metal Project

This project is a simple bare-metal firmware example for the STM32F446 microcontroller. It shows how the build process, memory layout, and startup sequence work for embedded C code.

## Makefile

The Makefile is used to automate the build process. It contains:

- the ARM cross-compiler `arm-none-eabi-gcc`
- target architecture settings for Cortex-M4
- compiler and linker flags for building object files and the final ELF executable
- rules to build the source files such as `main.c`, `led.c`, `syscalls.c`, and `stm32f446_startup.c`
- a `clean` target to remove generated build files
- an OpenOCD target for flashing the board

## Linker Script (`stm32f446_linker.ld`)

The linker script defines how the program is placed in memory for the STM32F446. It contains:

- the entry point `Reset_Handler`
- memory regions for Flash and SRAM
- section placement rules for `.text`, `.data`, `.bss`, and `.heap`
- symbols such as `_etext`, `_sdata`, `_edata`, `_sbss`, `_ebss`, and `_estack` used by the startup code

## Startup File (`stm32f446_startup.c`)

The startup file provides the code executed when the MCU starts. It contains:

- the interrupt vector table
- weak default handlers for exceptions and interrupts
- the `Reset_Handler` function
- code to copy initialized data from Flash to SRAM and zero the `.bss` section
- a call to `main()` after initialization

---

## How To Flash .elf/.bin files from command line Interface

#### Using OPENOCD (OPEN ON CHIP DEBUGGER): 

- Adding the loading script in Makefile ,as per the Board selection and its config file selection, 
- here we have selected `st_nucleo_f4.cfg` for `STM32Nucleo` board `STM32F446RE` microcontroller. 

---

---
#### Steps taken: 

1. Open the folder where you have source files and header files/ give exact path in Makefile.
2. in Makefile link `*.c` which is source file into target file which is `*.o` object/target file.
3. use command: `make all` it will generate `*.o` and `*.elf` files, also it will generate `*.map`.
4. if we want to see the diassembly, as well as we want to see the objectdump of Object file then we can view it by using `arm-none-eabi-objdump -h *.o` or `arm-none-eabi-objdump -D *.o`.
5. now we need to load the `*.elf` file into the board/controller's flash memory.
6. use command : `make load` , it will load the image `*.elf` by using `OpenOCD` config file. 

7. Now OPEN NEW TERMINAL: It will show the `PORT number : 3333` , we need to open new terminal and use the command as `arm-none-eabi-gdb`.
8. it will open `gdb` :
9. In GDB use command: 
    
    ```command
        target extended-remote localhost:3333
        monitor reset init
        monitor flash write_image erase *.elf
        monitor reset halt
        monitor resume 
    ```

10. To view the data at which the address is holding:

    ```command
        monitor mdw 0xXXXXXXXX 4          // here 4 is word length

    ```

11. To create breakpoint at particular address, then we can do it by using command: 
    
    ```command
        monitor bp 0xXXXXXXXX hw 
    ```

---

---

#### SemiHosting feature for viewing printf() in OpenOCD terminal:

1. To view the printf() statements on the OpenOCD , we need to modify Makefile with `rdimon.specs` file which is the library required for printf statements.
2. include the `initialization_monitor_handles();` function in  main() function and extern its function prototype.
3. now use command: 
    
    ```command

        monitor reset init
        monitor flash write_image final_semihosting.elf
        monitor arm semihosting enable
        monitor reset halt
        monitor resume
        monitor reset

    ```

---

#### REF: [OpenOCD Commands](https://openocd.org/doc/html/General-Commands.html)