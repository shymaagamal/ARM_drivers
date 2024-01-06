/*****************************************************************************************************************/
/* Auther :																										*/
/* Version :																										*/
/* Date :																										*/
/*****************************************************************************************************************/

#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H







void SPI1_voidInit(void);
void SPI_voidSendReciveSync(u8 Copy_u8DataTransmit,u8* Copy_u8DataToRecive);


void SPI_voidSendReciveASync(u8 Copy_u8DataTransmit,void(*CallBack)(u8));





#endif