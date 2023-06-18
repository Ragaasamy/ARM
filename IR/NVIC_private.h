/**************************************************/
/* ! Author  : Abdullah M. Abdullah			      */
/* ! Date    : 4 NOV, 2021						  */
/* ! Version : v1.0								  */
/**************************************************/

#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H


#define NVIC_BASE_ADDRESS	0xE000E100

#define NVIC_ISER0			*((u32 *)(NVIC_BASE_ADDRESS+0x000))
#define NVIC_ISER1			*((u32 *)(NVIC_BASE_ADDRESS+0x004))
#define NVIC_ISER2			*((u32 *)(NVIC_BASE_ADDRESS+0x008))

#define NVIC_ICER0			*((u32 *)(NVIC_BASE_ADDRESS+0x080))
#define NVIC_ICER1			*((u32 *)(NVIC_BASE_ADDRESS+0x084))
#define NVIC_ICER2			*((u32 *)(NVIC_BASE_ADDRESS+0x088))


#define NVIC_ISPR0			*((u32 *)(NVIC_BASE_ADDRESS+0x100))
#define NVIC_ISPR1			*((u32 *)(NVIC_BASE_ADDRESS+0x104))
#define NVIC_ISPR2			*((u32 *)(NVIC_BASE_ADDRESS+0x108))


#define NVIC_ICPR0			*((u32 *)(NVIC_BASE_ADDRESS+0x180))
#define NVIC_ICPR1			*((u32 *)(NVIC_BASE_ADDRESS+0x184))
#define NVIC_ICPR2			*((u32 *)(NVIC_BASE_ADDRESS+0x188))


#define NVIC_IABR0			*((volatile u32 *)(NVIC_BASE_ADDRESS+0x200))
#define NVIC_IABR1			*((volatile u32 *)(NVIC_BASE_ADDRESS+0x204))
#define NVIC_IABR2			*((volatile u32 *)(NVIC_BASE_ADDRESS+0x208))

#define NVIC_IPR			 ((volatile u8 *)(NVIC_BASE_ADDRESS+0x300))


#define NVIC_GRP_4_SUB_0		0x05FA0300
#define NVIC_GRP_3_SUB_1		0x05FA0400
#define NVIC_GRP_2_SUB_2		0x05FA0500
#define NVIC_GRP_1_SUB_3		0x05FA0600
#define NVIC_GRP_0_SUB_4		0x05FA0700


#endif