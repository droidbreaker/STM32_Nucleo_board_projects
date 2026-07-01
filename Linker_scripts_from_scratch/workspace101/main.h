/*
 * main.h
 *
 *  Created on: Jun 15, 2026
 *      Author: brak3r
 */


#ifndef MAIN_H_
#define MAIN_H_
#include <stdint.h>

/*Defining macros for the SRAM stacking assessment for private stack for each task */
#define MAX_TASK	5
#define DUMMY_XPSR 	0x01000000U      //24th bit is set to 1. T bit setting always 1. as XPSR dummy value.


#define SIZE_TASK_STACK      			1024U                    // 1KB
#define SIZE_SCHEDULAR_STACK 			1024U                    // 1KB

#define SRAM_START              		0x20000000U                       // starting address of the RAM
#define SRAM_SIZE              			( (128) * (1024) )                // Total size of SRAM of ARM Cortex M4 processor
#define SRAM_END						( (SRAM_START)+(SRAM_SIZE) )      // End address of the SRAM

#define TASK1_PRIVATE_STACK_START    		SRAM_END                                // Task1 private stack assigned
#define TASK2_PRIVATE_STACK_START     		( (SRAM_END) - (1 * SIZE_TASK_STACK) )  // Task2 private stack assigned
#define TASK3_PRIVATE_STACK_START     		( (SRAM_END) - (2 * SIZE_TASK_STACK) )  // Task3 private stack assigned
#define TASK4_PRIVATE_STACK_START     		( (SRAM_END) - (3 * SIZE_TASK_STACK) )  // Task4 private stack assigned
#define IDLE_PRIVATE_STACK_START     		( (SRAM_END) - (4 * SIZE_TASK_STACK) )  // Idle private stack assigned
#define SCHEDULAR_PRIVATE_STACK_START       ( (SRAM_END) - (5 * SIZE_TASK_STACK) )  // Schedular private stack assigned

#define TASK_READY_STATE            0x00
#define TASK_BLOCK_STATE            0xFF

/* *
 * Here we are adding the interrupt enable and disable macros, using assembly we need to use PRIMASK register to enable and disable it.
 * So here do-while loop we can apply.
 */

#define INTERRUPT_DISABLE() do{ __asm volatile ("MOV R0,#0x1"); __asm volatile ("MSR PRIMASK,R0"); }while(0)
#define INTERRUPT_ENABLE() do{ __asm volatile ("MOV R0,#0x0"); __asm volatile ("MSR PRIMASK,R0"); }while(0)

/* SYSTICK Timer macros*/
#define TICK_HZ        		1000U
#define HSI_CLK        		16000000U
#define SYSTICK_TIM_CLK 	HSI_CLK


#endif /* MAIN_H_ */
