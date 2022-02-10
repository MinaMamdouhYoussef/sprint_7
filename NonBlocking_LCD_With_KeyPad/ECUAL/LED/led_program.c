#include "../../LIBRARY/primitive_data_types.h"
#include "../../MCAL/DIO/dio_interface.h"
#include "led_interface.h"

void LED_voidInit(void)
{
	DIO_u8SetPinDir(u8_LED_PORT,u8_LED0,u8_DIO_OUTPUT_PIN)          ;
	DIO_u8SetPinDir(u8_LED_PORT,u8_LED1,u8_DIO_OUTPUT_PIN)          ;
	DIO_u8SetPinDir(u8_LED_PORT,u8_LED2,u8_DIO_OUTPUT_PIN)          ;
	DIO_u8SetPinDir(u8_LED_PORT,u8_LED3,u8_DIO_OUTPUT_PIN)          ;
	DIO_u8SetPinVal(u8_LED_PORT,u8_LED0,u8_DIO_PIN_LOW)          ;
	DIO_u8SetPinVal(u8_LED_PORT,u8_LED1,u8_DIO_PIN_LOW)          ;
	DIO_u8SetPinVal(u8_LED_PORT,u8_LED2,u8_DIO_PIN_LOW)          ;
	DIO_u8SetPinVal(u8_LED_PORT,u8_LED3,u8_DIO_PIN_LOW)          ;


}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

uint8_t LED_u8On(uint8_t u8_LedNum) 
{
	uint8_t u8_FlagError = u8_LED_OK ;
	if(u8_LedNum<=u8_LED3 && u8_LedNum >= u8_LED0)
	{ 
		DIO_u8SetPinVal(u8_LED_PORT,u8_LedNum,u8_LED_ON)    ;  
	}
	else 
	{
		u8_FlagError = u8_LED_NOK ;
	}
	
	return u8_FlagError ; 

}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

uint8_t LED_u8Off(uint8_t u8_LedNum)  
{
	uint8_t u8_FlagError = u8_LED_OK ;
	if(u8_LedNum<=u8_LED3 && u8_LedNum >= u8_LED0)
	{ 
		DIO_u8SetPinVal(u8_LED_PORT,u8_LedNum,u8_LED_OFF)    ;  
	}
	else 
	{
		u8_FlagError = u8_LED_NOK ;
	}
	
	return u8_FlagError ; 

}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

uint8_t LED_u8Tog(uint8_t u8_LedNum)  
{
	uint8_t u8_FlagError = u8_LED_OK ;
	if(u8_LedNum<=u8_LED3 && u8_LedNum >= u8_LED0)
	{ 
		DIO_u8TogPinVal(u8_LED_PORT,u8_LedNum)    ;  
	}
	else 
	{
		u8_FlagError = u8_LED_NOK ;
	}
	
	return u8_FlagError ; 

}
