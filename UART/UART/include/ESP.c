/*==================================================================================*
 * File        : ESP.h     												
 * Description : This file includes ESP Driver prototypes 				
 * Author      : 							
 * Date        : 																										*
 * version     : 1 v                                                           	    
 *==================================================================================*/
#include "ESP.h"
#include "UART_INTERFACE.h"

void ESP_voidInit(void)
{
	u8 Local_u8Result = 0;
	
	while(Local_u8Result == 0)
	{
		/* Stop ECHO */
		MUART_voidSendStringSynch(UART1,"ATE0\r\n");
		Local_u8Result = Esp_voidValidateCmd();
		MUART_voidReceiveStringSynch(UART1,&Ack );
	}
	
	Local_u8Result = 0;
	
	while(Local_u8Result == 0)
	{
		/* Set station mode */
		MUART_voidSendStringSynch("AT+CWMODE=1\r\n");
		Local_u8Result = Esp_voidValidateCmd();
	}
}
void ESP_connectWifi(void)
{
		u8 Local_u8Result = 0;
	
	while(Local_u8Result == 0)
	{
		/* Stop ECHO */
		MUART_voidSendStringSynch(UART1,"AT+CWJAP_CUR=\"Gamal\",\"G01005525506\"\r\n");
		Local_u8Result = Esp_voidValidateCmd();
	}
}
void ESP_connectServer(void)
{
	u8 Local_u8Result = 0;
	
	while(Local_u8Result == 0)
	{
		/* Stop ECHO */
		MUART_voidSendStringSynch(UART1,"AT+CIPSTART=\"TCP\",\"185.176.43.108\",80\r\n");
		Local_u8Result = Esp_voidValidateCmd();
	}
}
void ESP_ReciveHTTPRequest(u8 *Ptr_u8Data)
{
	u8 Local_u8Result = 0;
	
	while(Local_u8Result == 0)
	{
		/* Send length of Get command */
		MUART_voidSendStringSynch(UART1,"AT+CIPSTART=55\r\n");
		
		Local_u8Result = Esp_voidValidateCmd();
		
	}
	MUART_voidSendStringSynch(UART1,"GET http://ntigreaters.scienceontheweb.net/status.txt\r\n");
	MUART_voidReceiveStringSynch(UART1,Ptr_u8Data);
	
}
u8 Esp_voidValidateCmd(void)
{
	u8 Local_u8Response[100] = {0};
	u8 i = 0;
	u8 Ack = 0;
	u8 Result = 0;
	
	while (Ack != 255)
	{
		MUART_voidReceiveStringSynch(UART1,&Ack );
		Local_u8Response[i] = Ack;
		i++;
	}
	
	/* Check if Ok */
	if (Local_u8Response[0] == 'O' && Local_u8Response[1] == 'K')
	{
		Result = 1;
	}
	
	return Result;
}

