/**************************************************/
/* ! Author  : Abdullah M. Abdullah			      */
/* ! Date    : 4 NOV, 2021						  */
/* ! Version : v1.0								  */
/**************************************************/

#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "../include/NVIC_interface.h"
#include "../include/NVIC_private.h"
#include "../include/NVIC_config.h"

void MNVIC_voidInit(void)
{
	#define 	SCB_AIRCR		*((u32 *)(0xE000ED00+0x0C))
	SCB_AIRCR = NVIC_GRP_SUB_DISTRUBTION;
}


void MNVIC_voidSetPriority(u8 Copy_u8InterruptID, u8 Copy_u8Priority)
{
	if(Copy_u8InterruptID <= 59)
	{
		NVIC_IPR[Copy_u8InterruptID] = Copy_u8Priority;
	}
	else
	{
		/* Return Error */
	}
}

void MNVIC_voidInterruptEnable(u8 Copy_u8InterruptID)
{
	if(Copy_u8InterruptID <=31)
	{
		NVIC_ISER0 = (1 << Copy_u8InterruptID);
	}
	else if(Copy_u8InterruptID <=59)
	{
		Copy_u8InterruptID -= 32; 
		NVIC_ISER1 = (1 << Copy_u8InterruptID);
	}
	else
	{
		/* Return Error */
	}
}

void MNVIC_voidInterruptDisable(u8 Copy_u8InterruptID)
{
	if(Copy_u8InterruptID <=31)
	{
		NVIC_ICER0 = (1 << Copy_u8InterruptID);
	}
	else if(Copy_u8InterruptID <=59)
	{
		Copy_u8InterruptID -= 32; 
		NVIC_ICER1 = (1 << Copy_u8InterruptID);
	}
	else
	{
		/* Return Error */
	}
}


void MNVIC_voidSetPendingFlag(u8 Copy_u8InterruptID)
{
	if(Copy_u8InterruptID <= 31)
	{
		NVIC_ISPR0 = (1 << Copy_u8InterruptID);
	}
	else if(Copy_u8InterruptID <= 59)
	{
		Copy_u8InterruptID -= 32;
		NVIC_ISPR1 = (1 << Copy_u8InterruptID);
	}
	else
	{
		/* Return Error */
	}
}


void MNVIC_voidClearPendingFlag(u8 Copy_u8InterruptID)
{
	if(Copy_u8InterruptID <= 31)
	{
		NVIC_ICPR0 = (1 << Copy_u8InterruptID);
	}
	else if(Copy_u8InterruptID <= 59)
	{
		Copy_u8InterruptID -= 32;
		NVIC_ICPR1 = (1 << Copy_u8InterruptID);
	}
	else
	{
		/* Return Error */
	}
}

u8 MNVIC_u8GetActiveFlag(u8 Copy_u8InterruptID)
{
	u8 Local_u8Result = 0;
	if(Copy_u8InterruptID <= 31)
	{
		Local_u8Result = GET_BIT(NVIC_IABR0, Copy_u8InterruptID);
	}
	else if(Copy_u8InterruptID <= 59)
	{
		Copy_u8InterruptID -= 32;
		Local_u8Result = GET_BIT(NVIC_IABR1, Copy_u8InterruptID);
	}
	else
	{
		/* Return Error*/
	}
	
	return Local_u8Result;
}