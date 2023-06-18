#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"


#include "../include/GPIO_interface.h"
#include "../include/GPIO_private.h"
#include "../include/GPIO_config.h"



void GPIO_voidSetPinDirection(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinMode)
{
    switch(Copy_u8PortName)
    {
        case GPIOA:
        /* Set Pins from Pin 0 to Pin 7 */
            if(  (Copy_u8PinNumber >= PIN0) && (Copy_u8PinNumber <= PIN7)  )
            {
                /* Reset (Bit Masking) for the 4-bits */
                GPIOA_CRL &=~ ((0b1111) << (Copy_u8PinNumber * 4));
                /* Set The Mode in the 4-bit */
                GPIOA_CRL |= ((Copy_u8PinMode) << (Copy_u8PinNumber * 4));
            }
        /* Set Pins from Pin 8 to Pin 15 */
            else if((Copy_u8PinNumber >= PIN8) && (Copy_u8PinNumber <= PIN15)  )
            {
                Copy_u8PinNumber = Copy_u8PinNumber - 8;  // Copy_u8PinNumber -=8;
                /* Reset (Bit Masking) for the 4-bits */
                GPIOA_CRH &=~ ((0b1111) << (Copy_u8PinNumber * 4));
                /* Set The Mode in the 4-bit */
                GPIOA_CRH |= ((Copy_u8PinMode) << (Copy_u8PinNumber * 4));
            }
        break;
        case GPIOB:
                /* Set Pins from Pin 0 to Pin 7 */
            if(  (Copy_u8PinNumber >= PIN0) && (Copy_u8PinNumber <= PIN7)  )
            {
                /* Reset (Bit Masking) for the 4-bits */
                GPIOB_CRL &=~ ((0b1111) << (Copy_u8PinNumber * 4));
                /* Set The Mode in the 4-bit */
                GPIOB_CRL |= ((Copy_u8PinMode) << (Copy_u8PinNumber * 4));
            }
        /* Set Pins from Pin 8 to Pin 15 */
            else if((Copy_u8PinNumber >= PIN8) && (Copy_u8PinNumber <= PIN15)  )
            {
                Copy_u8PinNumber = Copy_u8PinNumber - 8;  // Copy_u8PinNumber -=8;
                /* Reset (Bit Masking) for the 4-bits */
                GPIOB_CRH &=~ ((0b1111) << (Copy_u8PinNumber * 4));
                /* Set The Mode in the 4-bit */
                GPIOB_CRH |= ((Copy_u8PinMode) << (Copy_u8PinNumber * 4));
            }
        break;
        case GPIOC:
                /* Set Pins from Pin 0 to Pin 7 */
            if(  (Copy_u8PinNumber >= PIN0) && (Copy_u8PinNumber <= PIN7)  )
            {
                /* Reset (Bit Masking) for the 4-bits */
                GPIOC_CRL &=~ ((0b1111) << (Copy_u8PinNumber * 4));
                /* Set The Mode in the 4-bit */
                GPIOC_CRL |= ((Copy_u8PinMode) << (Copy_u8PinNumber * 4));
            }
        /* Set Pins from Pin 8 to Pin 15 */
            else if((Copy_u8PinNumber >= PIN8) && (Copy_u8PinNumber <= PIN15)  )
            {
                Copy_u8PinNumber = Copy_u8PinNumber - 8;  // Copy_u8PinNumber -=8;
                /* Reset (Bit Masking) for the 4-bits */
                GPIOC_CRH &=~ ((0b1111) << (Copy_u8PinNumber * 4));
                /* Set The Mode in the 4-bit */
                GPIOC_CRH |= ((Copy_u8PinMode) << (Copy_u8PinNumber * 4));
            }
        break;
    }
}


void GPIO_voidSetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinValue)
{
    if( (Copy_u8PinNumber >= PIN0) && (Copy_u8PinNumber <= PIN15))
    {
        switch(Copy_u8PortName)
        {
            case GPIOA:
                if(Copy_u8PinValue == GPIO_HIGH)
                {
                    SET_BIT(GPIOA_ODR, Copy_u8PinNumber);
                }
                else if(Copy_u8PinValue == GPIO_LOW)
                {
                    CLR_BIT(GPIOA_ODR, Copy_u8PinNumber);
                }
            break;
            
            case GPIOB:
                if(Copy_u8PinValue == GPIO_HIGH)
                {
                    SET_BIT(GPIOB_ODR, Copy_u8PinNumber);
                }
                else if(Copy_u8PinValue == GPIO_LOW)
                {
                    CLR_BIT(GPIOB_ODR, Copy_u8PinNumber);
                }
            break;
            
            case GPIOC:
                if(Copy_u8PinValue == GPIO_HIGH)
                {
                    SET_BIT(GPIOC_ODR, Copy_u8PinNumber);
                }
                else if(Copy_u8PinValue == GPIO_LOW)
                {
                    CLR_BIT(GPIOC_ODR, Copy_u8PinNumber);
                }
            break;
        }
    }
    else
    {
        /* Display Error */
    }
}



u8 GPIO_u8GetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber)
{
    u8 Local_u8PinState;
    if((Copy_u8PinNumber >= PIN0) && (Copy_u8PinNumber <= PIN15))
    {
        switch(Copy_u8PortName)
        {
            case GPIOA:
                Local_u8PinState = GET_BIT(GPIOA_IDR, Copy_u8PinNumber);
            break;
            
            case GPIOB:
                Local_u8PinState = GET_BIT(GPIOB_IDR, Copy_u8PinNumber);
            break;
            
            case GPIOC:
                Local_u8PinState = GET_BIT(GPIOC_IDR, Copy_u8PinNumber);
            break;
        }
    }
    else
    {
        /*Display Error*/
    }
    return Local_u8PinState;
}
