/**************************************************/
/* ! Author  : Abdullah M. Abdullah			      */
/* ! Date    : 11 NOV, 2021						  */
/* ! Version : v2.0								  */
/**************************************************/
#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "../include/EXTI_interface.h"
#include "../include/EXTI_private.h"
#include "../include/EXTI_config.h"

static void (*Global_pvEXTI0NotificationFunction)(void) = NULL;


void MEXTI_voidInit(void)
{
	#if 		EXTI0_ENABLE == ENABLE
		SET_BIT(EXTI -> IMR, 0);
		#if 		EXTI0_SENSE_SIGNAL == FALLING_EDGE
						SET_BIT(EXTI -> FTSR, 0);
		#elif		EXTI0_SENSE_SIGNAL == RISING_EDGE
						SET_BIT(EXTI -> RTSR, 0);
		#elif		EXTI0_SENSE_SIGNAL == ON_CHANGE
						SET_BIT(EXTI -> FTSR, 0);
						SET_BIT(EXTI -> RTSR, 0);
		#else
				#error "Error, EXTI0_SENSE_SIGNAL Configuration"
		#endif
		
	#elif		EXTI0_ENABLE == DISABLE
		CLR_BIT(EXTI -> IMR, 0);
	#else
		#error "Error, EXTI0_ENABLE Configuration"
	#endif
}
	
void MEXTI_voidEXTISetSenseControl(u8 Copy_u8LineNumber, u8 Copy_u8SenseSignal)
{
	if(Copy_u8LineNumber <= 15)
	{
		switch(Copy_u8SenseSignal)
		{
			case RISING_EDGE:
					SET_BIT(EXTI->RTSR, Copy_u8LineNumber);
					CLR_BIT(EXTI->FTSR, Copy_u8LineNumber);
				break;
			case FALLING_EDGE:
					CLR_BIT(EXTI->RTSR, Copy_u8LineNumber);
					SET_BIT(EXTI->FTSR, Copy_u8LineNumber);
				break;
			case ON_CHANGE:
					SET_BIT(EXTI->RTSR, Copy_u8LineNumber);
					SET_BIT(EXTI->FTSR, Copy_u8LineNumber);
				break;
			default:
				break;
		}
	}
	else
	{
		/* Return Error */
	}
}

void MEXTI_voidClearPendingFlag(u8 Copy_u8LineNumber)
{
	if(Copy_u8LineNumber <= 15)
	{
		SET_BIT( EXTI -> PR, Copy_u8LineNumber);
	}
	else
	{
		/*Return Error*/
	}
}

void MEXTI_voidSetCallback(u8 Copy_u8ExternalLine, void (*Copy_pvNotificationFunction)(void))
{
	switch(Copy_u8ExternalLine)
	{
		case EXTI_LINE0:
			Global_pvEXTI0NotificationFunction = Copy_pvNotificationFunction;
			break;
	}
	
}

void EXTI0_IRQHandler(void)
{
	if(Global_pvEXTI0NotificationFunction != NULL)
	{
		Global_pvEXTI0NotificationFunction();
		SET_BIT( EXTI -> PR, 0);
	}
	else
	{
		/* Do Nothing*/
	}
	
}
