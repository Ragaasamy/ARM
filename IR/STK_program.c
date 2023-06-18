/**************************************************/
/* ! Author  : Abdullah M. Abdullah			      */
/* ! Date    : 11 NOV, 2021						  */
/* ! Version : v1.0								  */
/**************************************************/
#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "../include/STK_interface.h"
#include "../include/STK_private.h"
#include "../include/STK_config.h"

static void  (*Global_pvSTKFunction)(void) = NULL;
static u8 Global_u8SysTickOperationMode;

void MSTK_voidInit(void)
{
	#if 	STK_ENABLE		== ENABLE
		SET_BIT(STK->CTRL, 0);
	#elif 	STK_ENABLE		== DISABLE
		CLR_BIT(STK->CTRL, 0);
	#else
		#error "STK_ENABLE Configuration Error"
	#endif
	
	#if 	STK_INTERRUPT_ENABLE		== ENABLE
		SET_BIT(STK->CTRL, 1);
	#elif 	STK_INTERRUPT_ENABLE		== DISABLE
		CLR_BIT(STK->CTRL, 1);
	#else
		#error "STK_INTERRUPT_ENABLE Configuration Error"
	#endif
	
	#if 	STK_CLOCK_SOURCE		== AHB
		SET_BIT(STK->CTRL, 2);
	#elif 	STK_CLOCK_SOURCE		== AHB_DIV_8
		CLR_BIT(STK->CTRL, 2);
	#else
		#error "STK_CLOCK_SOURCE Configuration Error"
	#endif
}

/*
	AHB = 8MHz
	STK -> AHB/8
	tick Time for STK = 1usec
*/

void MSTK_voidSetBusyWait(u32 Copy_u32Ticks)
{
	/*Load Ticks To The LOAD Register*/
	STK -> LOAD = Copy_u32Ticks;
	
	/*Start Timer*/
	SET_BIT(STK->CTRL, 0);
	
	/*Wait for the flag is raised (Polling Mechanism)*/
	while(GET_BIT(STK->CTRL, 16) == 0);
	
	/*Stop The Timer*/
	CLR_BIT(STK->CTRL, 0);
	STK -> LOAD = 0;
	STK -> VAL = 0;
}

u32 MSTK_u32GetElapsedTime(void)
{
	u32 Local_u32ElapsedTime;
	Local_u32ElapsedTime = (STK->LOAD) - (STK->VAL);
	return Local_u32ElapsedTime;
}

u32 MSTK_u32GetRemainingTime(void)
{
	u32 Local_u32ElapsedTime;
	Local_u32ElapsedTime = (STK->VAL);
	return Local_u32ElapsedTime;
}

void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks, void(*Copy_pvNotificationFunction)(void))
{
	/*Disable Timer*/
	CLR_BIT(STK->CTRL, 0);
	STK -> VAL = 0;

	/*Set The Operation Mode To SINGLE_MODE*/
	Global_u8SysTickOperationMode = SINGLE_MODE;
	/*Load The Ticks To The LOAD Register*/
	STK -> LOAD = Copy_u32Ticks;
	/*Start Timer*/
	SET_BIT(STK->CTRL, 0);
	/*Assign the Passed Address To The Global Pointer To Function*/
	Global_pvSTKFunction = Copy_pvNotificationFunction;
	/*Enable Interrupt*/
	SET_BIT(STK->CTRL, 1);
}


void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void(*Copy_pvNotificationFunction)(void))
{
	/*Set The Operation Mode To PERIODIC_MODE*/
	Global_u8SysTickOperationMode = PERIODIC_MODE;
	/*Load The Ticks To The LOAD Register*/
	STK -> LOAD = Copy_u32Ticks;
	/*Start Timer*/
	SET_BIT(STK->CTRL, 0);
	/*Assign the Passed Address To The Global Pointer To Function*/
	Global_pvSTKFunction = Copy_pvNotificationFunction;
	/*Enable Interrupt*/
	SET_BIT(STK->CTRL, 1);
	
}

void SysTick_Handler(void)
{
	u8 Local_u8Dummy;
	if(Global_u8SysTickOperationMode == SINGLE_MODE)
	{
		/*Stop Timer*/
		CLR_BIT(STK->CTRL, 0);
		/*Disbale SysTick Interrupt*/
		CLR_BIT(STK->CTRL, 1);
		/*Clear Registers*/
		STK->LOAD = 0;
		STK->VAL = 0;
	}
	if(Global_pvSTKFunction != NULL)
	{
		Global_pvSTKFunction();
		Local_u8Dummy = GET_BIT(STK->CTRL, 16);		
	}
	else
	{
		/*Do Nothing*/
	}
}
