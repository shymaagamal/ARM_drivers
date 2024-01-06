/*==============================================================================*
 * File        : BIT_MATH.h							     						*
 * Description : This file includes macros used for Bit manipulation          	*
 * Author      : Mahmoud Gharib Embedded SW Engineer 							*
 * Date        : 														        *
 * Git account : https://github.com/Mahmoud-Gharib								*
 * mail        : mahmoudgharib99999@gmail.com 									*
 *==============================================================================*/
#ifndef BIT_MATH_H_
#define BIT_MATH_H_

/*Bit-Math macros*/
#define SET_BIT(REG , BIT)     REG |= 1<<BIT
#define CLR_BIT(REG , BIT)     REG &= ~(1<<BIT)
#define TOG_BIT(REG , BIT)     REG ^= 1<<BIT
#define GET_BIT(REG , BIT)     ((REG >> BIT) & 1)


#define SIT_BIT(REG , BIT)     REG |= 1<<BIT
#define READ_BIT(REG , BIT)     ((REG >> BIT) & 1)
#endif 
