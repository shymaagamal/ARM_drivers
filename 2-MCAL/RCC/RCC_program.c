/*********************************************************************************************************************************************
 * Author       :      Shaimaa G.Salem
 * Date         :      2 Nov 2023
 * Version      :      v01
*********************************************************************************************************************************************/
 
#include "STD_TYPES"
#include "BIT_MATH.h" 
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_voidInitSysClock(void)
{
    
}

void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
    if(Copy_u8PerId <=32 )
    {
        switch(Copy_u8BusId)
        {
            case RCC_AHB:
            SET_BIT(RCC_AHBENR,Copy_u8PerId);
            break;
            case RCC_APB1:
            SET_BIT(RCC_APB1ENR,Copy_u8PerId);
            break;
            case RCC_APB2:
            SET_BIT(RCC_APB2ENR,Copy_u8PerId);
            break;
 

        }
    }
    else
    {
        /* Return Error */
    }
}

void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
    if(Copy_u8PerId <=32 )
    {
        switch(Copy_u8BusId)
        {
            case RCC_AHB:
            CEALR_BIT(RCC_AHBENR,Copy_u8PerId);
            break;
            case RCC_APB1:
            CEALR_BIT(RCC_APB1ENR,Copy_u8PerId);
            break;
            case RCC_APB2:
            CEALR_BIT(RCC_APB2ENR,Copy_u8PerId);
            break;
 

        }
    }
    else
    {
        /* Return Error */
    }
}