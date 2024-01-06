
#include "StdTypes.h"
#include "Utils.h"
#include "UART_Interface.h"
#include "ESP_Interface.h"
#include "ESP_Private.h"
#include "ESP_Cfg.h"
#include "SysTick_Interface.h"
void ESP_Init(void)
{
	u8 Result=0;
	/* stop ECHO  */

	while(Result==0)
	{
		MUART_voidSendStringSynch(UART2,(u8*)"AT\r\n");
		Result=ESP_ValidateCmd();
	}
		Result=0;
	/*Set Station mode */
	while(Result==0)
	{
		MUART_voidSendStringSynch(UART2,(u8*)"AT+CWMODE=1\r\n");
		Result=ESP_ValidateCmd();
	}
}
u8 Response[50]={0};
u8 ESP_ValidateCmd(void)
{

	u8 i=0;
	u8 Dummy=0;
	u8 Result=0;
	while (Dummy!=255)
	{
		Dummy= MUART_u8ReceiveCharSync(UART2);		//it must have timeout at least equals the execution time of command
		Response[i]=Dummy;
		i++;
	}
	if(Response[0] == 'O' && Response[1] == 'K')
	{
		Result=1;
	}
	return Result;
}

void ESP_connectWifi(void)
{
		u8 Local_u8Result = 0;

	while(Local_u8Result == 0)
	{
		/* Stop ECHO */
		MUART_voidSendStringSynch(UART1,(u8*)"AT+CWJAP_CUR=\"koko\",\"*koko12345678*\"\r\n");
		Local_u8Result = ESP_ValidateCmd();
	}
}
void ESP_connectServer(void)
{
	u8 Local_u8Result = 0;

	while(Local_u8Result == 0)
	{
		/* Stop ECHO */
		MUART_voidSendStringSynch(UART1,(u8*)"AT+CIPSTART=\"TCP\",\"185.176.43.108\",80\r\n");
		Local_u8Result = ESP_ValidateCmd();
	}
}
void ESP_ReciveHTTPRequest(u8 *Ptr_u8Data)
{
	u8 Local_u8Result = 0;

	while(Local_u8Result == 0)
	{
		/* Send length of Get command */
		MUART_voidSendStringSynch(UART1,(u8*)"AT+CIPSEND=55\r\n");

		Local_u8Result = ESP_ValidateCmd();

	}
	MUART_voidSendStringSynch(UART1,(u8*)"GET http://ntigreaters.scienceontheweb.net/status.txt\r\n");
	MUART_voidReceiveStringSynch(UART1,Ptr_u8Data);

}

