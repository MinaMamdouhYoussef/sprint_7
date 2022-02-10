/*
 *  Author: Mina Mamdouh Youssef
 *  Driver: KEYPAD
 *  Layer arch : ECUAL
 *	Modified on : Feb 8, 2022
 *  Created on: Jan 17, 2022
 *	version: 2
 *
 */
 
#ifndef __KEYPAD__PRIVATE__
#define __KEYPAD__PRIVATE__


				
#define u8_KEYPAD_INTIALIZING_VAR								0
#define u16_KEYPAD_MAX_DEBOUNCE_SUCCESSIVE_COUNT					50
#define u16_KEYPAD_MIN_DEBOUNCE_SUCCESSIVE_COUNT					20

#define u8_KEYPAD_ROW_NOT_PRESSED								21
#define u8_KEYPAD_COL_NOT_PRESSED								22

static void KEYPAD_voidcheckedIfNotPressed(uint8_t* pu8_PressedNum) ;



#endif
