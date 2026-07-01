# Cross-compiler used to build ARM firmware
cc=arm-none-eabi-gcc

# Target ARM processor architecture
MACH=cortex-m4
NANO=nano.specs                               # this is to use the nano.specs file for printf() output on the terminal. This is used to reduce the size of the final executable file.
RDIMON=rdimon.specs                            # to monitor the printf() output on the terminal, we need to use rdimon.specs file.

# Compiler flags for building object files
CFLAGS=-c -mcpu=$(MACH) -mthumb -mfloat-abi=soft -Wall -std=gnu11 -O0

# Linker flags for building elf files / final executable files.
LDFLAGS=-mcpu=$(MACH) -mthumb -mfloat-abi=soft --specs=$(NANO) -T stm32f446_linker.ld -Wl,-Map=final.map

LDFLAGS_SEMIHOSTING=-mcpu=$(MACH) -mthumb -mfloat-abi=soft --specs=$(RDIMON) -T stm32f446_linker.ld -Wl,-Map=final.map

# Command used to remove generated build files
CLEAN=rm -rf

# Command used for OpenOcd flashing using gdb
OPENOCD=openocd
OPENOCD_PATH=/usr/share/openocd/scripts/
OPENOCD_SCRIPT=board/st_nucleo_f4.cfg                         # this is for STM32F446RE board config file.

# Default build target: compile the required object files
all: main.o led.o stm32f446_startup.o syscalls.o final.elf 

semihosting: main.o led.o stm32f446_startup.o syscalls.o final_semihosting.elf

# Rule to build main.o from main.c
main.o:main.c
	$(cc) $(CFLAGS) -o $@ $^           # $@ is the output file (main.o) and $^ is the source file (main.c)

# Rule to build led.o from led.c
led.o:led.c
	$(cc) $(CFLAGS) -o $@ $^           # $@ is the output file (led.o) and $^ is the source file (led.c)

syscalls.o:syscalls.c
	$(cc) $(CFLAGS) -o $@ $^           # $@ is the output file (syscalls.o) and $^ is the source file (syscalls.c)

stm32f446_startup.o:stm32f446_startup.c
	$(cc) $(CFLAGS) -o $@ $^           # $@ is the output file (stm32f446_startup.o) and $^ is the source file (stm32f446_startup.c)

final.elf:main.o led.o stm32f446_startup.o syscalls.o
	$(cc) $(LDFLAGS) -o $@ $^          # $@ is the output file (final.elf) and $^ is the source file (main.o),(led.o),(stm32f446_startup.o)

final_semihosting.elf:main.o led.o stm32f446_startup.o 
	$(cc) $(LDFLAGS_SEMIHOSTING) -o $@ $^          # $@ is the output file (final_semihosting.elf) and $^ is the source file (main.o),(led.o),(stm32f446_startup.o)

load:
	$(OPENOCD) -s $(OPENOCD_PATH) -f $(OPENOCD_SCRIPT)


# Clean target: remove generated object files
clean:
	$(CLEAN) *.o *.elf
