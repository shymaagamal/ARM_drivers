/******************************************/
/*		Author	   : Pola Magdy			  */
/*		Version	   : V01				  */
/*		Date	   : 5/11/2023			  */
/*      Description: DIO_Private.h	      */
/******************************************/


#ifndef SYSTICK_PRIVATE_H_
#define SYSTICK_PRIVATE_H_


//#define	SysTick		*((volatile u32*) 0xE000E010)

#define STK_CTRL	*((volatile u32*) (0xE000E010	    ))
#define STK_LOAD	*((volatile u32*) (0xE000E010 + 0x04))
#define STK_VAL		*((volatile u32*) (0xE000E010 + 0x08))
#define STK_CALIB	*((volatile u32*) (0xE000E010 + 0x0C))


#endif /* SYSTICK_PRIVATE_H_ */
