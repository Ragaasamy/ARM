/**************************************************/
/* ! Author  : Abdullah M. Abdullah			      */
/* ! Date    : 11 NOV, 2021						  */
/* ! Version : v1.0								  */
/**************************************************/
#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H
void MSTK_voidInit(void);
void MSTK_voidSetBusyWait(u32 Copy_u32Ticks);
void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks, void(*Copy_pvNotificationFunction)(void));
void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void(*Copy_pvNotificationFunction)(void));
u32 MSTK_u32GetRemainingTime(void);
u32 MSTK_u32GetElapsedTime(void);

#endif
