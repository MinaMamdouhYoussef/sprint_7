/*
 *  Author: Mina Mamdouh Youssef
 *  Driver: Timer0 , Timer 2
 *  Layer arch : MCAL
 *  Created on: Feb 9, 2022
 *  Modified on : Jan 15, 2022
 *	version:4
 *
 */


#ifndef __TIMERS__CONFIG__
#define __TIMERS__CONFIG__
#include "timers_private.h"
/*choose one of timer 0 modes :-
 *1-u8_NORMAL_MODE
 *2-u8_CTC_MODE
 */
#define u8_TIMER0_MODE_CONFIG 			    		u8_CTC_MODE

/* choose clock source:-
 *1-u8_NO_CLK_TIMER_STOP
 *2-u8_INTERNAL_CLK_NO_PRE
 *3-u8_INTERNAL_CLK_PRE_8
 *4-u8_INTERNAL_CLK_PRE_64
 *5-u8_INTERNAL_CLK_PRE_256
 *6-u8_INTERNAL_CLK_PRE_1024
 *7-u8_EXTERNAL_CLK_FALLING
 *8-u8_EXTERNAL_CLK_RISING
 */
#define u8_TIMER0_1_CLOCK_SELECT					u8_INTERNAL_CLK_PRE_8

/*OC0 config if one of pwm modes set:-
 *1-u8_OC0_DISCONNECTED
 *2-u8_OC0_CLEAR_ON_COMPARE_MATCH
 *3-u8_OC0_SET_ON_COMPARE_MATCH
 */
#define u8_TIMER0_COMP_MATCH_PWM_CONFIG				u8_OC0_DISCONNECTED

/*OC0 config if one of non-pwm modes set:-
 *1-u8_OC0_DISCONNECTED
 *2-u8_TOGGLE_ON_COMPARE_MATCH
 *3-u8_OC0_CLEAR_ON_COMPARE_MATCH
 *4-u8_OC0_SET_ON_COMPARE_MATCH
 */
#define u8_TIMER0_COMP_MATCH_NON_PWM_CONFIG 		u8_OC0_DISCONNECTED


/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/*choose one of timer 2 modes :-
 *1-u8_NORMAL_MODE
 *2-u8_CTC_MODE
 */
#define u8_TIMER2_MODE_CONFIG 			    		u8_CTC_MODE

/* choose clock source:-
 *1-u8_NO_CLK_TIMER_STOP
 *2-u8_INTERNAL_CLK_NO_PRE
 *3-u8_INTERNAL_CLK_PRE_8
 *4-u8_INTERNAL_CLK_PRE_64
 *5-u8_INTERNAL_CLK_PRE_256
 *6-u8_INTERNAL_CLK_PRE_1024
 *7-u8_EXTERNAL_CLK_FALLING
 *8-u8_EXTERNAL_CLK_RISING
 */
#define u8_TIMER2_CLOCK_SELECT					u8_INTERNAL_CLK_PRE_8

/*OC2 config if one of pwm modes set:-
 *1-u8_OC2_DISCONNECTED
 *2-u8_OC2_CLEAR_ON_COMPARE_MATCH
 *3-u8_OC2_SET_ON_COMPARE_MATCH
 */
#define u8_TIMER2_COMP_MATCH_PWM_CONFIG				u8_OC2_DISCONNECTED

/*OC2 config if one of non-pwm modes set:-
 *1-u8_OC2_DISCONNECTED
 *2-u8_TOGGLE_ON_COMPARE_MATCH
 *3-u8_OC2_CLEAR_ON_COMPARE_MATCH
 *4-u8_OC2_SET_ON_COMPARE_MATCH
 */
#define u8_TIMER2_COMP_MATCH_NON_PWM_CONFIG 		u8_OC2_DISCONNECTED




#endif
