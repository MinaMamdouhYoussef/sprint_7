#ifndef __LED__INTERFACE__
#define __LED__INTERFACE__

#define u8_LED_PORT 					   u8_DIO_PORTB

#define u8_LED0							   u8_DIO_PIN4
#define u8_LED1                            u8_DIO_PIN5
#define u8_LED2                            u8_DIO_PIN6
#define u8_LED3                            u8_DIO_PIN7


#define u8_LED_OK							4
#define u8_LED_NOK							5

#define u8_LED_ON							u8_DIO_PIN_HIGH
#define u8_LED_OFF							u8_DIO_PIN_LOW


void LED_voidInit(void) ;
uint8_t LED_u8On(uint8_t u8_LedNum)   ;
uint8_t LED_u8Off(uint8_t u8_LedNum)  ;
uint8_t LED_u8Tog(uint8_t u8_LedNum)  ;




#endif
