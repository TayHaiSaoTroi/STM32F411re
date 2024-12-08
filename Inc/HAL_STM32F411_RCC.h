/*
 * stm32f401_rcc.h
 *
 *  Created on: Nov 11, 2024
 *      Author: Admins
 */

#ifndef HAL_STM32F411_RCC_H_
#define HAL_STM32F411_RCC_H_

#include "std_type.h"
#include "Bit_math.h"
#define PERIPHERAL_BASE		0x40000000
#define RCC_BASE_ADDRESS	0x40023800
#define PWR_BASE_ADDRESS	0x40007000


/*define bit AHB1*/
#define RCC_GPIOAENR	(1<<0U)
#define RCC_GPIOBENR	(1<<1U)
#define RCC_GPIOCENR	(1<<2U)
#define RCC_GPIODENR	(1<<3U)
#define RCC_GPIOEENR	(1<<4U)
#define RCC_GPIOHENR	(1<<7U)
#define RCC_DMA1ENR	(1<<21U)
#define RCC_DMA2ENR	(1<<22U)

/*define bit APB1*/

#define RCC_TIM2ENR	(1<<0U)
#define RCC_TIM3ENR	(1<<1U)
#define RCC_TIM4ENR	(1<<2U)
#define RCC_TIM5ENR	(1<<3U)
#define RCC_SPI2ENR	(1<<14U)
#define RCC_SPI3ENR	(1<<15U)
#define RCC_USART2ENR	(1<<17U)
#define RCC_I2C1ENR	(1<<21U)
#define RCC_I2C2ENR	(1<<22U)
#define RCC_I2C3ENR	(1<<23U)
#define RCC_PWRENR		(1<<28U)

#define PWR_CR_VOS	(1<<14U)

/*define bit APB2*/

#define RCC_TIM1ENR	(1<<0U)
#define RCC_USART1ENR	(1<<4U)
#define RCC_USART6ENR	(1<<5U)
#define RCC_ADC1ENR	(1<<8U)
#define RCC_SPI1ENR 	(1<<12U)
#define RCC_SPI4ENR	(1<<13U)
#define RCC_SYSCFGENR	(1<<14U)
#define RCC_TIM9ENR	(1<<16U)
#define RCC_TIM10ENR	(1<<17U)
#define RCC_TIM11ENR	(1<<18U)


typedef struct
{
	volatile uint32 CR; //0x00
	volatile uint32 PLLCFGR; //0x04
	volatile uint32 CFGR; // 0x08
	volatile uint32 CIR;//0x0C
	volatile uint32 AHB1RSTR;//0x10
	volatile uint32 AHB2RSTR;//0x14
	volatile uint32 reserved1[2];//0x18,0x1C
	volatile uint32 APB1RSTR;//0x20
	volatile uint32 APB2RSTR;//0x24
	volatile uint32 reserved2[2];//0x28,0x2C
	volatile uint32 AHB1ENR;//0x30
	volatile uint32 AHB2ENR;//0x34
	volatile uint32 reserved3[2];
	volatile uint32 APB1ENR;//0x40
	volatile uint32 APB2ENR;//0x44
	volatile uint32 reserved4[2];
	volatile uint32 AHB1LPENR;//0x50
	volatile uint32 AHB2LPENR;//0x54
	volatile uint32 reserved5[2];//0x58,0x5C
	volatile uint32 APB1LPENR;//0x60
	volatile uint32 APB2LPENR;//0x64
	volatile uint32 reserved6[2];
	volatile uint32 BDCR;//0x70
	volatile uint32 CSR;//0x74
	volatile uint32 reserved7[2];
	volatile uint32 SSCGR;//0x80
	volatile uint32 PLLI2SCFGR;//0x84
	volatile uint32 DCKCFGR;//0x8C
}RCC_t;

typedef struct PWR
{
	volatile uint32 PWR_CR;
	volatile uint32 PWR_CSR;
}PWR_t;
#define RCC_CR_HSEON	(1<<16U)
#define RCC_CR_HSERDY	(1<<17U)
#define RCC_CR_HSION	(1<<0U)
#define RCC_CR_HSIRDY	(1<<1U)
#define RCC_CR_PLL		(1<<24U)
#define RCC_CR_PLLRDY	(1<<25U)
#define RCC_PLLCFGR_SRC_HSE	(1U<<22)
#define RCC_PLLCFGR_SRC_HSI	(0U)
#define RCC_PLL_SW			(1U<<2)
#define RCC_PLL_SWS			(1U<<4)
#define RCC_HSE_SW			(1U<<1)
#define RCC_HSI_SW			(0U)
#define RCC_HSE_SWS			(1U<<3)
#define RCC_HSI_SWS			(0U)
#define RCC_CFGR_PLLM		(0U)
#define RCC_CFGR_PLLN		(6U)
#define RCC_CFGR_PLLP		(16U)
#define RCC_CFGR_PLLQ		(24U)


#define ON 				1
#define OFF				0
#define HSI_CLOCK_ENABLE	OFF
#define HSE_CLOCK_ENABLE	ON
#define HSECLOCKSPEED 8U
#define HSICLOCKSPEED 16U

#if HSI_CLOCK_ENABLE
#define PLL_CLOCK 16
#else
#define PLL_CLOCK 8
#endif

// HPRE	AHB precaler
#define HPRE_CLOCK_POS			(4U) // AHBP Prescaler
#define HPRE_CLOCK_DIV_1	    0U
#define HPRE_CLOCK_DIV_2		2U
#define HPRE_CLOCK_DIV_4		4U
#define HPRE_CLOCK_DIV_8		8U
#define HPRE_CLOCK_DIV_16		16U
#define HPRE_CLOCK_DIV_64		64U
#define HPRE_CLOCK_DIV_128		128U
#define HPRE_CLOCK_DIV_256		256U
#define HPRE_CLOCK_DIV_512		512U

//PPRE1 APB1 precaler // register 10

#define PPRE1_CLOCK_POS			10U //APB1 Prescaler
#define PPRE1_CLOCK_DIV1	(0b000)
#define PPRE1_CLOCK_DIV2	(0b100)
#define PPRE1_CLOCK_DIV4	(0b101)
#define PPRE1_CLOCK_DIV8	(0b110)
#define PPRE1_CLOCK_DIV16	(0b111)

// PPRE2 APB2 precaler // register 13

#define PPRE2_CLOCK_POS			13U // APB2 Prescaler
#define PPRE2_CLOCK_DIV1	(0b000)
#define PPRE2_CLOCK_DIV2	(0b100)
#define PPRE2_CLOCK_DIV4	(0b101)
#define PPRE2_CLOCK_DIV8	(0b110)
#define PPRE2_CLOCK_DIV16	(0b111)

/////////////////////////////////////////
#define GPIOA_CLOCK_ENABLE	(1<<0)
#define GPIOB_CLOCK_ENABLE	(1<<1)
#define GPIOC_CLOCK_ENABLE 	(1<<2)
#define GPIOD_CLOCK_ENABLE	(1<<3)
#define GPIOE_CLOCK_ENABLE	(1<<4)
#define GPIOH_CLOCK_ENABLE	(1<<7)
/////////////////////////////////////////

#define RCC	((volatile RCC_t *)RCC_BASE_ADDRESS)
#define PWR	((volatile PWR_t *)PWR_BASE_ADDRESS)
//RCC Phase clock loop
void HAL_RCC_SetSystemClockByPLL(uint32 SysClc, uint32 AHBPre, uint32 APB1Pre, uint32 APB2Pre);
void HAL_RCC_SetSystemClockTo16Mhz(void);
void HAL_RCC_SetSystemClockTo8Mhz(void);

inline uint32 HAL_RCC_GET_AHBPre(uint32 SysClk, uint32 AHBPre_Div);
inline uint32 HAL_RCC_GET_APB1Pre(uint32 SysClk,uint32 AHBPre_Div,uint32 APB1Pre_Div);
inline uint32 HAL_RCC_GET_APB2Pre(uint32 SysClk, uint32 AHBPre_Div,uint32 APB2Pre_Div);
//GPIO Clock
void HAL_GPIOA_ENABLE_CLOCK();
void HAL_GPIOB_ENABLE_CLOCK();
void HAL_GPIOC_ENABLE_CLOCK();
void HAL_GPIOD_ENABLE_CLOCK();
void HAL_GPIOE_ENABLE_CLOCK();
void HAL_GPIOH_ENABLE_CLOCK();

//Timer Clock
void HAL_TIM1_ENNABLE_CLOCK();
void HAL_TIM2_ENNABLE_CLOCK();

void HAL_TIM3_ENNABLE_CLOCK();
void HAL_TIM4_ENNABLE_CLOCK();
void HAL_TIM5_ENNABLE_CLOCK();
void HAL_TIM9_ENNABLE_CLOCK();
void HAL_TIM10_ENNABLE_CLOCK();
void HAL_TIM11_ENNABLE_CLOCK();



//////////////


#endif /* HAL_STM32F411_RCC_H_ */
