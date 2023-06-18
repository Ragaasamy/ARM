#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H


#define GPIOA   0
#define GPIOB   1
#define GPIOC   2

#define PIN0    0
#define PIN1    1
#define PIN2    2
#define PIN3    3
#define PIN4    4
#define PIN5    5
#define PIN6    6
#define PIN7    7
#define PIN8    8
#define PIN9    9
#define PIN10   10
#define PIN11   11
#define PIN12   12
#define PIN13   13
#define PIN14   14
#define PIN15   15


#define INPUT_ANALOG            0b0000
#define INPUT_FLOAT             0b0100
#define INPUT_PULL_UP_DOWN      0b1000

/* Speed 2MHz */
#define OUTPUT_2MHZ_PP          0b0010
#define OUTPUT_2MHZ_OD          0b0110
#define OUTPUT_2MHZ_AFPP        0b1010
#define OUTPUT_2MHZ_AFOD        0b1110

/* Speed 10MHz */
#define OUTPUT_10MHZ_PP          0b0001
#define OUTPUT_10MHZ_OD          0b0101
#define OUTPUT_10MHZ_AFPP        0b1001
#define OUTPUT_10MHZ_AFOD        0b1101


/* Speed 50MHz */
#define OUTPUT_50MHZ_PP          0b0011
#define OUTPUT_50MHZ_OD          0b0111
#define OUTPUT_50MHZ_AFPP        0b1011
#define OUTPUT_50MHZ_AFOD        0b1111

/* Pin Value */
#define GPIO_LOW    0
#define GPIO_HIGH   1

void GPIO_voidSetPinDirection(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinMode);
void GPIO_voidSetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinValue);
u8   GPIO_u8GetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber);

#endif