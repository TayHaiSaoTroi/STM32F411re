/*
 * ETP_STM32F401_TIM.h
 *
 *  Created on: Nov 20, 2024
 *      Author: Admins
 */

#ifndef HAL_STM32F411_TIM_H_
#define HAL_STM32F411_TIM_H_
#define TIM2_ADDRESS		0x40000000
#define TIM3_ADDRESS		0x40000400
#define TIM4_ADDRESS		0x40000800
#define TIM5_ADDRESS		0x40000C00

#define TIM1_ADDRESS		0x40010000
#define TIM8_ADDRESS		0x40010400

#define TIM9_ADDRESS		0x40014000
#define TIM10_ADDRESS		0x40014400
#define TIM11_ADDRESS		0x40014800



typedef struct
{
	volatile uint32 CR1;
	volatile uint32 CR2;
	volatile uint32 SMCR;
	volatile uint32 DIER;
	volatile uint32 SR;
	volatile uint32 EGR;
	volatile uint32 CCMR1;
	volatile uint32 CCMR2;
	volatile uint32 CNT;
	volatile uint32 PSC;
	volatile uint32 ARR;
	volatile uint32 RCR;
	volatile uint32 CCR1;
	volatile uint32 CCR2;
	volatile uint32 CCR3;
	volatile uint32 CCR4;
	volatile uint32 BDTR;
	volatile uint32 DCR;
	volatile uint32 DMAR;
}TIM_t;


#endif /* HAL_STM32F411_TIM_H_ */
