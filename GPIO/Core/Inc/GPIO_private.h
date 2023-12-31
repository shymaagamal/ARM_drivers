/*********************************************************************************************************************************************
 * Author       :      Shaimaa G.Salem
 * Date         :      5 Nov 2023
 * Version      :      v01
*********************************************************************************************************************************************/



#ifndef INC_GPIO_PRIVATE_H_
#define INC_GPIO_PRIVATE_H_





#define GPIOA_BASE_ADDRESS	0x40010800
#define GPIOB_BASE_ADDRESS	0x40010C00
#define GPIOC_BASE_ADDRESS	0x40011000

/*************************************************************************************************
 *							Registers Addresses For PORTA
 **************************************************************************************************/
#define GPIOA_CRL		*((volatile u32*) (GPIOA_BASE_ADDRESS))
#define GPIOA_CRH		*((volatile u32*) (GPIOA_BASE_ADDRESS+0x04))
#define GPIOA_IDR		*((volatile u32*) (GPIOA_BASE_ADDRESS+0x08))
#define GPIOA_ODR		*((volatile u32*) (GPIOA_BASE_ADDRESS+0x0c))
#define GPIOA_BSRR		*((volatile u32*) (GPIOA_BASE_ADDRESS+0x10))
#define GPIOA_BRR		*((volatile u32*) GPIOA_BASE_ADDRESS+0x14)
#define GPIOA_LCKR		*((volatile u32*) GPIOA_BASE_ADDRESS+0x18)


/*************************************************************************************************
 *							Registers Addresses For PORTB
 **************************************************************************************************/

#define GPIOB_CRL		*((volatile u32*) (GPIOB_BASE_ADDRESS))
#define GPIOB_CRH		*((volatile u32*) (GPIOB_BASE_ADDRESS+0x04))
#define GPIOB_IDR		*((volatile u32*) (GPIOB_BASE_ADDRESS+0x08))
#define GPIOB_ODR		*((volatile u32*) (GPIOB_BASE_ADDRESS+0x0c))
#define GPIOB_BSRR		*((volatile u32*) (GPIOB_BASE_ADDRESS+0x10))
#define GPIOB_BRR		*((volatile u32*) (GPIOB_BASE_ADDRESS+0x14))
#define GPIOB_LCKR		*((volatile u32*) (GPIOB_BASE_ADDRESS+0x18))

/*************************************************************************************************
 *							Registers Addresses For PORTC
 **************************************************************************************************/


#define GPIOC_CRL		*((volatile u32*) GPIOC_BASE_ADDRESS)
#define GPIOC_CRH		*((volatile u32*) GPIOC_BASE_ADDRESS+0x04)
#define GPIOC_IDR		*((volatile u32*) GPIOC_BASE_ADDRESS+0x08)
#define GPIOC_ODR		*((volatile u32*) GPIOC_BASE_ADDRESS+0x0c)
#define GPIOC_BSRR		*((volatile u32*) GPIOC_BASE_ADDRESS+0x10)
#define GPIOC_BRR		*((volatile u32*) GPIOC_BASE_ADDRESS+0x14)
#define GPIOC_LCKR		*((volatile u32*) GPIOC_BASE_ADDRESS+0x18)





#endif /* INC_GPIO_PRIVATE_H_ */
