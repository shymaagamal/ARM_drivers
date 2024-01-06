/***********************************************/
/*		Author  	: Pola Magdy			   */
/*		Version		: V01					   */
/*		Date		: 7/11/2023			 	   */
/*      Description : SysTick_Interface.h      */
/***********************************************/

#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_


#define		AHB_8		0
#define		AHB			1


#define 	STK_ENBL	0
#define		TICKINT		1
#define		CLK_Source	2
#define		COUNT_FLAG	16



void STK_Init(void);

void STK_Start(u32	Reload_Val);
void Busy(u32 Reload_Val);
u32 STK_Read(void);

void STK_INT_EN(void);

void STK_INT_DIS(void);

#endif /* SYSTICK_INTERFACE_H_ */
