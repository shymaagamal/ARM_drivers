/*********************************************************************************************************************************************
 * Author       :      Shaimaa G.Salem
 * Date         :      5 Nov 2023
 * Version      :      v01
 * Description  :      GPIO Interface
*********************************************************************************************************************************************/



#ifndef INC_GPIO_INTERFACE_H_
#define INC_GPIO_INTERFACE_H_


#define LOGIC_LOW		0
#define LOGIC_HIGH		1

#define PORTA_ID 0
#define PORTB_ID 1
#define PORTC_ID 2





#define OUTPUT_SPEED10HZ_PUSH_PULL		0b0001
#define OUTPUT_SPEED2HZ_PUSH_PULL		0b0010
#define OUTPUT_SPEED50HZ_PUSH_PULL		0b0011

#define OUTPUT_SPEED10HZ_OPEN_DRAIN		0b0101
#define OUTPUT_SPEED2HZ_OPEN_DRAIN		0b0110
#define OUTPUT_SPEED50HZ_OPEN_DRAIN		0b0111

#define OUTPUT_SPEED10HZ_AF_PUSH_PULL	0b1001
#define OUTPUT_SPEED2HZ_AF_PUSH_PULL	0b1010
#define OUTPUT_SPEED50HZ_AF_PUSH_PULL	0b1011

#define OUTPUT_SPEED10HZ_AF_OPEN_DRAIN	0b1101
#define OUTPUT_SPEED2HZ_AF_OPEN_DRAIN	0b1110
#define OUTPUT_SPEED50HZ_AF_OPEN_DRAIN 	0b1111



#define INPUT_Analog 					0b0000
#define INPUT_FLOATING					0b0001
#define INPUT_PULL_UP_DOWN				0b0010




void GPIO_voidSetPinDirection(u8 copy_u8PortId,u8 copy_u8PinNum,u8 copy_u8PinMood);
void GPIO_voidSetPinValue(u8 copy_u8PortId,u8 copy_u8PinNum,u8 copy_u8PinVal);
u8 GPIO_u8getPinValue(u8 copy_u8PortId,u8 copy_u8PinNum);


#endif /* INC_GPIO_INTERFACE_H_ */
