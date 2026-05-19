/*
 * main.h
 *
 *  Created on: Mar 12, 2025
 *      Author: brak3r
 */
#include <stdint.h>

#ifndef MAIN_H_
#define MAIN_H_

/*
 * RCC_AHB1ENR_t
 * This is the structure of the RCC_AHB1ENR register,
 * which is used to enable the clock of the peripherals on the AHB1 bus.
 * Each peripheral has 1 bit to enable the clock of the peripheral,
 * so we need 1 bit for each peripheral, 
 * and we have 32 bits for the whole register, 
 * and the rest of the bits are reserved for future use.
 *  0 : Clock disabled
 *  1 : Clock enabled
 * --------------------------------------------------------
 */

typedef struct{
	uint32_t gpioA_en:1;
	uint32_t gpioB_en:1;
	uint32_t gpioC_en:1;
	uint32_t gpioD_en:1;
	uint32_t gpioE_en:1;
	uint32_t gpioF_en:1;
	uint32_t gpioG_en:1;
	uint32_t gpioH_en:1;
	uint32_t gpioI_en:1;
	uint32_t reserved_1:3;
	uint32_t CRC_en:1;
	uint32_t reserved_2:5;
	uint32_t bkPSRAM_en:1;
	uint32_t reserved_3:1;
	uint32_t CCMDataRam_en:1;
	uint32_t DMA1_en:1;
	uint32_t DMA2_en:1;
	uint32_t reserved_4:2;
	uint32_t EthMac_en:1;
	uint32_t EthMacTx_en:1;
	uint32_t EthMacRx_en:1;
	uint32_t EthMacPtp_en:1;
	uint32_t OtgHs_en:1;
	uint32_t OtgHsUlpi_en:1;
	uint32_t reserved_5:1;

}RCC_AHB1ENR_t;   // this is the 32 bit clock register of AHB1ENR

/*-------------------------------------------------------
* GPIOx_MODE_t
* This is the structure of the GPIOx_MODER register, 
* which is used to select the mode of the pin, 
* whether it is input, output, alternate function or analog mode. 
* Each pin has 2 bits to select the mode of the pin, 
* so we need 2 bits for each pin, and we have 16 pins, 
* so we need 32 bits for the whole register.
*  00 : Input mode (reset state)
*  01 : General purpose output mode
*  10 : Alternate function mode
*  11 : Analog mode (IF the ADC is not used, 
*       this mode can be used to reduce the power consumption of the pin)
* --------------------------------------------------------
*/

typedef struct{
	uint32_t gpioPin_Mode_0:2;                
	uint32_t gpioPin_Mode_1:2;
	uint32_t gpioPin_Mode_2:2;
	uint32_t gpioPin_Mode_3:2;
	uint32_t gpioPin_Mode_4:2;
	uint32_t gpioPin_Mode_5:2;
	uint32_t gpioPin_Mode_6:2;
	uint32_t gpioPin_Mode_7:2;
	uint32_t gpioPin_Mode_8:2;
	uint32_t gpioPin_Mode_9:2;
	uint32_t gpioPin_Mode_10:2;
	uint32_t gpioPin_Mode_11:2;
	uint32_t gpioPin_Mode_12:2;
	uint32_t gpioPin_Mode_13:2;
	uint32_t gpioPin_Mode_14:2;
	uint32_t gpioPin_Mode_15:2;
}GPIOx_MODE_t;                 // this is the 32 bit GPIO MODE register for input and output.

/*--------------------------------------------------------
 * GPIOx_ODR_t
 * This is the structure of the GPIOx_ODR register, 
 * which is used to set the output state of the pin.
 * Each pin has 1 bit to set the output state of the pin,
 * so we need 1 bit for each pin, and we have 16 pins,
 * so we need 16 bits for the whole register, 
 * and the rest of the bits are reserved for future use.
 *  0 : Output low
 *  1 : Output high
 * --------------------------------------------------------
 */

typedef struct{
	uint32_t gpio_pin_Out_0:1;
	uint32_t gpio_pin_Out_1:1;
	uint32_t gpio_pin_Out_2:1;
	uint32_t gpio_pin_Out_3:1;
	uint32_t gpio_pin_Out_4:1;
	uint32_t gpio_pin_Out_5:1;
	uint32_t gpio_pin_Out_6:1;
	uint32_t gpio_pin_Out_7:1;
	uint32_t gpio_pin_Out_8:1;
	uint32_t gpio_pin_Out_9:1;
	uint32_t gpio_pin_Out_10:1;
	uint32_t gpio_pin_Out_11:1;
	uint32_t gpio_pin_Out_12:1;
	uint32_t gpio_pin_Out_13:1;
	uint32_t gpio_pin_Out_14:1;
	uint32_t gpio_pin_Out_15:1;
	uint32_t reserved:16;

}GPIOx_ODR_t;               // this is 32 bit Output Data Register to make as output.
#endif /* MAIN_H_ */
