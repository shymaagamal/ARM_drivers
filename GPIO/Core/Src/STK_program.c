/*********************************************************************************************************************************************
 * Author       :      Shaimaa G.Salem
 * Date         :      7 Nov 2023
 * Version      :      v01
 *********************************************************************************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"

#include "STK_interface.h"
#include "STK_config.h"
#include "STK_private.h"

void(*STK_pf)(void)=NULL;
u8 g_u8Interval=Interval_Periodic;
void STK_voidInit()
{
	CTRL_REG->ENABLE=1;
	CTRL_REG->CLKSOURCE=CLK_SRC_SELECTION;
	CTRL_REG->TICKINT=1;

}
void STK_voidSetBusyWait(u32 Copy_u32NumOfTicks)
{
	LOAD_REG=Copy_u32NumOfTicks;
	while(CTRL_REG->COUNTFLAG !=1);
}
void STK_voidSetIntervalSingle(u32 Copy_u32NumOfTicks, void(*Copy_pf)(void))
{
	if(Copy_pf!=NULL)
		{
	LOAD_REG=Copy_u32NumOfTicks;
	STK_pf=Copy_pf;
	g_u8Interval=Interval_SIGNAL;
		}
}
void STK_voidSetIntervalPeriodic(u32 Copy_u32NumOfTicks, void(*Copy_pf)(void))
{

	if(Copy_pf!=NULL)
	{
		LOAD_REG=Copy_u32NumOfTicks;
		//GPIO_voidSetPinValue(PORTA_ID, 0, LOGIC_HIGH);
		STK_pf=Copy_pf;
		g_u8Interval=Interval_Periodic;
	}


}
void STK_voidStopTimer()
{
	CTRL_REG->ENABLE=0;
	LOAD_REG=0;
	VAL_REG=0;
}
u32 STK_u32GetElabsedTime(u32* Copy_pu32ElapsedTime)
{
	Copy_pu32ElapsedTime=LOAD_REG;
	return Copy_pu32ElapsedTime;
}
u32 STK_u32GetRemainingTime(u32* Copy_pu32RemainingTime)
{
	Copy_pu32RemainingTime=VAL_REG-LOAD_REG;
	return Copy_pu32RemainingTime;
}
void SysTick_Handler(void)
{
	u8 local_readFlag=CTRL_REG->COUNTFLAG;


	if(g_u8Interval==Interval_SIGNAL)
	{
		GPIO_voidSetPinValue(PORTA_ID, 0, LOGIC_HIGH);

		if(STK_pf!=NULL)
		{
			//GPIO_voidSetPinValue(PORTA_ID, 0, LOGIC_HIGH);
			STK_pf();
			STK_voidStopTimer();
		}
	}
	else//(g_u8Interval==Interval_Periodic)
	{
		//GPIO_voidSetPinValue(PORTA_ID, 0, LOGIC_HIGH);
		if(STK_pf!=NULL)
		{
			STK_pf();
		}
	}
}
