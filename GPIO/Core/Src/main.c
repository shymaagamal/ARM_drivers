/*********************************************************************************************************************************************
 * Author       :      Shaimaa G.Salem
 * Date         :      5 Nov 2023
 * Version      :      v01
*********************************************************************************************************************************************/


#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"


#include "DMA_interface.h"

#define PORTA_CLK_PIN	2
void LED();
u8 flag=0;
void main(void)
{

	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,PORTA_CLK_PIN);

	GPIO_voidSetPinDirection(PORTA_ID, 0, OUTPUT_SPEED2HZ_PUSH_PULL);

	GPIO_voidSetPinValue(PORTA_ID, 0, LOGIC_LOW);

//	u32 x = 0;
//	u32 y = 1;
//
//	DMA_voidInit(1);
//    DMA_voidChannelStart(1, &y, &x, 4);

//	STK_voidInit();
//	SysTik_init(AHB_NO_PRESCALE);

//	STK_voidSetIntervalSingle(10000,&LED);
	//STK_voidSetIntervalPeriodic(10000, LED);
	while(1)
	{
		GPIO_voidSetPinValue(PORTA_ID, 0, 1);

	}
}

void LED()
{
	GPIO_voidSetPinValue(PORTA_ID, 0, LOGIC_HIGH);

}
