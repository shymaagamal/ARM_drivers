/*
 * RCC_Private.h
 *
 * Created: 2/11/2023 10:47:34 AM
 *  Author: Mahmoud Ahmed Ismail
 */

#ifndef _RCC_Private_H_
#define _RCC_Private_H_

#include "STD_TYPES.h"

//START_ENDADDRESS FOR RCC_PREPHIERLS

#define RCC_BASEADDRESS      *((volatile u32*)0x40021000)  //START ADDRESS
#define RCC_ENDADDRESS       *((volatile u32)0x400213FF)   //END   ADDRESS

//clock_controlRegister
#define RCC_CR               *((volatile u32*)0x40021000)

#define  HSI_ON    0                               //Enable high speed internal RC (8MHZ)
#define  HSI_RDY   1                               // high speed internal  RC FLAG
#define  HSI_TRIM  7	                           //from bit3 to bit7 ((+-) FREQUANCY START 16)
#define  HSI_CAL   8                               //from bit8 to bit15 (H.W CALIBRATION)
#define  HSE_ON    16                              //Enable high speed external
#define  HSE_RDY   17                              //high speed external FLAG
#define  HSE_BYp   18                              //BYPATH (if 1->RC) (if->0 crystal)
#define  CSS_ON    19                              //Enable clock security system
#define  PLL_ON    24                              //Enable pll_clock
#define  PLL_RDY   25                              //ppl_clock  FLAG

//Clock_configurationRegister
#define RCC_CFGR             *((volatile u32*)0x40021004)

#define  SW           0                              //from bit0 to bit1  System clock switch
#define  SWS          2                              // from bit2 to bit3   System clock switch status
#define  HP_RE        4                              //from bit4 to bit7  AHB prescaler
#define  PPR_E1       8                              //from bit8 to bit10 APB low-speed prescaler (APB1)
#define  PPR_E2       11                             ////from bit 11 to bit13 APB high-speed prescaler (APB2)
#define  ADC_PRE      14                             //from bit 14 to bit 15  ADC prescaler
#define  PLL_SRC      16                             // PLL entry clock source(external or internal)
#define  PLL_XTPRE    17                             // HSE divider for PLL entry
#define  PLL_MUL      18                             // PLL multiplication factor  bit18 to bit21
#define  USB_PRE      22                             //USB prescaler
#define  MC0          24                             //Microcontroller clock output bit24 to bit26


#define RCC_CIR              *((volatile u32*)0x40021008)
#define RCC_APB2RSTR         *((volatile u32*)0x4002100C)
#define RCC_APB1RSTR         *((volatile u32*)0x40021010)
#define RCC_AHBENR           *((volatile u32*)0x40021014)
#define RCC_APB2ENR          *((volatile u32*)0x40021018)
#define RCC_APB1ENR          *((volatile u32*)0x4002101C)
#define RCC_BDCR             *((volatile u32*)0x40021020)
#define RCC_CSR              *((volatile u32*)0x40021024)


//clock_type

#define RCC_HSI           0
#define RCC_HSE_CRYSTAL   1
#define RCC_HSE_RC        2
#define RCC_PLL           3

//System clock switch

#define   HSI_SC          0
#define   HSE_SC          1
#define   PLL_SC          2
#define   NOT_ALLOWED     3

//pll_source

#define PLL_HSI_DIVIDEBY2         0
#define PLL_HSE_DIVIDEBY2         1
#define PLL_HSE                   2

#define PLL_MULBY2     0
#define PLL_MULBY3     1
#define PLL_MULBY4     2
#define PLL_MULBY5     3
#define PLL_MULBY6     4
#define PLL_MULBY7     5
#define PLL_MULBY8     6
#define PLL_MULBY9     7
#define PLL_MULBY10    8
#define PLL_MULBY11    9
#define PLL_MULBY12    10
#define PLL_MULBY13    11
#define PLL_MULBY14    12
#define PLL_MULBY15    13
#define PLL_MULBY16    14
#define PLL_MULBY16_    15

#endif
