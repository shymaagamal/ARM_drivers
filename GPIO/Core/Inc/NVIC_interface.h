/*********************************************************************************************************************************************
 * Author       :      Shaimaa G.Salem
 * Date         :      6 Nov 2023
 * Version      :      v01
*********************************************************************************************************************************************/


#ifndef INC_NVIC_INTERFACE_H_
#define INC_NVIC_INTERFACE_H_

typedef enum
{
	NVICError=0,
	NVICNoError=1,

}Error_Status;


Error_Status  NVIC_ErrorStatusEnableInterrupt(u8 copy_u8IntNumber);
Error_Status  NVIC_ErrorStatusDisableInterrupt(u8 copy_u8IntNumber);
Error_Status  NVIC_ErrorStatusSetPendingFlag(u8 copy_u8IntNumber);
Error_Status  NVIC_ErrorStatusClearPendingFlag(u8 copy_u8IntNumber);

u8 NVIC_u8GetActiveFlag(u8 copy_u8IntNumber);
void NVIC_voidSetPriority(s8 copy_s8INTID,u8 copy_u8GroupPriority,u8 copy_u8SubPriority);
#endif /* INC_NVIC_INTERFACE_H_ */
