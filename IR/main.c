/**************************************************/
/* ! Author  : Abdullah M. Abdullah			      */
/* ! Date    : 23 NOV, 2021						  */
/* ! Version : v1.0								  */
/**************************************************/
#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "../include/RCC_interface.h"
#include "../include/GPIO_interface.h"
#include "../include/STK_interface.h"
#include "../include/NVIC_interface.h"
#include "../include/EXTI_interface.h"

void APP_voidGetFrame(void);
void APP_voidTakeAction(void);
void APP_voidPlay(void);

void main(void)
{
	/*Initialize System Clock*/
	RCC_voidClockSystemInit();
	/*Enable Clock For GPIOA*/
	RCC_voidEnablePeripheralClock(RCC_APB2, 2);
	/*Initialize The Pins*/
	GPIO_voidSetPinDirection(GPIOA, PIN0, INPUT_FLOAT);	    /* A0 -> EXTI0 */
	GPIO_voidSetPinDirection(GPIOA, PIN1, OUTPUT_2MHZ_PP);	/* A1 -> RED   */
	GPIO_voidSetPinDirection(GPIOA, PIN2, OUTPUT_2MHZ_PP);	/* A2 -> BLUE  */
	GPIO_voidSetPinDirection(GPIOA, PIN3, OUTPUT_2MHZ_PP);	/* A3 -> GREEN */
	/*Set EXTI0 Callback Function*/
	MEXTI_voidSetCallback(EXTI_LINE0, &APP_voidGetFrame);
	/*Initialize External Line*/
	MEXTI_voidInit();
	/*Initialize NVIC*/
	MNVIC_voidInit();
	MNVIC_voidInterruptEnable(6);			// EXTI0
	/*Systick Initialize*/
	MSTK_voidInit();
	while(1)
	{

	}
}

u8   APP_u8StartFlag = 0;
u32  APP_u32ReceivedFrame[50] = {0};
u8   APP_u8EdgeCounter = 0;
u8   APP_u8Data = 0;
void APP_voidGetFrame(void)
{
	/*Check if the Received Edge The very first falling edge or not*/
	if(APP_u8StartFlag == 0)
	{
		/*Start Timer To Count The Ticks*/
		MSTK_voidSetIntervalSingle(1000000, &APP_voidTakeAction);
		APP_u8StartFlag = 1;
	}
	else
	{
		APP_u32ReceivedFrame[APP_u8EdgeCounter] = MSTK_u32GetElapsedTime();
		MSTK_voidSetIntervalSingle(1000000, &APP_voidTakeAction);
		APP_u8EdgeCounter++;
	}
}

void APP_voidTakeAction(void)
{
	APP_u8Data = 0;
	u8 Local_u8LoopCounter;
	if(APP_u32ReceivedFrame[0] >= 10000 && APP_u32ReceivedFrame[0] <= 15000 )
	{
		for(Local_u8LoopCounter = 0; Local_u8LoopCounter < 8; Local_u8LoopCounter++)
		{
			if( (APP_u32ReceivedFrame[17+Local_u8LoopCounter] >= 1000) &&
					(APP_u32ReceivedFrame[17+Local_u8LoopCounter] <= 1500))
			{
				CLR_BIT(APP_u8Data, Local_u8LoopCounter);
			}
			else
			{
				SET_BIT(APP_u8Data, Local_u8LoopCounter);
			}
		}
		APP_voidPlay();
	}
	else
	{
		/*Invalid Frame*/
	}

	APP_u32ReceivedFrame[0] = 0;
	APP_u8EdgeCounter = 0;
	APP_u8StartFlag = 0;
}


void APP_voidPlay(void)
{
	switch(APP_u8Data)
	{
	case 12:
		GPIO_voidSetPinValue(GPIOA, PIN1, GPIO_HIGH);
		break;
	case 24:
		GPIO_voidSetPinValue(GPIOA, PIN2, GPIO_HIGH);
		break;
	case 94:
		GPIO_voidSetPinValue(GPIOA, PIN3, GPIO_HIGH);
		break;
	}
}





