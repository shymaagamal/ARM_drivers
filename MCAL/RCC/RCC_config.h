/*********************************************************************************************************************************************
 * Author       :      Shaimaa G.Salem
 * Date         :      2 Nov 2023
 * Version      :      v01
*********************************************************************************************************************************************/
 
 
 
 #ifndef RCC_CONFIG_H
 #define RCC_CONFIG_H


/* Options:     RCC_HSE_CRYSTAL
                RCC_HSE_RC
                RCC_HSI
                RCC_PLL
*/
#define RCC_CLOCK_TYPE    RCC_HSE_CRYSTAL


/* Options:     RCC_PLL_IN_HSI_DIV_2
                RCC_PLL_IN_HSE_DIV_2
                RCC_PLL_IN_HSE
* Note:Select Value only if you have PLL as Input Clock Source
*/
#if(RCC_CLOCK_TYPE== RCC_PLL)
#define RCC_PLL_INPUT    RCC_PLL_IN_HSE_DIV_2

/*Options 2  to  16*/
#define RCC_PLL_MUL_VAL  4

#endif



#endif /*RCC_CONFIG_H*/