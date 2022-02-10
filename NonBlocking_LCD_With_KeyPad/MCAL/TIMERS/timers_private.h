/*
 *  Author: Mina Mamdouh Youssef
 *  Driver: Timer0 , Timer 2
 *  Layer arch : MCAL
 *  Created on: Feb 9, 2022
 *  Modified on : Jan 15, 2022
 *	version:4
 *
 */


#ifndef __TIMERS__PRIVATE__
#define __TIMERS__PRIVATE__



//TIMER CONFIG MODES
#define u8_NORMAL_MODE										1
#define u8_CTC_MODE											3



//TCCR0 BIT NAMES 
#define u8_FOC0_BIT											7
#define u8_WGM00_BIT										6
#define u8_COM00_BIT										5
#define u8_COM01_BIT										4
#define u8_WGM01_BIT										3
#define u8_CS02_BIT											2
#define u8_CS01_BIT											1
#define u8_CS00_BIT											0

//TIFR BIT NAMES 
#define u8_OCF0_BIT											1
#define u8_TOV0_BIT											0

//TIMSK BIT NAMES
#define u8_OCIE0_BIT										1
#define u8_TOIE0_BIT										0

#define u8_NUM_OF_COUNTS_FOR_250_uS_with_8_pre 				250
#define u8_MAX_TIMER0_COUNTS								255
#define u8_INTIALIZING_TIMER2_COUNTER						0
#define u8_NUMBER_OF_COUNTS_TO_COMP_1mS_with_8_pre			4



//TCCR2 BIT NAMES
#define u8_FOC2_BIT											7
#define u8_WGM20_BIT										6
#define u8_COM20_BIT										5
#define u8_COM21_BIT										4
#define u8_WGM21_BIT										3
#define u8_CS22_BIT											2
#define u8_CS21_BIT											1
#define u8_CS20_BIT											0

//TIFR BIT NAMES
#define u8_OCF2_BIT											7
#define u8_TOV2_BIT											6

//TIMSK BIT NAMES
#define u8_OCIE2_BIT										7
#define u8_TOIE2_BIT										6



#define u8_NO_CLK_TIMER_STOP             				    8
#define u8_INTERNAL_CLK_NO_PRE           				    9
#define u8_INTERNAL_CLK_PRE_8						    	10
#define u8_INTERNAL_CLK_PRE_64								11
#define u8_INTERNAL_CLK_PRE_256								12
#define u8_INTERNAL_CLK_PRE_1024							13
#define u8_EXTERNAL_CLK_FALLING								14
#define u8_EXTERNAL_CLK_RISING								15


#define u8_OC0_DISCONNECTED									16
#define u8_OC0_CLEAR_ON_COMPARE_MATCH						17
#define u8_OC0_SET_ON_COMPARE_MATCH	  						18
#define u8_TOGGLE_ON_COMPARE_MATCH							19



#define u8_OC2_DISCONNECTED									20
#define u8_OC2_CLEAR_ON_COMPARE_MATCH						21
#define u8_OC2_SET_ON_COMPARE_MATCH	  						22





static void TIMER0_voidIntWaitControlFlagCount(void) ;
static void TIMER2_voidIntWaitControlFlagCount(void) ;


#endif
