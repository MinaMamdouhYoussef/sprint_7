/*
 *  Author: Mina Mamdouh Youssef
 *  Driver: KEYPAD
 *  Layer arch : ECUAL
 *	Modified on : Feb 8, 2022
 *  Created on: Jan 17, 2022
 *	version: 2
 *
 */
 
 
#ifndef __KEYPAD__INTERFACE__
#define __KEYPAD__INTERFACE__

#define u8_KEYPAD_PORT											u8_DIO_PORTC
				
#define u8_KEYPAD_ROW1											u8_DIO_PIN2
#define u8_KEYPAD_ROW2                          				u8_DIO_PIN3
#define u8_KEYPAD_ROW3                          				u8_DIO_PIN4
#define u8_KEYPAD_COL1                          				u8_DIO_PIN5
#define u8_KEYPAD_COL2                          				u8_DIO_PIN6
#define u8_KEYPAD_COL3                          				u8_DIO_PIN7
				
#define u8_KEYPAD_PRESSED										u8_DIO_PIN_LOW
#define u8_KEYPAD_NOT_PRESSED									u8_DIO_PIN_HIGH

#define u8_KEYPAD_ALL_KEYS_NOT_PRESSED							20
#define u8_KEYPAD_OK											50	
#define u8_KEYPAD_NOK											51
#define u8_KEYPAD_INVALID_TO_USE								52
#define u8_KEYPAD_VALID_TO_USE									53
#define u8_KEYPAD_DEBOUNCING_TIME								20

void KEYPAD_voidInit(void) ;
uint8_t KEYPAD_u8GetKeyNum(uint8_t* pu8_ReturnKeyNumInASCII)  ;

#endif
