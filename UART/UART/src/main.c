

#include "RCC_Interface.h"
#include "GPIO_Interface.h"
#include "UART_INTERFACE.h"

#define uart    3
#if uart == 1
void main(void)
{
	RCC_InitClockSystem();
	RCC_EnableClock(APB2,IOPA);
	RCC_EnableClock(APB2 ,USART);

	GPIO_SetPinDirection(PA,PINA9,OUTPUT2KHZ_AF_PUSHPALL);
	GPIO_SetPinDirection(PA,PINA10,INPUT_FLOATING);

	MUART_voidInit(UART1);
	MUART_voidEnable(UART1);
	u8 *Ptr ;
	while(1)
	{

		//		MUART_voidSendStringSynch(UART1, Ptr);
		//		for(int i = 0 ; i < 1000000 ; i++)
		//		{
		//			asm("NOP");
		//		}

		MUART_voidSendCharSync(UART1,MUART_u8ReceiveCharSync(UART1));
		for(int i = 0 ; i < 1000000 ; i++)
		{
			asm("NOP");
		}
	}
}

#elif uart == 2
void main(void)
{
	RCC_InitClockSystem();
	RCC_EnableClock(APB2,IOPA);
	RCC_EnableClock(APB1 ,USART2_EN);

	GPIO_SetPinDirection(PA,PINA2,OUTPUT2KHZ_AF_PUSHPALL);
	GPIO_SetPinDirection(PA,PINA3,INPUT_FLOATING);

	MUART_voidInit(UART2);
	MUART_voidEnable(UART2);
	u8 *Ptr ;
	while(1)
	{

		//		MUART_voidSendStringSynch(UART1, Ptr);
		//		for(int i = 0 ; i < 1000000 ; i++)
		//		{
		//			asm("NOP");
		//		}

		MUART_voidSendCharSync(UART2,MUART_u8ReceiveCharSync(UART2));
		for(int i = 0 ; i < 1000000 ; i++)
		{
			asm("NOP");
		}
	}
}
#elif uart == 3
void main(void)
{
	RCC_InitClockSystem();
	RCC_EnableClock(APB2,IOPB);
	RCC_EnableClock(APB1 ,USART3_EN);

	GPIO_SetPinDirection(PB,PINA10,OUTPUT2KHZ_AF_PUSHPALL);
	GPIO_SetPinDirection(PB,PINA11,INPUT_FLOATING);

	MUART_voidInit(UART3);
	MUART_voidEnable(UART3);
	u8 *Ptr ;
	while(1)
	{

		//		MUART_voidSendStringSynch(UART1, Ptr);
		//		for(int i = 0 ; i < 1000000 ; i++)
		//		{
		//			asm("NOP");
		//		}

		MUART_voidSendCharSync(UART3,MUART_u8ReceiveCharSync(UART3));
		for(int i = 0 ; i < 1000000 ; i++)
		{
			asm("NOP");
		}
	}
}

#endif
