/*
 * ETP_STM32F401_GPIO.h
 *
 *  Created on: Nov 14, 2024
 *      Author: Admins
 */

#ifndef HAL_STM32F411_GPIO_H_
#define HAL_STM32F411_GPIO_H_
#include "std_type.h"
#include "Bit_math.h"
#define GPIOA_ADDRESS		0x40020000
#define GPIOB_ADDRESS		0x40020400
#define GPIOC_ADDRESS		0x40020800
#define GPIOD_ADDRESS		0x40020C00
#define GPIOE_ADDRESS		0x40021000
#define GPIOH_ADDRESS		0x40021C00

//Macro GPIO PIN
#define GPIO_PIN_0			(0U)
#define GPIO_PIN_1			(1U)
#define GPIO_PIN_2			(2U)
#define GPIO_PIN_3			(3U)
#define GPIO_PIN_4			(4U)
#define GPIO_PIN_5			(5U)
#define GPIO_PIN_6			(6U)
#define GPIO_PIN_7			(7U)
#define GPIO_PIN_8			(8U)
#define GPIO_PIN_9			(9U)
#define GPIO_PIN_10			(10U)
#define GPIO_PIN_11			(11U)
#define GPIO_PIN_12			(12U)
#define GPIO_PIN_13			(13U)
#define GPIO_PIN_14			(14U)
#define GPIO_PIN_15			(15U)

// Macro GPIO Mode
#define GPIO_OUTPUT			(1U)
#define GPIO_INPUT			(0U)
#define GPIO_ALTERNATE		(2U)
#define GPIO_ANALOG			(3U)

//Macro GPIO Speed

#define LOW_SPEED			(0U)
#define MEDIUM_SPEED		(1U)
#define FAST_SPEED			(2U)
#define HIGH_SPEED			(3U)

//Macro GPIO Pull Up Pull Down
#define NO_PULL				(0U)
#define PULL_UP				(1U)
#define PULL_DOWN			(2U)

//Macro GPIO OTyper
#define OUPUT_PUSHPULL		(0U)
#define OUTPUT_OPENDRAIN	(1U)


typedef struct
{
	uint8 PinNumber;
	uint8 Mode;
	uint8 Speed;
	uint8 Pull_up_down;
	uint8 Otype;
	uint8 AltMode;
}GPIO_Config_t;



typedef struct
{
	volatile uint32 MODER;//0x00
	volatile uint32 OTYPER;//0x04
	volatile uint32 OSPEEDR;//0x08
	volatile uint32 PUPDR; //0x0C
	volatile uint32 IDR; //0x10
	volatile uint32 ODR;//0x14
	volatile uint32 BSRR; //0x18
	volatile uint32 LCKR; //0x1C
	volatile uint32 AFR[2]; //0x20,0x24
}GPIO_t;


#define GPIOA 	(( GPIO_t *)GPIOA_ADDRESS)
#define GPIOB	(( GPIO_t *)GPIOB_ADDRESS)
#define GPIOC	(( GPIO_t *)GPIOC_ADDRESS)
#define GPIOD	(( GPIO_t *)GPIOD_ADDRESS)
#define GPIOE	(( GPIO_t *)GPIOE_ADDRESS)
#define GPIOH	(( GPIO_t *)GPIOH_ADDRESS)
typedef struct
{
	GPIO_t *pGPIO;
	GPIO_Config_t GPIO_Config;
}GPIO_Typedef;
void GPIO_Init(GPIO_Typedef * GPIOx);
uint8 GPIO_ReadPin(GPIO_t *GPIOx, uint8 PinNumber);
void GPIO_WritePin(GPIO_t *GPIOx, uint8 PinNumber, uint8 State);
void GPIO_TogglePin(GPIO_t *GPIOx, uint8 PinNumber);

#endif /* HAL_STM32F411_GPIO_H_ */
