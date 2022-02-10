/*
 *  Author: Mina Mamdouh Youssef
 *  Driver: Timer0 , Timer 2
 *  Layer arch : MCAL
 *  Created on: Feb 9, 2022
 *  Modified on : Jan 15, 2022
 *	version:4
 *
 */


		
#ifndef __timers__interface__		
#define __timers__interface__		

#define u8_OK												1
#define u8_NOK												0
		
		
#define u8_MAX_8BIT_REG_HOLD								255
		



#define u8_TIMER0_OVER_FLOW									24
#define u8_TIMER0_COMPARE_ON_MATCH							25
#define u8_TIMER0_FLAG_NOT_USED								26
#define u8_TIMER0_FLAG_USED									27



#define u8_TIMER2_OVER_FLOW									31
#define u8_TIMER2_COMPARE_ON_MATCH							32
#define u8_TIMER2_FLAG_NOT_USED								33
#define u8_TIMER2_FLAG_USED									34


#define u8_WAITING_FIRST_INT_WAIT_NOT_BEGIN					28
#define u8_FINISH_INTERRUPT_WAITING							29
#define u8_BEGIN_INTERRUPT_WAITING							30
#define u8_INTIAL_COUNTER_VAL								0
#define u8_Flag_RAISED										1




uint8_t TIMERS_u8ClearIntFlag(uint8_t u8_wantedIntClearFlag) ;
uint8_t TIMERS_u8GetIntFlag(uint8_t u8_wantedIntClearFlag,uint8_t* pu8_retturnIntFlag) ;
uint8_t TIMERS_u8IntModesEn(uint8_t u8_wantedIntModeEn) ;
uint8_t TIMERS_u8IntModesDis(uint8_t u8_wantedIntModeDis) ;


void TIMER0_voidInit(void);
uint8_t TIMER0_u8StartWithclockAndPrescalerSelect(uint8_t u8_preScallerVal) ;
uint8_t Timer0_u8setCompareRegTicksBeforeOV(uint8_t u8_wantedTicksToCompare) ;
uint8_t Timer0_u8setOverFlowRegTicksBeforeOV(uint8_t u8_wantedTicksBeforeOV) ;
uint8_t TIMER0_u8setCallBack(uint8_t u8_wantedISRModeToSet,void(*ISRFuncToSet)(void))  ;
void    TIMER0_voidstop(void) ;
uint8_t TIMER0_u8BusyWaitMS(uint32_t u32_BusyTimeInMilliSec) ;
uint8_t TIMER0_u8BusyWaitUS(uint32_t u32_BusyTimeInMicroSec) ; 
uint8_t TIMER0_u8InterruptWait(uint32_t u32_BusyTimeInMilliSec) ;
uint8_t TIMER0_u8GetIntWaitStatus(void) ;


void TIMER2_voidInit(void);
uint8_t TIMER2_u8StartWithclockAndPrescalerSelect(uint8_t u8_preScallerVal) ;
uint8_t Timer2_u8setCompareRegTicksBeforeOV(uint8_t u8_wantedTicksToCompare) ;
uint8_t Timer2_u8setOverFlowRegTicksBeforeOV(uint8_t u8_wantedTicksBeforeOV) ;
uint8_t TIMER2_u8setCallBack(uint8_t u8_wantedISRModeToSet,void(*ISRFuncToSet)(void))  ;
void    TIMER2_voidstop(void) ;
uint8_t TIMER2_u8BusyWaitMS(uint32_t u32_BusyTimeInMilliSec) ;
uint8_t TIMER2_u8BusyWaitUS(uint32_t u32_BusyTimeInMicroSec) ;
uint8_t TIMER2_u8InterruptWait(uint32_t u32_BusyTimeInMilliSec) ;
uint8_t TIMER2_u8GetIntWaitStatus(void) ;



#endif
