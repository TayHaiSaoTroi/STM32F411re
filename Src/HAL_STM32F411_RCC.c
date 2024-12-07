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


static void HAL_RCC_CALCULATE_SCALER(uint32 PLL_M[],uint32 PLL_N[],uint32 PLL_P[] , uint32 SysClk)
{


	 // find consistent number to config clock - M,N,P
			for( uint32 index1 = 0 ; index1 < (sizeof(PLL_N)/sizeof(PLL_N[0])) ; index1++ )
			{
				for(uint32 index2 = 0 ; index2 < (sizeof(PLL_M)/sizeof(PLL_M[0])); index2++)
				{
					for(uint32 index3 = 0 ; index3 < (sizeof(PLL_P)/sizeof(PLL_P[0])); index3++)
					{
						if( PLL_CLOCK / PLL_M[index2] * PLL_N[index1] / PLL_P[index3] == SysClk)
							return;
					}
				}
			}
}

void HAL_RCC_SetSystemClockByPLL(uint32 SysClk, uint32 AHBPre, uint32 APB1Pre, uint32 APB2Pre)
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
	/////////////
	uint32 PLL_P[] = {2,4,5,8};

		uint32 PLL_Q[] = {2,3,4,5,6,7,8,9,10,11,12,13,14,15};

		uint32 PLL_M[] = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,\
							25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,\
							45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63};\

		uint32 PLL_N[] = {50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63,
				64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80,
				81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97,
				98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111,
				112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125,
				126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139,
				140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153,
				154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167,
				168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181,
				182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195,
				196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209,
				210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223,
				224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237,
				238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251,
				252, 253, 254, 255, 256, 257, 258, 259, 260, 261, 262, 263, 264, 265,
				266, 267, 268, 269, 270, 271, 272, 273, 274, 275, 276, 277, 278, 279,
				280, 281, 282, 283, 284, 285, 286, 287, 288, 289, 290, 291, 292, 293,
				294, 295, 296, 297, 298, 299, 300, 301, 302, 303, 304, 305, 306, 307,
				308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 318, 319, 320, 321,
				322, 323, 324, 325, 326, 327, 328, 329, 330, 331, 332, 333, 334, 335,
				336, 337, 338, 339, 340, 341, 342, 343, 344, 345, 346, 347, 348, 349,
				350, 351, 352, 353, 354, 355, 356, 357, 358, 359, 360, 361, 362, 363,
				364, 365, 366, 367, 368, 369, 370, 371, 372, 373, 374, 375, 376, 377,
				378, 379, 380, 381, 382, 383, 384, 385, 386, 387, 388, 389, 390, 391,
				392, 393, 394, 395, 396, 397, 398, 399, 400, 401, 402, 403, 404, 405,
				406, 407, 408, 409, 410, 411, 412, 413, 414, 415, 416, 417, 418, 419,
				420, 421, 422, 423, 424, 425, 426, 427, 428, 429, 430, 431, 432};

	HAL_RCC_CALCULATE_SCALER (PLL_M, PLL_N, PLL_P, SysClk);
	/////////////

	RCC->PLLCFGR &=~ (0xF << RCC_CFGR_PLLQ) | (0x3 <<RCC_CFGR_PLLP) | (0x3F << RCC_CFGR_PLLM)
			| (0x1FF << RCC_CFGR_PLLN);
	RCC->PLLCFGR |= (0xF << RCC_CFGR_PLLQ) | (0x3 <<RCC_CFGR_PLLP) | (0x3F << RCC_CFGR_PLLM)
	| (0x1FF << RCC_CFGR_PLLN);
	////////////////
	RCC->PLLCFGR &=~ (0x3 << 22);
#if HSE_CLOCK_ENABLE

	RCC->PLLCFGR |= RCC_PLLCFGR_SRC_HSE;
#else
	RCC->PLLCFGR |= RCC_PLLCFGR_SRC_HSI;
#endif
	HAL_RCC_PLL_ON();
	RCC->CFGR |= RCC_PLL_SWS;
	while((RCC->CFGR & RCC_PLL_SWS) != RCC_PLL_SWS);
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
