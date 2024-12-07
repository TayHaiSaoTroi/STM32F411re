/*
 * HAL_STM32F411_RCC.c
 *
 *  Created on: Nov 12, 2024
 *      Author: MinhTan
 */
#include <HAL_STM32F411_FLASH.h>
#include <HAL_STM32F411_RCC.h>

static void HAL_RCC_HSE_ON();
static void HAL_RCC_HSI_ON();
static void HAL_RCC_PLL_ON();

void HAL_RCC_SetSystemClockByPLL(uint32 SysClc, uint32 AHBPre, uint32 APB1Pre, uint32 APB2Pre)
{
	uint32 NMask;
	uint32 HPRE = 0;
#if HSE_CLOCK_ENABLE
	HAL_RCC_HSE_ON();
#else
	HAL_RCC_HSI_ON();
#endif
	RCC->APB1ENR |=RCC_PWRENR;
	PWR->PWR_CR |=PWR_CR_VOS;
	FLASH->ACR |= FLASH_ACR_ICEN | FLASH_ACR_DCEN | FLASH_ACR_PRFTEN | FLASH_ACR_LATENCY_3WS ;


	//AHB Prescaler
	if(AHBPre)
	{
	while(AHBPre /2 !=1)
	{
		AHBPre = AHBPre/2;
		HPRE ++;
	}
	HPRE +=7;
	}
	RCC->CFGR &=~ (0xF << HPRE_CLOCK_POS);
	RCC->CFGR |= (HPRE << HPRE_CLOCK_POS);
	// APB1 Prescaler
	uint32 PPRE1 = 0;
	if(APB1Pre)
	{
		while((APB1Pre & 1) == 0 )
		{
			PPRE1++;
			APB1Pre = APB1Pre >> 1;
		}
		PPRE1 +=3;
	}
	RCC->CFGR &=~ (0x7 << PPRE1_CLOCK_POS);
	RCC->CFGR |= (PPRE1 << PPRE1_CLOCK_POS);
	// APB2 Prescaler
	uint32 PPRE2 = 0 ;
	if(APB2Pre)
	{
		while((APB2Pre & 1) == 0 )
		{
			PPRE2 ++;
			APB2Pre = APB2Pre >> 1;

		}
		PPRE2 +=3;
	}
	RCC->CFGR &=~ (0x7 << PPRE2_CLOCK_POS);
	RCC->CFGR |= (PPRE2 << PPRE2_CLOCK_POS);
}

void HAL_RCC_SetSystemClockTo16Mhz(void)
{
	HAL_RCC_HSI_ON();
	RCC->CFGR |= HPRE_CLOCK_DIV_1 <<4;
	RCC->CFGR |= PPRE1_CLOCK_DIV1 <<10;
	RCC->CFGR |= PPRE2_CLOCK_DIV1 <<13;
	SET_BIT(RCC->CFGR,RCC_HSI_SW);
	while(!(RCC->CFGR & RCC_HSI_SWS));
	RCC->CR &=~ RCC_CR_HSEON;
}
void HAL_RCC_SetSystemClockTo8Mhz(void)
{
		HAL_RCC_HSE_ON();
		RCC->CFGR |= HPRE_CLOCK_DIV_1 <<4;
		RCC->CFGR |= PPRE1_CLOCK_DIV1 <<10;
		RCC->CFGR |= PPRE2_CLOCK_DIV1 <<13;
		CLR_BIT(RCC->CFGR,RCC_HSE_SW);
		while(!(RCC->CFGR & RCC_HSE_SWS));
		RCC->CR &=~ RCC_CR_HSION;
}

static void HAL_RCC_HSE_ON()
{
	RCC->CR |= RCC_CR_HSEON;
	while(RCC->CR & RCC_CR_HSERDY);
}

static void HAL_RCC_HSI_ON()
{
	RCC->CR |= RCC_CR_HSION;
	while(RCC->CR & RCC_CR_HSION);
}

static void HAL_RCC_PLL_ON()
{
	RCC->CR |= RCC_CR_PLL;
	while(RCC->CR & RCC_CR_PLLRDY);
}

uint32 HAL_RCC_SET_PLL_CLOCK()
{
	uint32 PLL_SRC = 0;
	uint32 PLL_CLOCK_SPEED;
	if(RCC->PLLCFGR & (1U<<22))
	{
		PLL_SRC = HSECLOCKSPEED;
	}
	else
	{
		PLL_SRC = HSICLOCKSPEED;
	}

	return PLL_CLOCK_SPEED;

}
/////////////////////////////

void HAL_GPIOA_ENABLE_CLOCK()
{
	RCC->AHB1ENR |= RCC_GPIOAENR;
}

void HAL_GPIOB_ENABLE_CLOCK()
{
	RCC->AHB1ENR |= RCC_GPIOBENR;
}
void HAL_GPIOC_ENABLE_CLOCK()
{
	RCC->AHB1ENR |= RCC_GPIOCENR;
}
void HAL_GPIOD_ENABLE_CLOCK()
{
	RCC->AHB1ENR |= RCC_GPIODENR;
}
void HAL_GPIOE_ENABLE_CLOCK()
{
	RCC->AHB1ENR |= RCC_GPIOEENR;
}
void HAL_GPIOH_ENABLE_CLOCK()
{
	RCC->AHB1ENR |= RCC_GPIOHENR;
}

////////
void HAL_TIM1_ENNABLE_CLOCK()
{
	RCC->APB2ENR |= RCC_TIM1ENR;
}

void HAL_TIM2_ENNABLE_CLOCK()
{
	RCC->APB1ENR |= RCC_TIM2ENR;
}
void HAL_TIM3_ENNABLE_CLOCK()
{
	RCC->APB1ENR |= RCC_TIM3ENR;
}
void HAL_TIM4_ENNABLE_CLOCK()
{
	RCC->APB1ENR |= RCC_TIM4ENR;
}

void HAL_TIM5_ENNABLE_CLOCK()
{
	RCC->APB1ENR |= RCC_TIM5ENR;
}

void HAL_TIM9_ENNABLE_CLOCK()
{
	RCC->APB2ENR |= RCC_TIM9ENR;
}
void HAL_TIM10_ENNABLE_CLOCK()
{
	RCC->APB2ENR |= RCC_TIM10ENR;
}
void HAL_TIM11_ENNABLE_CLOCK()
{
	RCC->APB2ENR |= RCC_TIM11ENR;
}
