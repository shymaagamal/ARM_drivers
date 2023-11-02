/*********************************************************************************************************************************************
 * Author       :      Shaimaa G.Salem
 * Date         :      2 Nov 2023
 * Version      :      v01
*********************************************************************************************************************************************/
 #ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H



/********************************************************************************************************************************************
 *                                      Register Definition  
 *********************************************************************************************************************************************/
 
#define RCC_CR          *((volatile u32 *) (0x4002 1000))  /*Enable Input clk for processor*/

#define RCC_CFGR        *((volatile u32 *) (0x4002 1000 + 0x04)) /*Enable Input clk for processor*/

#define RCC_CIR         *((volatile u32 *) (0x4002 1000 + 0x08))

#define RCC_APB2RSTR    *((volatile u32 *) (0x4002 1000 + 0x0C))

#define RCC_APB1RSTR    *((volatile u32 *) (0x4002 1000 + 0x010))

#define RCC_AHBENR       *((volatile u32 *) (0x4002 1000 + 0x14))//Enable/Disable  Input clk 
#define RCC_APB2ENR     *((volatile u32 *) (0x4002 1000 + 0x18))//for different peripheral

#define RCC_APB1ENR     *((volatile u32 *) (0x4002 1000 + 0x1C))

#define RCC_BDCR        *((volatile u32 *) (0x4002 1000 + 0x20))




 #endif /*RCC_PRIVATE_H*/ 