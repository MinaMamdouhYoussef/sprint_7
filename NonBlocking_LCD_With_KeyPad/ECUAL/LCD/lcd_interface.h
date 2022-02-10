/*
 *  Author: Mina Mamdouh Youssef
 *  Driver: LCD
 *  Layer arch : ECUAL
 *  Created on: Jan 22, 2022
 *	version:1
 *
 */

#ifndef __LCD__INTERFACE__
#define __LCD__INTERFACE__


#define u8_LCD_INTIAL_1st_WAITING_TIME_MS				50
#define u8_LCD_DEFAULT_WAITING_TIME_MS					10




#define u8_LCD_RS										u8_DIO_PIN1
#define u8_LCD_RW										u8_DIO_PIN2
#define u8_LCD_E										u8_DIO_PIN3
#define u8_LCD_D4										u8_DIO_PIN4
#define u8_LCD_D5										u8_DIO_PIN5
#define u8_LCD_D6										u8_DIO_PIN6
#define u8_LCD_D7										u8_DIO_PIN7
	
#define u8_LCD_D0_BIT									0									
#define u8_LCD_D1_BIT									1									
#define u8_LCD_D2_BIT									2									
#define u8_LCD_D3_BIT									3								
#define u8_LCD_D4_BIT									4									
#define u8_LCD_D5_BIT									5									
#define u8_LCD_D6_BIT									6									
#define u8_LCD_D7_BIT									7									

#define u8_LCD_INTIALIZING_VAR 							0
#define u8_LCD_CONVERT_NUM_TO_ASCII						'0'
#define u8_LCD_INTIALIZING_WEIGHT_VAR					1
#define u8_LCD_INTIALIZING_COMMAND1						0x3
#define u8_LCD_INTIALIZING_COMMAND2						0x2
#define u8_LCD_INTIALIZING_SINGLE_LINE_DIS_COM			0x20
#define u8_LCD_INTIALIZING_2LINE_DIS_COMMAND			0x28
#define u8_LCD_INTIALIZING_COMMAND4						0x08
#define u8_LCD_INTIALIZING_COMMAND5						0x01
#define u8_LCD_INTIALIZING_COMMAND6						0x06
#define u8_LCD_INTIALIZING_COMMAND7						0x0C

#define u8_LCD_TRUE										1
#define u8_LCD_FALSE									0

//Commands user used with LCD_voidsendCommand function.
#define u8_LCD_DISPLAY_CLEAR      						0x01
#define u8_LCD_DISPLAY_CURSOR_ON     					0x0E
#define u8_LCD_DISPLAY_ON_CURSOR_OFF 					0x0C
#define u8_LCD_LEFT										0x10
#define u8_LCD_RIGHT									0x14

#define u8_LCD_1ST_INTIALIZING_COM						0b00110000
#define u8_LCD_2ND_INTIALIZING_COM						0b00110000


#define u8_LCD_NOK										20
#define u8_LCD_OK										21


uint8_t LCD_u8Init(void) ;
uint8_t LCD_u8sendCommand(uint8_t u8_WantedCommand) ;
uint8_t LCD_u8sendData(uint8_t u8_WantedCommand) ;
void LCD_voidsendCommandData(uint8_t u8_WantedCommand,uint8_t u8_SetRsVal,uint8_t u8_SetRwVal) ;
void LCD_voidInit(void) ;






#endif
