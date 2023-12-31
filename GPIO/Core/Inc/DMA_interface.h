/*********************************************************************************************************************************************
 * Author       :      Shaimaa G.Salem
 * Date         :      7 Nov 2023
 * Version      :      v01
*********************************************************************************************************************************************/



#ifndef INC_DMA_INTERFACE_H_
#define INC_DMA_INTERFACE_H_


void DMA_voidInit(u8 copy_u8ChannelId);


void DMA_voidChannelStart(u8 copy_u8ChannelId,u32* Copy_pu32SourceAddress, u32* Copy_pu32DestinationAddress, u16 Copy_u16BlockLength);

#endif /* INC_DMA_INTERFACE_H_ */
