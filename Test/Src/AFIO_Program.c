/*******************************************/
/*		Author	: Pola Magdy			   */
/*		Version	: V01					   */
/*		Date	: 12/11/2023		 	   */
/*     Description: EXTI_Program.c    	   */
/*******************************************/

#include "StdTypes.h"
#include "Utils.h"
#include "AFIO_Private.h"
#include "AFIO_Interface.h"



void AFIO_EXTI_CFG(u8 Line, u8 PortMap)
{
	u8 Reg_Index=0;
	if(Line>3 && Line<=7)
	{
		Reg_Index=1;
		Line-=4;
	}
	else if(Line<=11)
	{
		Reg_Index=2;
		Line-=8;
	}
	else if(Line<=15)
	{
		Reg_Index=3;
		Line-=12;
	}
	//AFIO->EXTICR[Reg_Index] (&~=((0b1111)<<(Line*4)));
	AFIO->EXTICR[Reg_Index] |=((PortMap)<<(Line*4));
}
