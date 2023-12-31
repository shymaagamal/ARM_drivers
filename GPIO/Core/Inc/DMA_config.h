/*
 * DMA_config.h
 *
 *  Created on: Nov 7, 2023
 *      Author: Shaimaa Gamal
 */

#ifndef INC_DMA_CONFIG_H_
#define INC_DMA_CONFIG_H_

/*Options:	PERIPERAL_SOURCE_MEMORY_DESTINATION			0
			MEMORY_SOURCE_PERIPERAL_DESTINATION			1
			MEMORY_TO_MEMORY_ENABLED					2
			MEMORY_TO_MEMORY_DISABLED
 *
 * */
#define DATA_TRANSFER_DIRECTION		MEMORY_TO_MEMORY_ENABLED

/*Options:		LOW
 *				MEDIUM
 *				HIGH
 *				VERY_HIGH
 * */
#define CHANNEL_PRIORITY_LEVEL		VERY_HIGH

/*Options:    MEM_BITS8
 *			  MEM_BITS16
 *			  MEM_BITS32
 * */
#define	CHANNEL_MEMORY_SIZE		MEM_BITS8

/*Options:    PER_BITS8
 *			  PER_BITS16
 *			  PER_BITS32
 * */
#define	CHANNEL_PERIPHERAL_SIZE    PER_BITS16

/*Options:  0-> Memory increment mode disabled
			1-> Memory increment mode enabled
 * */
#define MEMORY_INCREMENT_MODE  0
/*Options:  0-> Peripheral increment mode disabled
			1-> Peripheral increment mode enabled
 * */
#define PERIPHERAL_INCREMENT_MODE	0
/*Options:  0-> Circular mode disabled
			1-> Circular mode  enabled
 * */
#define CIRCULAR_MODE	0
/*Options:  0-> Transfer error interrupt disable
			1-> Transfer error interrupt enable
 * */
#define TRANSFER_ERROR_INTERRUPT_ENABLE		0

/*Options:  0-> Half Transfer  interrupt disable
			1-> Half Transfer  interrupt  enabled
 * */
#define HALF_TRANSFER_INTERRUPT_ENABLE    	0
/*Options:  0-> Complete Transfer  interrupt disable
			1-> Complete Transfer  interrupt  enabled
 * */
#define COMPLETE_TRANSFER_INTERRUPT_ENABLE			0
#endif /* INC_DMA_CONFIG_H_ */
