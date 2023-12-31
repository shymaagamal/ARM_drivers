/*********************************************************************************************************************************************
 * Author       :      Shaimaa G.Salem
 * Date         :      7 Nov 2023
 * Version      :      v01
*********************************************************************************************************************************************/


#include"STD_Types.h"
#include "BIT_Math.h"
#include "DMA_config.h"
#include "DMA_private.h"
#include "DMA_interface.h"


void DMA_voidInit(u8 copy_u8ChannelId)
{

#if(DATA_TRANSFER_DIRECTION==PERIPERAL_SOURCE_MEMORY_DESTINATION)
	DMA_REG->channel[copy_u8ChannelId]->CCR->DIR=0;
#elif(DATA_TRANSFER_DIRECTION==MEMORY_SOURCE_PERIPERAL_DESTINATION)
	DMA_REG->channel[copy_u8ChannelId]->CCR->DIR=1;
#elif(DATA_TRANSFER_DIRECTION==MEMORY_TO_MEMORY_ENABLED)
	DMA_REG->channel[copy_u8ChannelId]->CCR->MEM2MEM=1;

#elif(DATA_TRANSFER_DIRECTION==MEMORY_TO_MEMORY_DISABLED)
	DMA_REG->channel[copy_u8ChannelId]->CCR->MEM2MEM=0;
#endif

DMA_REG->channel[copy_u8ChannelId]->CCR->MSIZE=CHANNEL_MEMORY_SIZE;
DMA_REG->channel[copy_u8ChannelId]->CCR->PL=CHANNEL_PRIORITY_LEVEL;
DMA_REG->channel[copy_u8ChannelId]->CCR->PSIZE=CHANNEL_PERIPHERAL_SIZE;

DMA_REG->channel[copy_u8ChannelId]->CCR->MINC=MEMORY_INCREMENT_MODE;
DMA_REG->channel[1]->CCR->PINC=PERIPHERAL_INCREMENT_MODE;
DMA_REG->channel[1]->CCR->CIRC=CIRCULAR_MODE;

DMA_REG->channel[1]->CCR->TEIE=TRANSFER_ERROR_INTERRUPT_ENABLE;
DMA_REG->channel[1]->CCR->HTIE=HALF_TRANSFER_INTERRUPT_ENABLE;
DMA_REG->channel[1]->CCR->TCIE=COMPLETE_TRANSFER_INTERRUPT_ENABLE;


}


void DMA_voidChannelStart(u8 copy_u8ChannelId,u32* Copy_pu32SourceAddress, u32* Copy_pu32DestinationAddress, u16 Copy_u16BlockLength)
{

	DMA_REG->channel[copy_u8ChannelId]->CPAR=Copy_pu32SourceAddress;

	DMA_REG->channel[copy_u8ChannelId]->CMAR=Copy_pu32DestinationAddress;

	DMA_REG->channel[copy_u8ChannelId]->CNDTR=Copy_u16BlockLength;

	DMA_REG->channel[copy_u8ChannelId]->CCR->EN=1;



}
