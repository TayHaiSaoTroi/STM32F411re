/*
 * HAL_RCC_STM32F411_FLASH.h
 *
 *  Created on: Dec 7, 2024
 *      Author: hi
 */

#ifndef HAL_STM32F411_FLASH_H_
#define HAL_STM32F411_FLASH_H_

#include "std_type.h"

#define FLASH_BASE_ADDRESS	0x40023C00


#define FLASH_ACR_LATENCY_0WS	(0U)
#define FLASH_ACR_LATENCY_1WS	(1U)
#define FLASH_ACR_LATENCY_2WS	(2U)
#define FLASH_ACR_LATENCY_3WS	(3U)
#define FLASH_ACR_LATENCY_4WS	(4U)
#define FLASH_ACR_LATENCY_5WS	(5U)
#define FLASH_ACR_LATENCY_6WS	(6U)
#define FLASH_ACR_LATENCY_7WS	(7U)
#define FLASH_ACR_LATENCY_8WS	(8U)
#define FLASH_ACR_LATENCY_9WS	(9U)
#define FLASH_ACR_LATENCY_10WS	(10U)
#define FLASH_ACR_LATENCY_11WS	(11U)
#define FLASH_ACR_LATENCY_12WS	(12U)
#define FLASH_ACR_LATENCY_13WS	(13U)
#define FLASH_ACR_LATENCY_14WS	(14U)
#define FLASH_ACR_LATENCY_15WS	(15U)

#define FLASH_ACR_PRFTEN	(1<<8)
#define FLASH_ACR_ICEN		(1<<9)
#define FLASH_ACR_DCEN		(1<<10)
#define FLASH_ACR_ICRST		(1<<11)
#define FLASH_ACR_DCRST		(1<<12)


typedef struct FLASH
{
	volatile uint32 ACR;
	volatile uint32 KEYR;
	volatile uint32 OPTKETR;
	volatile uint32 SR;
	volatile uint32 CR;
	volatile uint32 OPTCR;
}Flash_t;
#define FLASH	((volatile Flash_t *)FLASH_BASE_ADDRESS)


#endif /* HAL_STM32F411_FLASH_H_ */
