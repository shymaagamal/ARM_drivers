/** ========================= The file information ========================== */
/**
 *  Project: AVR_ATmega32_Driver
 *  File name: STD_Types.h
 *  Created on: Aug 12, 2023
 *  Author: ENG. Mahmoud Sayed
 **/
/** ========================================================================= */




/** ========================= The File Header Guard ========================= */
#ifndef LIB_STD_TYPES_H
#define LIB_STD_TYPES_H
/** ========================================================================= */




/** ====================== Defining The Standard Types ====================== */
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;
typedef unsigned long long int u64;

typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;
typedef signed long long int s64;

#define NULL (void *)0
/** ========================================================================= */

#define OK 			  0
#define NOK 		  1
#define NULL_POINTER  2
#define TIMEOUT_STATE 3
#define BUSY_STATE    4



#endif /* LIB_STD_TYPES_H */
/** ============================== END of File ============================== */
