/**************************************************/
/* ! Author  : Abdullah M. Abdullah			      */
/* ! Date    : 11 NOV, 2021						  */
/* ! Version : v1.0								  */
/**************************************************/
#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

typedef struct
{
	volatile u32 CTRL;
	volatile u32 LOAD;
	volatile u32 VAL;
	volatile u32 CALIB;
}STK_t;

#define 	STK		((volatile STK_t *)0xE000E010)


#define ENABLE			1
#define DISABLE			0
#define AHB				0
#define AHB_DIV_8		1

#define SINGLE_MODE		0
#define PERIODIC_MODE	1

#endif