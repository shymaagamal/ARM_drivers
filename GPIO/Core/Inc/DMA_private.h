/*********************************************************************************************************************************************
 * Author       :      Shaimaa G.Salem
 * Date         :      7 Nov 2023
 * Version      :      v01
*********************************************************************************************************************************************/


#ifndef INC_DMA_PRIVATE_H_
#define INC_DMA_PRIVATE_H_




#define DMA1_BASE_ADDRESS   0x40020000

typedef struct
{
u32 EN:1;
u32 TCIE:1;
u32 HTIE:1;
u32 TEIE:1;
u32 DIR:1;
u32 CIRC:1;
u32 PINC:1;
u32 MINC:1;
u32 PSIZE:2;
u32 MSIZE:2;
u32 PL:2;
u32 MEM2MEM:1;
u32 :17;

}CCRBits;
typedef struct
{
	CCRBits *CCR;
	u32 CNDTR;
	u32 CPAR;
	u32 CMAR;

}ChannalREG;
typedef struct
{
	u32 ISR;
	u32 IFCR;
	ChannalREG *channel[7];

}DMA;

#define  DMA_REG 		 ((volatile DMA*) DMA1_BASE_ADDRESS)



#define PERIPERAL_SOURCE_MEMORY_DESTINATION			0
#define	MEMORY_SOURCE_PERIPERAL_DESTINATION			1
#define	MEMORY_TO_MEMORY_ENABLED					2
#define	MEMORY_TO_MEMORY_DISABLED					3



#define LOW				 0b00
#define MEDIUM			 0b01
#define HIGH			 0b10
#define VERY_HIGH		 0b11


#define MEM_BITS8		0b00
#define	MEM_BITS16		0b01
#define	MEM_BITS32      0b10

#define PER_BITS8		0b00
#define	PER_BITS16		0b01
#define	PER_BITS32      0b10
#endif /* INC_DMA_PRIVATE_H_ */
