/*
 * Bit_math.h
 *
 *  Created on: Nov 12, 2024
 *      Author: Admins
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_
#include <stdio.h>
#define SET_BIT(var,bit)    ((var) |=  (1<<bit))
#define CLR_BIT(var,bit)	((var) &= ~(1<<bit))

#define GET_BIT(var,bit)	((var >> bit)  & 1)

#endif /* BIT_MATH_H_ */
