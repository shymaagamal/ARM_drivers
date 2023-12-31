/*********************************************************************************************************************************************
 * Author       :      Shaimaa G.Salem
 * Date         :      7 Nov 2023
 * Version      :      v01
*********************************************************************************************************************************************/

#ifndef INC_STK_INTERFACE_H_
#define INC_STK_INTERFACE_H_


void STK_voidInit();
void STK_voidSetBusyWait(u32 Copy_u32NumOfTicks);
void STK_voidSetIntervalSingle(u32 Copy_u32NumOfTicks, void(*Copy_pf)(void));
void STK_voidSetIntervalPeriodic(u32 Copy_u32NumOfTicks, void(*Copy_pf)(void));
void STK_voidStopTimer();
u32 STK_u32GetElabsedTime(u32 * Copy_pu32ElapsedTime);
u32 STK_u32GetRemainingTime(u32 * Copy_pu32RemainingTime);
#endif /* INC_STK_INTERFACE_H_ */
