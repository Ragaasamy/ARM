#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "../include/RCC_interface.h"
#include "../include/RCC_private.h"
#include "../include/RCC_config.h"


void RCC_voidClockSystemInit(void)
{
	#if    RCC_CLOCK_SOURCE == RCC_HSI
			RCC_CR   = 0x00000081;
			RCC_CFGR = 0x00000000;
			
	#elif  RCC_CLOCK_SOURCE == RCC_HSE_RC
			RCC_CR   = 0x00050000;
			RCC_CFGR = 0x00000001;
			
	#elif  RCC_CLOCK_SOURCE == RCC_HSE_CRYSTAL
			RCC_CR   = 0x00010000;
			RCC_CFGR = 0x00000001;
	
	#elif  RCC_CLOCK_SOURCE == RCC_PLL
		#if   RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
		
		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2
		
		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE
		
		#endif
	#else
		#error "RCC_CLOCK_SOURCE Error Configuration"
	#endif
}

void RCC_voidEnablePeripheralClock(u8 Copy_u8BusName ,u8 Copy_u8PeripheralID)
{
	if (Copy_u8PeripheralID <= 31)
	{
		switch(Copy_u8BusName)
		{
			case RCC_AHB:
				SET_BIT(RCC_AHBENR, Copy_u8PeripheralID);
			break;
			case RCC_APB1:
				SET_BIT(RCC_APB1ENR, Copy_u8PeripheralID);
			break;
			case RCC_APB2:
				SET_BIT(RCC_APB2ENR, Copy_u8PeripheralID);
			break;
		}
	}
	else
	{
		/*Return Error*/
	}
}

void RCC_voidDisablePeripheralClock(u8 Copy_u8BusName ,u8 Copy_u8PeripheralID)
{
	if (Copy_u8PeripheralID <= 31)
	{
		switch(Copy_u8BusName)
		{
			case RCC_AHB:
				CLR_BIT(RCC_AHBENR, Copy_u8PeripheralID);
			break;
			case RCC_APB1:
				CLR_BIT(RCC_APB1ENR, Copy_u8PeripheralID);
			break;
			case RCC_APB2:
				CLR_BIT(RCC_APB2ENR, Copy_u8PeripheralID);
			break;
		}
	}
	else
	{
		/*Return Error*/
	}
}
