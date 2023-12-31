
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_Interface.h"
#include "GPIO_Private.h"
#include "GPIO_Config.h"

 const MODE_CNF_t DIO_PinsStatusArr[TOTAL_PINS]={
		 OUTPUT2KHZ_PUSHPALL,      /* Port A Pin 0 */
		 OUTPUT2KHZ_PUSHPALL,      /* Port A Pin 1 */
		 OUTPUT2KHZ_PUSHPALL,      /* Port A Pin 2 */
		 OUTPUT2KHZ_PUSHPALL,      /* Port A Pin 3 */
		 OUTPUT2KHZ_PUSHPALL,      /* Port A Pin 4 */
		 OUTPUT2KHZ_PUSHPALL,      /* Port A Pin 5 */
		 OUTPUT2KHZ_PUSHPALL,      /* Port A Pin 6 */
		 OUTPUT2KHZ_PUSHPALL,      /* Port A Pin 7 */
		 OUTPUT2KHZ_PUSHPALL,      /* Port A Pin 8 */
		 OUTPUT2KHZ_PUSHPALL,      /* Port A Pin 9 */
		 OUTPUT2KHZ_PUSHPALL,      /* Port A Pin 10 */
		 OUTPUT2KHZ_PUSHPALL,     /* Port A Pin 11 */
		 OUTPUT2KHZ_PUSHPALL,      /* Port A Pin 12 */
		 OUTPUT2KHZ_PUSHPALL,      /* Port A Pin 13 */
		 OUTPUT2KHZ_PUSHPALL,      /* Port A Pin 14 */
		 OUTPUT2KHZ_PUSHPALL,      /* Port A Pin 15 */

		 OUTPUT2KHZ_PUSHPALL,      /* Port B Pin 0 */
		 OUTPUT2KHZ_PUSHPALL,      /* Port B Pin 1 */
		 OUTPUT2KHZ_PUSHPALL,      /* Port B Pin 2 */
		 OUTPUT2KHZ_PUSHPALL,      /* Port B Pin 3 */
		 OUTPUT2KHZ_PUSHPALL,      /* Port B Pin 4 */
		 OUTPUT2KHZ_PUSHPALL,      /* Port B Pin 5 */
		 OUTPUT2KHZ_PUSHPALL,      /* Port B Pin 6 */
		 OUTPUT2KHZ_PUSHPALL,      /* Port B Pin 7 */
		 OUTPUT2KHZ_PUSHPALL,      /* Port B Pin 8 */
		 OUTPUT2KHZ_PUSHPALL,      /* Port B Pin 9 */
		 OUTPUT2KHZ_PUSHPALL,      /* Port B Pin 10 */
		 OUTPUT2KHZ_PUSHPALL,      /* Port B Pin 11 */
		 OUTPUT2KHZ_PUSHPALL,      /* Port B Pin 12 */
		 OUTPUT2KHZ_PUSHPALL,      /* Port B Pin 13 */
		 OUTPUT2KHZ_PUSHPALL,      /* Port B Pin 14 */
		 OUTPUT2KHZ_PUSHPALL,      /* Port B Pin 15 */

		  OUTPUT2KHZ_PUSHPALL,      /* Port C Pin 13 */
		  OUTPUT2KHZ_PUSHPALL,      /* Port C Pin 14*/
		  OUTPUT2KHZ_PUSHPALL,      /* Port C Pin 15 */
};


void DIO_Init(void)
{
	Pin_t i ;

	for (i=PINA0;i<16;i++)
	{
		GPIO_SetPinDirection(PA,i,DIO_PinsStatusArr[i]);
	}
	for (i=PINB0;i<32;i++)
	{
		GPIO_SetPinDirection(PB,(i%PORTB_B0),DIO_PinsStatusArr[i]);
	}
	for (i=PINC13;i<35;i++)
	{
		GPIO_SetPinDirection(PC,(i-PORTB_C13),DIO_PinsStatusArr[i]);
	}
}

void GPIO_SetPinDirection(Port_t port,Pin_t pin,MODE_CNF_t mode)
{
	switch(port)
	{
	case PA:
		if (pin<8)
		{
			GPIOA_CRL&=~((0b1111)<<(pin*4));
			GPIOA_CRL|= ((mode)<<(pin*4));

		}
		else if (pin<=15&&pin>7)
				{
			        pin=pin-8;
					GPIOA_CRH&=~((0b1111)<<(pin*4));
					GPIOA_CRH|= ((mode)<<(pin*4));
				}
		break;
	case PB:
			if (pin<8)
			{
				GPIOB_CRL&=~((0b1111)<<(pin*4));
				GPIOB_CRL|= ((mode)<<(pin*4));

			}
			else if (pin<=15&&pin>7)
					{
				        pin=pin-8;
						GPIOB_CRH&=~((0b1111)<<(pin*4));
						GPIOB_CRH|= ((mode)<<(pin*4));
					}
			break;
	case PC:
			if (pin<8)
			{
				GPIOC_CRL&=~((0b1111)<<(pin*4));
				GPIOC_CRL|= ((mode)<<(pin*4));

			}
			else if (pin<=15&&pin>7)
					{
				        pin=pin-8;
						GPIOC_CRH&=~((0b1111)<<(pin*4));
						GPIOC_CRH|= ((mode)<<(pin*4));
					}
			break;
	default:break;
	}
}

void GPIO_SetPinValue(Pin_t pin,Pin_Value_t value)
{
	Port_t port=PA;
	if( pin<PINB0)
	{
		port=PA;
	}
	else if(pin>=PINB0 && pin<=PINB15)
		{
			port=PB;
			pin=pin-PORTB_B0;
		}
	else if (pin>=PINC13 && pin<=PINC15)
		{
			port=PC;
			pin=pin-PORTB_C13;
		}
	switch(port)
		{
		case PA:
			if (value==HIGH)
			{
				SIT_BIT(GPIOA_ODR,pin);
			}
			else if (value==LOW)
			{
				CLR_BIT(GPIOA_ODR,pin);
			}
			break;
		case PB:
					if (value==HIGH)
					{
						SIT_BIT(GPIOB_ODR,pin);
					}
					else if (value==LOW)
					{
						CLR_BIT(GPIOB_ODR,pin);
					}
					break;
		case PC:
					if (value==HIGH)
					{
						SIT_BIT(GPIOC_ODR,pin);
					}
					else if (value==LOW)
					{
						CLR_BIT(GPIOC_ODR,pin);
					}
					break;
		default:break;

}
}
void GPIO_TogPin(Pin_t pin)
{
	Port_t port=PA;
		if( pin<PINB0)
		{
			port=PA;
		}
		else if(pin>=PINB0 && pin<=PINB15)
			{
				port=PB;
				pin=pin-PORTB_B0;
			}
		else if (pin>=PINC13 && pin<=PINC15)
			{
				port=PC;
				pin=pin-PORTB_C13;
			}
	switch (port)
	{
	case PA:
			if (pin<8)
			{
				TOG_BIT(GPIOA_ODR,pin);
			}
			else if (pin<=15&&pin>7)
					{
				       TOG_BIT(GPIOA_ODR,pin);
					}
			break;
	case PB:
				if (pin<8)
				{
					TOG_BIT(GPIOB_ODR,pin);
				}
				else if (pin<=15&&pin>7)
						{
					       TOG_BIT(GPIOB_ODR,pin);
						}
				break;
	case PC:
				if (pin<8)
				{
					TOG_BIT(GPIOC_ODR,pin);
				}
				else if (pin<=15&&pin>7)
						{
					       TOG_BIT(GPIOC_ODR,pin);
						}
				break;

	}
}

u8 GPIO_GetPinValue(Pin_t  pin)
{
	u8 read=0;
	Port_t port=PA;
			if( pin<PINB0)
			{
				port=PA;
			}
			else if(pin>=PINB0 && pin<=PINB15)
				{
					port=PB;
					pin=pin-PORTB_B0;
				}
			else if (pin>=PINC13 && pin<=PINC15)
				{
					port=PC;
					pin=pin-PORTB_C13;
				}

	switch(port)
			{
			case PA:read=READ_BIT(GPIOA_IDR,pin);
				break;
			case PB:read=READ_BIT(GPIOB_IDR,pin);
				break;
			case PC:read=READ_BIT(GPIOC_IDR,pin);
				break;
			default:break;
			}
	return read;

}
void GPIO_SetPortDirection(Port_t port,MODE_CNF_t mode)
{
	u8 i=0;
	switch(port)
	{
	case PA:
		 if (i<8)
		 {
			 for (i=0;i<8;i++)
			 {
				 GPIO_SetPinDirection(port,i,mode);

			 }
		 }
		  if (i>=8&&i<16)
		 {
			 for (;i<16;i++)
			 	 {
			 		 GPIO_SetPinDirection(port,i,mode);

			      }
		 }
		 break;
	   case PB:
			 if (i<8)
			 {
				 for (i=0;i<8;i++)
				 {
					 GPIO_SetPinDirection(port,i,mode);

				 }
			 }
			  if (i>=8&&i<16)
			 {
				 for (;i<16;i++)
				 	 {
				 		 GPIO_SetPinDirection(port,i,mode);

				      }
			 }
			 break;
	case PC:
			 if (i<8)
			 {
				 for (i=0;i<8;i++)
				 {
					 GPIO_SetPinDirection(port,i,mode);

				 }
			 }
			   if (i>=8&&i<16)
			 {
				 for (;i<16;i++)
				 	 {
				 		 GPIO_SetPinDirection(port,i,mode);

				      }
			 }
			 break;
	     default:break;
	}
}
void GPIO_SetPortValue(Port_t port,u32 value)
{


	switch(port)
			{
			case PA: GPIOA_ODR=value;
				break;
			case PB: GPIOB_ODR=value;
			break;
			case PC:GPIOC_ODR=value;
								break;
			default:break;
			}

}

