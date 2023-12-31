/*********************************************************************************************************************************************
 * Author       :      Shaimaa G.Salem
 * Date         :      5 Nov 2023
 * Version      :      v01
*********************************************************************************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"





void GPIO_voidSetPinDirection(u8 copy_u8PortId,u8 copy_u8PinNum,u8 copy_u8PinMood)
{
	switch(copy_u8PortId)
	{
	case PORTA_ID:

		if(copy_u8PinNum <=7)
		{
			GPIOA_CRL&=~((0b1111)<< (copy_u8PinNum *4));
			GPIOA_CRL |= ((copy_u8PinMood )<<(copy_u8PinNum *4));

		}
		else if(copy_u8PinNum <=15)
		{
			GPIOA_CRH&=~((0b1111)<< (copy_u8PinNum *4));
			GPIOA_CRH|=(copy_u8PinMood <<(copy_u8PinNum *4));
		}
		break;
	case PORTB_ID:
		if(copy_u8PinNum <=7)
		{
			GPIOB_CRL&=~((0b1111)<< (copy_u8PinNum *4));
			GPIOB_CRL|=(copy_u8PinMood <<(copy_u8PinNum *4));

		}
		else if(copy_u8PinNum <=15)
		{
			GPIOB_CRH&=~((0b1111)<< (copy_u8PinNum *4));
			GPIOB_CRH|=(copy_u8PinMood <<(copy_u8PinNum *4));
		}

		break;

	}
}
void GPIO_voidSetPinValue(u8 copy_u8PortId,u8 copy_u8PinNum,u8 copy_u8PinVal)
{
	switch(copy_u8PortId)
	{
	case PORTA_ID:
		if(copy_u8PinVal==LOGIC_LOW)
		{
			CLR_BIT(GPIOA_ODR,copy_u8PinNum);
		}
		else if(copy_u8PinVal==LOGIC_HIGH)
		{
			SET_BIT(GPIOA_ODR,copy_u8PinNum);

		}
		break;
	case PORTB_ID:
		if(copy_u8PinVal==LOGIC_LOW)
		{
			CLR_BIT(GPIOB_ODR,copy_u8PinNum);
		}
		else if(copy_u8PinVal==LOGIC_HIGH)
		{
			SET_BIT(GPIOB_ODR,copy_u8PinNum);

		}
		break;
	case PORTC_ID:
		if(copy_u8PinVal==LOGIC_LOW)
		{
			CLR_BIT(GPIOC_ODR,copy_u8PinNum);
		}
		else if(copy_u8PinVal==LOGIC_HIGH)
		{
			SET_BIT(GPIOC_ODR,copy_u8PinNum);

		}
		break;
	}

}
u8 GPIO_u8getPinValue(u8 copy_u8PortId,u8 copy_u8PinNum)
{
	u8 val=0;
	switch(copy_u8PortId)
	{
	case PORTA_ID:
		val=GET_BIT(GPIOA_IDR,copy_u8PinNum);
		break;
	case PORTB_ID:
		val=GET_BIT(GPIOB_IDR,copy_u8PinNum);
		break;
	case PORTC_ID:
		val=GET_BIT(GPIOC_IDR,copy_u8PinNum);
		break;
	}
	return val;
}
