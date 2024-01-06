/*******************************************/
/*		Author	: Pola Magdy			   */
/*		Version	: V01					   */
/*		Date	: 12/11/2023		 	   */
/*     Description: EXTI_Private.h    	   */
/*******************************************/
#ifndef _EXTI_PRIVATE_H
#define _EXTI_PRIVATE_H

typedef struct{
	
	volatile u32 EVCR;
	volatile u32 MAPR;
	volatile u32 EXTICR[4];
	volatile u32 MAPR2;
	
}AFIO_t;

#define AFIO   ((volatile AFIO_t*) 0x40010000)

#endif