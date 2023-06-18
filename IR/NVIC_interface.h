/**************************************************/
/* ! Author  : Abdullah M. Abdullah			      */
/* ! Date    : 4 NOV, 2021						  */
/* ! Version : v1.0								  */
/**************************************************/

#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H
void MNVIC_voidInit(void);
void MNVIC_voidSetPriority(u8 Copy_u8InterruptID, u8 Copy_u8Priority);
void MNVIC_voidInterruptEnable(u8 Copy_u8InterruptID);
void MNVIC_voidInterruptDisable(u8 Copy_u8InterruptID);
void MNVIC_voidSetPendingFlag(u8 Copy_u8InterruptID);
void MNVIC_voidClearPendingFlag(u8 Copy_u8InterruptID);
u8 	 MNVIC_u8GetActiveFlag(u8 Copy_u8InterruptID);

#endif