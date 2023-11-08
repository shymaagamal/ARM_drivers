/*********************************************************************************************************************************************
 * Author       :      Shaimaa G.Salem
 * Date         :      2 Nov 2023
 * Version      :      v01
*********************************************************************************************************************************************/

#ifndef BIT_MATH_H
#define BIT_MATH_H


#define SET_BIT(REG,BIT)            REG |= (1 << (BIT) )
#define CEALR_BIT(REG,BIT)          REG &= ~(1 << (BIT) )
#define GET_BIT(REG,BIT)            ((REG >> BIT ) & 1)
#define TOGGLE_BIT(REG,BIT)         REG ^= (1 << (BIT) )

#endif /*BIT_MATH_H*/
