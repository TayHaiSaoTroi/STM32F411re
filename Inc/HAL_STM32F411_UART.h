/*
 * HAL_STM32F411_UART.h
 *
 *  Created on: Dec 5, 2024
 *      Author: hi
 */

#ifndef HAL_STM32F411_UART_H_
#define HAL_STM32F411_UART_H_

#include "std_type.h"

#define UART1_ADDRESS_BASE	0x40011000
#define UART6_ADDRESS_BASE	0x40011400
#define UART2_ADDRESS_BASE	0x40004400

////Macro
#define UART_OVER8	(1<<15)
#define UART_ENR	(1<<13)
#define UART_WORLDLENGT		(1<<12)
#define UART_PARITY_ENR		(1<<10)
#define UART_PARITY_SEL		(1<<9)
#define UART_TX_ENR			(1<<3)
#define UART_RX_ENR			(1<<2)

#define UART_TRANSIMISSION 0U
#define UART_RECEPTION		1U
#define UART_TRANSIMISSION_RECEPTION	2U
///

typedef struct
{
	volatile uint32 SR; //0x00
	volatile uint32 DR; //0x04
	volatile uint32 BRR; //0x08
	volatile uint32 CR1; //0x0C
	volatile uint32 CR2; //0x10
	volatile uint32 CR3; //0x14
	volatile uint32 GTDR; //0x18
}UART_t;

typedef struct
{
	volatile uint32 Mode;
	volatile uint32 WorldLenght;
	volatile uint32 Baudrate;
	volatile uint32 Parity;
	volatile uint32 OverSampling;
}UART_Config_t;

#define UART1	((volatile UART_t *)(UART1_ADDRESS_BASE))
#define UART2	((volatile UART_t *)(UART2_ADDRESS_BASE))
#define UART6	((volatile UART_t *)(UART6_ADDRESS_BASE))

void HAL_STM32F411_UART_INIT(UART_t *UART_Typedef, UART_Config_t UART_Config);
void HAL_STM32F411_UART_TRANSIMISSION();
void HAL_STM32F411_UART_RECEPTION();


#endif /* HAL_STM32F411_UART_H_ */
