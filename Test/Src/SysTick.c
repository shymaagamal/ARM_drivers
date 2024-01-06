/***********************************************/
/*		Author  	: Pola Magdy			   */
/*		Version		: V01					   */
/*		Date		: 7/11/2023			 	   */
/*      Description : SysTick.c		           */
/***********************************************/
#include "Utils.h"
#include "StdTypes.h"
#include "SysTick_Private.h"
#include "SysTick_Interface.h"

void STK_Init(void)
{
	CLR_BIT(STK_CTRL,CLK_Source);		//clock source
}

void STK_Start(u32	Reload_Val)
{
	STK_LOAD = Reload_Val;

	//SET_BIT(STK_CTRL,STK_ENBL);			// Enable SysTick
}

void Busy(u32 Reload_Val)
{
	STK_VAL=0;
	STK_LOAD = (Reload_Val & 0X00FFFFFF);
	SET_BIT(STK_CTRL,STK_ENBL);			// Enable SysTick
	while(!READ_BIT(STK_CTRL,COUNT_FLAG));
	CLR_BIT(STK_CTRL,STK_ENBL);
	STK_LOAD=0;
	STK_VAL=0;
}

u32 STK_Read(void)
{
	return (STK_VAL & 0x00FFFFFF);	//Reading the current counting number
}
void STK_INT_EN(void)
{
	SET_BIT(STK_CTRL,TICKINT);		//Enable Interrupt and counter Flag becomes 1 after reaching to 0
}
void STK_INT_DIS(void)
{
	CLR_BIT(STK_CTRL,TICKINT);		//Disable Interrupt
}

