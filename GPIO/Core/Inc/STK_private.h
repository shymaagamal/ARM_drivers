/*********************************************************************************************************************************************
 * Author       :      Shaimaa G.Salem
 * Date         :      7 Nov 2023
 * Version      :      v01
*********************************************************************************************************************************************/


#ifndef INC_STK_PRIVATE_H_
#define INC_STK_PRIVATE_H_


typedef struct
{
	u32 ENABLE:1;
	u32 TICKINT:1;
	u32 CLKSOURCE:1;
	u32 :13;
	u32 COUNTFLAG:1;
	u32 :15;

}CTRL;

#define STK_BASE_ADDRESS 		0xE000E010

#define CTRL_REG		((volatile CTRL*) (STK_BASE_ADDRESS))
#define LOAD_REG		*((volatile u32*) (STK_BASE_ADDRESS+0x04))
#define VAL_REG			*((volatile u32*) (STK_BASE_ADDRESS+0x08))
#define CALIB_REG		*((volatile u32*) (STK_BASE_ADDRESS+0x0C))


#define AHB_DIV_8   0
#define AHB			1


#endif /* INC_STK_PRIVATE_H_ */
