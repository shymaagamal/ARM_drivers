/*********************************************************************************************************************************************
 * Author       :      Shaimaa G.Salem
 * Date         :      6 Nov 2023
 * Version      :      v01
*********************************************************************************************************************************************/


#ifndef INC_NVIC_PRIVATE_H_
#define INC_NVIC_PRIVATE_H_

#include "STD_TYPES.h"
#define NVIC_BASE_ADDRESS		0xE000E100


#define NVIC_ISER0				*((volatile u32*) (NVIC_BASE_ADDRESS+0x000))/*Enable External Interrupt from 0 -> 31*/
#define NVIC_ISER1				*((volatile u32*) (NVIC_BASE_ADDRESS+0x004))/*Enable External Interrupt from 32 -> 63*/

#define NVIC_ICER0				*((volatile u32*) (NVIC_BASE_ADDRESS+0x080))/*Disable External Interrupt from 0 -> 31*/
#define NVIC_ICER1				*((volatile u32*) (NVIC_BASE_ADDRESS+0x084))/*Disable External Interrupt from 32 -> 63*/

#define NVIC_ISPR0  			*((volatile u32*) (NVIC_BASE_ADDRESS+0x100))/*Set Pending Flag from 0 -> 31*/
#define NVIC_ISPR1				*((volatile u32*) (NVIC_BASE_ADDRESS+0x104))/*Set Pending Flag from 32 -> 63*/

#define NVIC_ICPR0  			*((volatile u32*) (NVIC_BASE_ADDRESS+0x180))/*Clear Pending Flag from 0 -> 31*/
#define NVIC_ICPR1				*((volatile u32*) (NVIC_BASE_ADDRESS+0x184))/*Clear Pending Flag from 32 -> 63*/

#define NVIC_IABR0  			*((volatile u32*) (NVIC_BASE_ADDRESS+0x200))/*Return Active Flag from 0 -> 31*/
#define NVIC_IABR1				*((volatile u32*) (NVIC_BASE_ADDRESS+0x204))/*Return Pending Flag from 32 -> 63*/

#define NVIC_IPR		  		((volatile u8 *)0xE000E100 + 0x300)

#define SCB_AIRCR				 *((volatile u32*)0xE000ED00 + 0x0C)

#define GROUP3					0X05FA0300 //4 bit for group in IPR
#define GROUP4					0X05FA0400//3 bits for group and 1 bit for sub in IPR
#define GROUP5					0X05FA0500//2 bits for group and 2 bit for sub in IPR
#define GROUP6					0X05FA0600//1 bit for group and 3 bit for sub in IPR
#define GROUP7					0X05FA0700 //0 bit for group 4 bit for sub in IPR
#endif /* INC_NVIC_PRIVATE_H_ */
