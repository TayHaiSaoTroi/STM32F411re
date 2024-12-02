/*
 * std_type.h
 *
 *  Created on: Nov 12, 2024
 *      Author: Admins
 */

#ifndef STD_TYPE_H_
#define STD_TYPE_H_
#include <stdio.h>

#define HIGH 	(0x01U)
#define LOW		(0x00U)
#define TRUE 	(0x01U)
#define FALSE	(0x00U)

#define GPIO_PIN_SET 1
#define GPIO_PIN_RESET 0

typedef signed char int8;
typedef signed short int16;
typedef signed int int32;
typedef signed long long int64;

typedef float float32;
typedef double float64;

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;
typedef unsigned long long uint64;


typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;

typedef signed char s8;
typedef signed short s16;
typedef signed long s32;
typedef signed long long s64;

typedef float f32;
typedef double f64;

#endif /* STD_TYPE_H_ */
