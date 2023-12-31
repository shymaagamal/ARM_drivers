/*********************************************************************************************************************************************
 * Author       :      Shaimaa G.Salem
 * Date         :      6 Nov 2023
 * Version      :      v01
*********************************************************************************************************************************************/

#include "STD_TYPES.h"

#include "BIT_MATH.h"
#include "NVIC_config.h"
#include "NVIC_interface.h"
#include "NVIC_private.h"



Error_Status  NVIC_ErrorStatusEnableInterrupt(u8 copy_u8IntNumber)
{
	u8	local_errorStatus=NVICNoError;
	if(copy_u8IntNumber <=31)
	{
		NVIC_ISER0=(1<<copy_u8IntNumber); /* writing Zero has noEffect on NVIC_ISER0 */
	}
	else if(copy_u8IntNumber<=59)
	{
		copy_u8IntNumber-=32;
		NVIC_ISER0=(1<<copy_u8IntNumber);
	}
	else
	{
		local_errorStatus=NVICError;
	}
	return local_errorStatus;
}
Error_Status  NVIC_ErrorStatusDisableInterrupt(u8 copy_u8IntNumber)
{
	u8	local_errorStatus=NVICNoError;
	if(copy_u8IntNumber <=31)
	{
		NVIC_ICER0=(1<<copy_u8IntNumber); /* writing Zero has noEffect on NVIC_ISER0 */
	}
	else if(copy_u8IntNumber<=59)
	{
		copy_u8IntNumber-=32;
		NVIC_ICER1=(1<<copy_u8IntNumber);
	}
	else
	{
		local_errorStatus=NVICError;
	}
	return local_errorStatus;
}
Error_Status  NVIC_ErrorStatusSetPendingFlag(u8 copy_u8IntNumber)
{
	u8	local_errorStatus=NVICNoError;
	if(copy_u8IntNumber <=31)
	{
		NVIC_ISPR0=(1<<copy_u8IntNumber); /* writing Zero has noEffect on NVIC_ISER0 */
	}
	else if(copy_u8IntNumber<=59)
	{
		copy_u8IntNumber-=32;
		NVIC_ISPR1=(1<<copy_u8IntNumber);
	}
	else
	{
		local_errorStatus=NVICError;
	}
	return local_errorStatus;
}
Error_Status  NVIC_ErrorStatusClearPendingFlag(u8 copy_u8IntNumber)
{
	u8	local_errorStatus=NVICNoError;
	if(copy_u8IntNumber <=31)
	{
		NVIC_ICPR0=(1<<copy_u8IntNumber); /* writing Zero has noEffect on NVIC_ISER0 */
	}
	else if(copy_u8IntNumber<=59)
	{
		copy_u8IntNumber-=32;
		NVIC_ICPR1=(1<<copy_u8IntNumber);
	}
	else
	{
		local_errorStatus=NVICError;
	}
	return local_errorStatus;
}

u8 NVIC_u8GetActiveFlag(u8 copy_u8IntNumber)
{
	u8	local_flagResult;
	if(copy_u8IntNumber <=31)
	{
		local_flagResult=GET_BIT(NVIC_IABR0,copy_u8IntNumber);/* GET Active Flag */
	}
	else if(copy_u8IntNumber<=59)
	{
		copy_u8IntNumber-=32;
		local_flagResult=GET_BIT(NVIC_IABR1,copy_u8IntNumber);
	}

	return local_flagResult;
}
void NVIC_voidSetPriority(s8 copy_s8INTID,u8 copy_u8GroupPriority,u8 copy_u8SubPriority)
{

	SCB_AIRCR=GROUP3;




}

