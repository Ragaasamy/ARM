/**************************************************/
/* ! Author  : Abdullah M. Abdullah			      */
/* ! Date    : 4 NOV, 2021						  */
/* ! Version : v1.0								  */
/**************************************************/
#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

typedef struct
{
	u32 IMR;
	u32 EMR;
	u32 RTSR;
	u32 FTSR;
	u32 SWIER;
	u32 PR;
}EXTI_t;


#define 	EXTI    ((volatile EXTI_t *)(0x40010400))



#define 	ENABLE				1
#define 	DISABLE				0

#endif