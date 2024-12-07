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

typedef struct
{
	volatile uint32 UART_SR;
	volatile uint32 UART_DR;
	volatile uint32 UART_BRR;
	volatile uint32 UART_CR1;
	volatile uint32 UART_CR2;
	volatile uint32 UART_CR3;
	volatile uint32 UART_GTDR;
}UART_t;

#define UART1	((volatile UART_t *)(UART1_ADDRESS_BASE))
#define UART2	((volatile UART_t *)(UART2_ADDRESS_BASE))
#define UART6	((volatile UART_t *)(UART6_ADDRESS_BASE))


#endif /* HAL_STM32F411_UART_H_ */
