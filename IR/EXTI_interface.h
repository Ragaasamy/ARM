/**************************************************/
/* ! Author  : Abdullah M. Abdullah			      */
/* ! Date    : 4 NOV, 2021						  */
/* ! Version : v1.0								  */
/**************************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H


#define 	FALLING_EDGE		0
#define 	RISING_EDGE			1
#define 	ON_CHANGE			2

#define 	EXTI_LINE0		0
#define 	EXTI_LINE1		1
#define 	EXTI_LINE2		2

void MEXTI_voidInit(void);
void MEXTI_voidEXTISetSenseControl(u8 Copy_u8LineNumber, u8 Copy_u8SenseSignal);
void MEXTI_voidClearPendingFlag(u8 Copy_u8LineNumber);
void MEXTI_voidSetCallback(u8 Copy_u8ExternalLine, void (*Copy_pvNotificationFunction)(void));

#endif