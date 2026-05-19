/*
 * main.h
 *
 *  Created on: Mar 12, 2025
 *      Author: brak3r
 */

#ifndef MAIN_H_
#define MAIN_H_

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

}RCC_AHB1ENR_t;


//GPIOx_Mode_t with bit fields 2 bits in every pin.
//0 0 | Input
//0 1 | Output
//1 0 | Alternate Function Mode
//1 1 | Analog Mode

typedef struct{
	uint32_t Mode_Pin_0:2;
	uint32_t Mode_Pin_1:2;
	uint32_t Mode_Pin_2:2;
	uint32_t Mode_Pin_3:2;
	uint32_t Mode_Pin_4:2;
	uint32_t Mode_Pin_5:2;
	uint32_t Mode_Pin_6:2;
	uint32_t Mode_Pin_7:2;
	uint32_t Mode_Pin_8:2;
	uint32_t Mode_Pin_9:2;
	uint32_t Mode_Pin_10:2;
	uint32_t Mode_Pin_11:2;
	uint32_t Mode_Pin_12:2;
	uint32_t Mode_Pin_13:2;
	uint32_t Mode_Pin_14:2;
	uint32_t Mode_Pin_15:2;

}GPIOx_MODE_t;



typedef struct{
	uint32_t ODR_Pin_0:1;
	uint32_t ODR_Pin_1:1;
	uint32_t ODR_Pin_2:1;
	uint32_t ODR_Pin_3:1;
	uint32_t ODR_Pin_4:1;
	uint32_t ODR_Pin_5:1;
	uint32_t ODR_Pin_6:1;
	uint32_t ODR_Pin_7:1;
	uint32_t ODR_Pin_8:1;
	uint32_t ODR_Pin_9:1;
	uint32_t ODR_Pin_10:1;
	uint32_t ODR_Pin_11:1;
	uint32_t ODR_Pin_12:1;
	uint32_t ODR_Pin_13:1;
	uint32_t ODR_Pin_14:1;
	uint32_t ODR_Pin_15:1;
	uint32_t reserved_Odr:16;

}GPIOx_ODR_t;

#endif /* MAIN_H_ */
