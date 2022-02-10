/*
 * main.c
 *
 *  Created on: Feb 9, 2022
 *      Author: CompuSity
 */
/*
 * KEYPAD_notBlockingTestmain.c
 *
 *  Created on: Feb 8, 2022
 *      Author: CompuSity
 */
/*

#include "LIBRARY/primitive_data_types.h"
#include "LIBRARY/atmega32_registers.h"

#include "LIBRARY/BIT_MATH.h"
#include "MCAL/DIO/dio_interface.h"
#include "ECUAL/LED/led_interface.h"
#include "ECUAL/KEYPAD_non_blocking/keypad_interface.h"

int main(void)
{
	uint8_t u8_KeyState ,u8_KeyVal = 0  ;
	SET_BIT(Ru8_SREG , 7); // set global interrupt
	LED_voidInit() ;
	KEYPAD_voidInit() ;

	while(1)
	{
		u8_KeyState = KEYPAD_u8GetKeyNum(&u8_KeyVal) ;
		if(u8_KeyState==u8_KEYPAD_OK)
		{
			switch(u8_KeyVal)

			{
			case 1:
					LED_u8On(u8_LED0) ;
					LED_u8Off(u8_LED1) ;
					LED_u8Off(u8_LED2) ;
					LED_u8Off(u8_LED3) ;
					break ;
			case 2:
					LED_u8Off(u8_LED0) ;
					LED_u8On(u8_LED1) ;
					LED_u8Off(u8_LED2) ;
					LED_u8Off(u8_LED3) ;
					break ;
			case 3:
					LED_u8On(u8_LED0) ;
					LED_u8On(u8_LED1) ;
					LED_u8Off(u8_LED2) ;
					LED_u8Off(u8_LED3) ;
					break ;
			case 4:
					LED_u8Off(u8_LED0) ;
					LED_u8Off(u8_LED1) ;
					LED_u8On(u8_LED2) ;
					LED_u8Off(u8_LED3) ;
					break ;
			case 5:
					LED_u8On(u8_LED0) ;
					LED_u8Off(u8_LED1) ;
					LED_u8On(u8_LED2) ;
					LED_u8Off(u8_LED3) ;
					break ;
			case 6:
					LED_u8Off(u8_LED0) ;
					LED_u8On(u8_LED1) ;
					LED_u8On(u8_LED2) ;
					LED_u8Off(u8_LED3) ;
					break ;
			case 7:
					LED_u8On(u8_LED0) ;
					LED_u8On(u8_LED1) ;
					LED_u8On(u8_LED2) ;
					LED_u8Off(u8_LED3) ;
					break ;
			case 8:
					LED_u8Off(u8_LED0) ;
					LED_u8Off(u8_LED1) ;
					LED_u8Off(u8_LED2) ;
					LED_u8On(u8_LED3) ;
					break ;
			case 9:
					LED_u8On(u8_LED0) ;
					LED_u8Off(u8_LED1) ;
					LED_u8Off(u8_LED2) ;
					LED_u8On(u8_LED3) ;
					break ;
			}
		}

	}
}








*/


#include "LIBRARY/primitive_data_types.h"
#include "LIBRARY/BIT_MATH.h"
#include "LIBRARY/atmega32_registers.h"
#include "MCAL/DIO/dio_interface.h"
#include "MCAL/TIMERS/timers_interface.h"
#include "ECUAL/LCD/lcd_interface.h"
#include "ECUAL/KEYPAD_non_blocking/keypad_interface.h"
#include "ECUAL/LED/led_interface.h"

int main(void)
{
	uint8_t PressedKeyNum = 0,u8_lcdValstate1,state2,state1;
	uint8_t tempKeyNum = 0 ;
	uint8_t ValidKeyPadVal = u8_KEYPAD_NOK ;
	KEYPAD_voidInit() ;
	SET_BIT(Ru8_SREG , 7); // set global interrupt
	state1 = LCD_u8Init() ;
	Ru8_DDRD =0xFF ;
	while(1)
	{
		if(state1== u8_LCD_NOK )
		{
			state1 = LCD_u8Init() ;
		}
		else
		{
			state2 = KEYPAD_u8GetKeyNum((uint8_t*)(&PressedKeyNum)) ;
			if(state2 == u8_KEYPAD_OK)
			{
				if(PressedKeyNum != u8_KEYPAD_ALL_KEYS_NOT_PRESSED)
				{
					tempKeyNum=PressedKeyNum+'0' ;
					ValidKeyPadVal = u8_KEYPAD_OK ;
				}
			}

			if(ValidKeyPadVal == u8_KEYPAD_OK)
			{
				u8_lcdValstate1 = LCD_u8sendData(tempKeyNum) ;
				if(u8_lcdValstate1== u8_LCD_OK)
				{
					ValidKeyPadVal = u8_KEYPAD_NOK ;

				}
			}


		}

	}

	return 1 ;
}
