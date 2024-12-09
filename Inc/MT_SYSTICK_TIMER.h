/*
 * MT_SYSTICK_TIMER.h
 *
 *  Created on: Dec 9, 2024
 *      Author: hi
 */

#ifndef MT_SYSTICK_TIMER_H_
#define MT_SYSTICK_TIMER_H_

#include <std_type.h>
#define SYSTICK_BASE_ADDRESS	0xE000E010



typedef struct systick
{
	volatile uint32 CTRL; //0xE000E010
	volatile uint32 LOAD; //0xE00E014
	volatile uint32 VAL; //0xE000E018
	volatile uint32 CALIB; //0xE000E01C
}Systick_t;

#define Systick	((volatile Systick_t *)SYSTICK_BASE_ADDRESS)

void Systick_init();
void MT_delay(uint32 );

void Systick_init()
{
	Systick->CTRL = 0;
	Systick->LOAD = 0x00FFFFFF;
	Systick->VAL = 0;
	Systick->CTRL |=0x05;
}

void MT_delayMillis(uint32 time)
{
	for(;time>0;time--)
	{
	Systick ->LOAD = 15999;
	Systick ->VAL =0;
	while(!(Systick->CTRL & 0x00010000));
	}
}

#endif /* MT_SYSTICK_TIMER_H_ */
