/*****************************************************************************************************************/
/* Auther :																										*/
/* Version :																										*/
/* Date :																										*/
/*****************************************************************************************************************/





void SPI1_voidInit(void); 

void SPI_voidSendReciveSync(u8 Copy_u8DataTransmit,u8* Copy_u8DataToRecive)
{
    /*Clear For Slave Select Pin*/

    GPIO_voidSetPinValue(SPI1_SLAVE_PIN,LOGIC_LOW);

    SPI->DR=Copy_u8DataTransmit;
    /*Wait Busy Flag*/
    while(GIT_BIT(SPI->SR,7) !=0);
    /*Return to the recived data*/
    Copy_u8DataToRecive=SPI->DR;

    /*Set For Slave Select Pin*/
    GPIO_voidSetPinValue(SPI1_SLAVE_PIN,LOGIC_HIGH);
}


void SPI_voidSendReciveASync(u8 Copy_u8DataTransmit,void(*CallBack)(u8));


