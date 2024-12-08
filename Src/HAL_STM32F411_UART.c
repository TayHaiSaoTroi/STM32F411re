/*
 * HAL_STM32F411_UART.c
 *
 *  Created on: Dec 7, 2024
 *      Author: hi
 */


#include <HAL_STM32F411_UART.h>

void HAL_STM32F411_UART_INIT(UART_t *UART_Typedef, UART_Config_t UART_Config)
{
	if(UART_Config.Mode == UART_TRANSIMISSION)
	{
		UART_Typedef ->CR1 &=~ (1<< UART_TX_ENR);
		UART_Typedef ->CR1 |= (1<<UART_TX_ENR);
	}
}
