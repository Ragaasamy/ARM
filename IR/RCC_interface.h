#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H


#define RCC_AHB  0
#define RCC_APB1 1
#define RCC_APB2 2

void RCC_voidClockSystemInit(void);
void RCC_voidEnablePeripheralClock(u8 Copy_u8BusName ,u8 Copy_u8PeripheralID);
void RCC_voidDisablePeripheralClock(u8 Copy_u8BusName ,u8 Copy_u8PeripheralID);

#endif
