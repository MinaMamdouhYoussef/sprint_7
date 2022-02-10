

#include "LIBRARY/primitive_data_types.h"
#include "LIBRARY/BIT_MATH.h"
#include "LIBRARY/atmega32_registers.h"
#include "MCAL/DIO/dio_interface.h"
#include "MCAL/TIMERS/timers_interface.h"
#include "ECUAL/LCD/lcd_interface.h"
#include "ECUAL/KEYPAD_non_blocking/keypad_interface.h"
#include "ECUAL/LED/led_interface.h"


#define u8_INTIAL_VAL 					0
#define u8_SREG_GIE_BIT7				7
int main(void)
{
	uint8_t u8_PressedKeyNum = u8_KEYPAD_ALL_KEYS_NOT_PRESSED ;
	uint8_t	u8_lcdDatastate = u8_LCD_NOK ;
	uint8_t u8_keyPadState = u8_KEYPAD_NOK;
	uint8_t u8_lcdInitState = u8_LCD_NOK ;
	uint8_t u8_tempKeyNum = u8_INTIAL_VAL ;
	uint8_t ValidKeyPadVal = u8_KEYPAD_NOK ;
	KEYPAD_voidInit() ;
	SET_BIT(Ru8_SREG , u8_SREG_GIE_BIT7); // set global interrupt
	u8_lcdInitState = LCD_u8Init() ;
	while(1)
	{
		if(u8_lcdInitState== u8_LCD_NOK )
		{
			u8_lcdInitState = LCD_u8Init() ;
		}
		else
		{
			u8_keyPadState = KEYPAD_u8GetKeyNum((uint8_t*)(&u8_PressedKeyNum)) ;
			if(u8_keyPadState == u8_KEYPAD_OK)
			{
				if(u8_PressedKeyNum != u8_KEYPAD_ALL_KEYS_NOT_PRESSED)
				{
					u8_tempKeyNum=u8_PressedKeyNum + '0' ;
					ValidKeyPadVal = u8_KEYPAD_OK ;
				}
			}

			if(ValidKeyPadVal == u8_KEYPAD_OK)
			{
				u8_lcdDatastate = LCD_u8sendData(u8_tempKeyNum) ;
				if(u8_lcdDatastate== u8_LCD_OK)
				{
					ValidKeyPadVal = u8_KEYPAD_NOK ;

				}
			}


		}

	}

	return 1 ;
}
