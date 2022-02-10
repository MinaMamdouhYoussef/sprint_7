/*
 *  Author: Mina Mamdouh Youssef
 *  Driver: LCD
 *  Layer arch : ECUAL
 *  Created on: Jan 22, 2022
 *	version:1
 *
 */

#include "../../LIBRARY/primitive_data_types.h"
#include "../../LIBRARY/BIT_MATH.h"
#include "../../LIBRARY/atmega32_registers.h"
#include "../../MCAL/TIMERS/timers_interface.h"
#include "../../MCAL/DIO/dio_interface.h"
#include "lcd_interface.h"



typedef enum
{
	LCD_data_state1,
	LCD_data_state2,
	LCD_data_state3,
	LCD_data_state4,
	LCD_data_state5,
	LCD_data_ready_state
}LCD_SEND_DATA_STATE_t;


/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////


typedef enum
{
	LCD_command_state1,
	LCD_command_state2,
	LCD_command_state3,
	LCD_command_state4,
	LCD_command_state5,
	LCD_command_ready_state
}LCD_SEND_COMMAND_STATE_t;


/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
typedef enum
{
	LCD_timer_Init,
	LCD_initialize_state1,
	LCD_initialize_state2,
	LCD_initialize_state3,
	LCD_initialize_state4,
	LCD_initialize_state5,
	LCD_initialize_state6,
	LCD_initialize_state7,
	LCD_initialize_state8,
	LCD_initialize_state9,
	LCD_initialize_state10,
	LCD_initializing_finished
}LCD_INIT_STATE_t;


/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////

LCD_INIT_STATE_t LCD_stateInit = LCD_timer_Init ; 
LCD_SEND_COMMAND_STATE_t LCD_stateCommand = LCD_command_state1 ; 
LCD_SEND_DATA_STATE_t LCD_stateData = LCD_data_ready_state ;
uint8_t LCD_u8Init(void)
{

	uint8_t u8_timerState, u8_returnState =u8_LCD_OK ;
	uint8_t u8_commState ;
	static uint8_t u8_commFinished = u8_LCD_TRUE ;
	if(LCD_stateInit != LCD_initializing_finished)
	{
		u8_returnState =u8_LCD_NOK ;

		switch(LCD_stateInit)
		{
			case LCD_timer_Init:
					TIMER0_voidInit();
					//intialing pins direction and values
					DIO_u8SetPinDir(u8_DIO_PORTA,u8_LCD_RS,u8_DIO_OUTPUT_PIN) ;
					DIO_u8SetPinDir(u8_DIO_PORTA,u8_LCD_RW,u8_DIO_OUTPUT_PIN) ;
					DIO_u8SetPinDir(u8_DIO_PORTA,u8_LCD_E,u8_DIO_OUTPUT_PIN) ;
					DIO_u8SetPinDir(u8_DIO_PORTA,u8_LCD_D4,u8_DIO_OUTPUT_PIN) ;
					DIO_u8SetPinDir(u8_DIO_PORTA,u8_LCD_D5,u8_DIO_OUTPUT_PIN) ;
					DIO_u8SetPinDir(u8_DIO_PORTA,u8_LCD_D6,u8_DIO_OUTPUT_PIN) ;
					DIO_u8SetPinDir(u8_DIO_PORTA,u8_LCD_D7,u8_DIO_OUTPUT_PIN) ;
					TIMER0_u8InterruptWait(u8_LCD_INTIAL_1st_WAITING_TIME_MS);
					LCD_stateInit = LCD_initialize_state1 ;

					break ; 
			case LCD_initialize_state1:
					u8_timerState = TIMER0_u8GetIntWaitStatus() ;  
					if(u8_timerState==u8_FINISH_INTERRUPT_WAITING)
					{
						//INTIALIZING COMMANDS TO LCD
						u8_commState=LCD_u8sendCommand(u8_LCD_INTIALIZING_COMMAND1) ;
						if(u8_commState==u8_LCD_NOK)
						{
							u8_commFinished = u8_LCD_FALSE ;
						}
						else
						{

							u8_commFinished = u8_LCD_TRUE ;
						}

					}
					if(u8_commFinished == u8_LCD_TRUE)
					{
						u8_commFinished = u8_LCD_FALSE ;
						LCD_stateInit = LCD_initialize_state2 ;
						TIMER0_u8InterruptWait(u8_LCD_DEFAULT_WAITING_TIME_MS) ;

					}
					break;
	
			case LCD_initialize_state2:
					u8_timerState = TIMER0_u8GetIntWaitStatus() ;  
					if(u8_timerState==u8_FINISH_INTERRUPT_WAITING)
					{
						    u8_commState = LCD_u8sendCommand(u8_LCD_INTIALIZING_COMMAND1) ;
							if(u8_commState==u8_LCD_NOK)
							{
								u8_commFinished = u8_LCD_FALSE ;
							}
							else
							{
								u8_commFinished = u8_LCD_TRUE ;
							}

					}
					if(u8_commFinished == u8_LCD_TRUE)
					{

						LCD_stateInit = LCD_initialize_state3 ;
						TIMER0_u8InterruptWait(u8_LCD_DEFAULT_WAITING_TIME_MS) ;
						u8_commFinished = u8_LCD_FALSE ;

					}
					break;
	
			case LCD_initialize_state3:
					u8_timerState = TIMER0_u8GetIntWaitStatus() ;  
					if(u8_timerState==u8_FINISH_INTERRUPT_WAITING)
					{
						u8_commState = LCD_u8sendCommand(u8_LCD_INTIALIZING_COMMAND1) ;

						if(u8_commState==u8_LCD_NOK)
						{
							u8_commFinished = u8_LCD_FALSE ;
						}
						else
						{
							u8_commFinished = u8_LCD_TRUE ;
						}
					}

					if(u8_commFinished == u8_LCD_TRUE)
					{
						LCD_stateInit = LCD_initialize_state4 ;
						TIMER0_u8InterruptWait(u8_LCD_DEFAULT_WAITING_TIME_MS) ;
						u8_commFinished = u8_LCD_FALSE ;

					}
					break;
	
			case LCD_initialize_state4:
					u8_timerState = TIMER0_u8GetIntWaitStatus() ;  
					if(u8_timerState==u8_FINISH_INTERRUPT_WAITING)
					{
						u8_commState = LCD_u8sendCommand(u8_LCD_INTIALIZING_COMMAND2) ;
						if(u8_commState==u8_LCD_NOK)
						{
							u8_commFinished = u8_LCD_FALSE ;
						}
						else
						{
							u8_commFinished = u8_LCD_TRUE ;
						}

					}

					if(u8_commFinished == u8_LCD_TRUE)
					{
						LCD_stateInit = LCD_initialize_state5 ;
						TIMER0_u8InterruptWait(u8_LCD_DEFAULT_WAITING_TIME_MS) ;
						u8_commFinished = u8_LCD_FALSE ;
					}
					break;
	
			case LCD_initialize_state5:
					u8_timerState = TIMER0_u8GetIntWaitStatus() ;  
					if(u8_timerState==u8_FINISH_INTERRUPT_WAITING)
					{
						u8_commState = LCD_u8sendCommand(u8_LCD_INTIALIZING_SINGLE_LINE_DIS_COM) ;
						if(u8_commState==u8_LCD_NOK)
						{
							u8_commFinished = u8_LCD_FALSE ;
						}
						else
						{
							u8_commFinished = u8_LCD_TRUE ;
						}

					}

					if(u8_commFinished == u8_LCD_TRUE)
					{
						LCD_stateInit = LCD_initialize_state6 ;
						TIMER0_u8InterruptWait(u8_LCD_DEFAULT_WAITING_TIME_MS) ;
						u8_commFinished = u8_LCD_FALSE ;

					}
					break;
	
			case LCD_initialize_state6:
					u8_timerState = TIMER0_u8GetIntWaitStatus() ;  
	
					if(u8_timerState==u8_FINISH_INTERRUPT_WAITING)
					{
						u8_commState = LCD_u8sendCommand(u8_LCD_INTIALIZING_COMMAND4) ;
						if(u8_commState==u8_LCD_NOK)
						{
							u8_commFinished = u8_LCD_FALSE ;
						}
						else
						{
							u8_commFinished = u8_LCD_TRUE ;
						}
					}

					if(u8_commFinished == u8_LCD_TRUE)
					{
						LCD_stateInit = LCD_initialize_state7 ;
						TIMER0_u8InterruptWait(u8_LCD_DEFAULT_WAITING_TIME_MS) ;
						u8_commFinished = u8_LCD_FALSE ;

					}
					break;
	
			case LCD_initialize_state7:
					u8_timerState = TIMER0_u8GetIntWaitStatus() ;  
	
					if(u8_timerState==u8_FINISH_INTERRUPT_WAITING)
					{
						u8_commState = LCD_u8sendCommand(u8_LCD_INTIALIZING_COMMAND5) ;

						if(u8_commState==u8_LCD_NOK)
						{
							u8_commFinished = u8_LCD_FALSE ;
						}
						else
						{
							u8_commFinished = u8_LCD_TRUE ;
						}


					}

					if  (u8_commFinished == u8_LCD_TRUE)
					{
						LCD_stateInit = LCD_initialize_state8 ;
						TIMER0_u8InterruptWait(u8_LCD_DEFAULT_WAITING_TIME_MS) ;
						u8_commFinished = u8_LCD_FALSE ;

					}
					break;
	
			case LCD_initialize_state8:
					u8_timerState = TIMER0_u8GetIntWaitStatus() ;  
	
					if(u8_timerState==u8_FINISH_INTERRUPT_WAITING)
					{
						u8_commState = LCD_u8sendCommand(u8_LCD_INTIALIZING_COMMAND6) ;

						if(u8_commState==u8_LCD_NOK)
						{
							u8_commFinished = u8_LCD_FALSE ;
						}
						else
						{
							u8_commFinished = u8_LCD_TRUE ;
						}

					}

					if(u8_commFinished == u8_LCD_TRUE)
					{
						LCD_stateInit = LCD_initialize_state9 ;
						TIMER0_u8InterruptWait(u8_LCD_DEFAULT_WAITING_TIME_MS) ;
						u8_commFinished = u8_LCD_FALSE ;
					}
						
					break;
	
			case LCD_initialize_state9:
					u8_timerState = TIMER0_u8GetIntWaitStatus() ;  
					if(u8_timerState==u8_FINISH_INTERRUPT_WAITING)
					{
						u8_commState=LCD_u8sendCommand(u8_LCD_INTIALIZING_COMMAND7) ;

						if(u8_commState==u8_LCD_NOK)
						{
							u8_commFinished = u8_LCD_FALSE ;
						}
						else
						{
							u8_commFinished = u8_LCD_TRUE ;
						}

					}

					if (u8_commFinished == u8_LCD_TRUE)
					{
						LCD_stateInit = LCD_initialize_state10 ;
						TIMER0_u8InterruptWait(u8_LCD_DEFAULT_WAITING_TIME_MS) ;
						u8_commFinished = u8_LCD_FALSE ;
					}
						
					break;
	
			case LCD_initialize_state10:
				u8_timerState = TIMER0_u8GetIntWaitStatus() ;
				if((u8_timerState==u8_FINISH_INTERRUPT_WAITING))
				{
					LCD_stateInit = LCD_initializing_finished ;
				}
					break;
			default:
				break ;
		}
	}
	
	
	return u8_returnState ; 
}


/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
 uint8_t LCD_u8sendCommand(uint8_t u8_WantedCommand)
{
	uint8_t u8_returnState = u8_LCD_NOK ,u8_timerState ;
	if(LCD_stateData == LCD_data_ready_state )
	{
		if(LCD_stateCommand == LCD_command_ready_state)
		{
			LCD_stateCommand = LCD_command_state1 ; 
		}
	
		switch(LCD_stateCommand)
		{
			case LCD_command_state1:
					
				u8_timerState = TIMER0_u8GetIntWaitStatus() ;  

				if(u8_timerState==u8_FINISH_INTERRUPT_WAITING)
				{
					DIO_u8SetPinVal(u8_DIO_PORTA,u8_LCD_E,u8_DIO_PIN_HIGH) ;
					DIO_u8SetPinVal(u8_DIO_PORTA,u8_LCD_RS,u8_DIO_PIN_LOW) ;
					DIO_u8SetPinVal(u8_DIO_PORTA,u8_LCD_RW,u8_DIO_PIN_LOW) ;
					/*SETTING HIGHER SIGNIFICANT BITS */
					TIMER0_u8InterruptWait(u8_LCD_DEFAULT_WAITING_TIME_MS) ;
					LCD_stateCommand = LCD_command_state2 ;

				}
				break ; 
					
			case LCD_command_state2:
			
				u8_timerState = TIMER0_u8GetIntWaitStatus() ;  
				
				if(u8_timerState==u8_FINISH_INTERRUPT_WAITING)
				{
					DIO_u8SetPinVal(u8_DIO_PORTA,u8_LCD_D7,GET_BIT(u8_WantedCommand,u8_LCD_D7_BIT));
					DIO_u8SetPinVal(u8_DIO_PORTA,u8_LCD_D6,GET_BIT(u8_WantedCommand,u8_LCD_D6_BIT));
					DIO_u8SetPinVal(u8_DIO_PORTA,u8_LCD_D5,GET_BIT(u8_WantedCommand,u8_LCD_D5_BIT)) ;
					DIO_u8SetPinVal(u8_DIO_PORTA,u8_LCD_D4,GET_BIT(u8_WantedCommand,u8_LCD_D4_BIT)) ;
					DIO_u8SetPinVal(u8_DIO_PORTA,u8_LCD_E,u8_DIO_PIN_LOW) ;
					TIMER0_u8InterruptWait(u8_LCD_DEFAULT_WAITING_TIME_MS) ;
					LCD_stateCommand = LCD_command_state3 ; 

				}
				break ; 
				
			case LCD_command_state3:
			
				u8_timerState = TIMER0_u8GetIntWaitStatus() ;  
	
				if(u8_timerState==u8_FINISH_INTERRUPT_WAITING)
				{
					/*SETTING LOWER SIGNIFICANT BITS */
					DIO_u8SetPinVal(u8_DIO_PORTA,u8_LCD_E,u8_DIO_PIN_HIGH) ;
					DIO_u8SetPinVal(u8_DIO_PORTA,u8_LCD_D7,GET_BIT(u8_WantedCommand,u8_LCD_D3_BIT));
					DIO_u8SetPinVal(u8_DIO_PORTA,u8_LCD_D6,GET_BIT(u8_WantedCommand,u8_LCD_D2_BIT));
					DIO_u8SetPinVal(u8_DIO_PORTA,u8_LCD_D5,GET_BIT(u8_WantedCommand,u8_LCD_D1_BIT)) ;
					DIO_u8SetPinVal(u8_DIO_PORTA,u8_LCD_D4,GET_BIT(u8_WantedCommand,u8_LCD_D0_BIT)) ;
					TIMER0_u8InterruptWait(u8_LCD_DEFAULT_WAITING_TIME_MS) ;
					LCD_stateCommand = LCD_command_state4 ; 

				}
				break ; 
			
			case LCD_command_state4:
					
				u8_timerState = TIMER0_u8GetIntWaitStatus() ;  
	
				if(u8_timerState==u8_FINISH_INTERRUPT_WAITING)
				{
					DIO_u8SetPinVal(u8_DIO_PORTA,u8_LCD_E,u8_DIO_PIN_LOW) ;
					TIMER0_u8InterruptWait(u8_LCD_DEFAULT_WAITING_TIME_MS) ;
					LCD_stateCommand = LCD_command_state5 ; 
				}
				break ; 
			case LCD_command_state5:
				
				u8_timerState = TIMER0_u8GetIntWaitStatus() ;  
	
				if(u8_timerState==u8_FINISH_INTERRUPT_WAITING)
				{
					LCD_stateCommand = LCD_command_ready_state ;
					u8_returnState = u8_LCD_OK ;
				}
				break ;
			default:
				break ;
		}
	}

	return u8_returnState ; 
	
}
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
 uint8_t LCD_u8sendData(uint8_t u8_WantedData)
{
	uint8_t u8_returnState = u8_NOK ,u8_timerState ; 
	if(LCD_stateCommand == LCD_command_ready_state && LCD_stateInit == LCD_initializing_finished)
	{
		if(LCD_stateData == LCD_data_ready_state)
		{
			LCD_stateData = LCD_data_state1 ; 
		}
	
		switch(LCD_stateData)
		{
			case LCD_data_state1:
					
				u8_timerState = TIMER0_u8GetIntWaitStatus() ;  
				
				if(u8_timerState==u8_FINISH_INTERRUPT_WAITING)
				{
					DIO_u8SetPinVal(u8_DIO_PORTA,u8_LCD_E,u8_DIO_PIN_HIGH) ;
					DIO_u8SetPinVal(u8_DIO_PORTA,u8_LCD_RS,u8_DIO_PIN_HIGH) ;
					DIO_u8SetPinVal(u8_DIO_PORTA,u8_LCD_RW,u8_DIO_PIN_LOW) ;
					/*SETTING HIGHER SIGNIFICANT BITS */
					TIMER0_u8InterruptWait(u8_LCD_DEFAULT_WAITING_TIME_MS) ;
					LCD_stateData = LCD_data_state2 ; 
				}
				break ; 
					
			case LCD_data_state2:
			
				u8_timerState = TIMER0_u8GetIntWaitStatus() ;  
				
				if(u8_timerState==u8_FINISH_INTERRUPT_WAITING)
				{
					DIO_u8SetPinVal(u8_DIO_PORTA,u8_LCD_D7,GET_BIT(u8_WantedData,u8_LCD_D7_BIT));
					DIO_u8SetPinVal(u8_DIO_PORTA,u8_LCD_D6,GET_BIT(u8_WantedData,u8_LCD_D6_BIT));
					DIO_u8SetPinVal(u8_DIO_PORTA,u8_LCD_D5,GET_BIT(u8_WantedData,u8_LCD_D5_BIT)) ;
					DIO_u8SetPinVal(u8_DIO_PORTA,u8_LCD_D4,GET_BIT(u8_WantedData,u8_LCD_D4_BIT)) ;
					DIO_u8SetPinVal(u8_DIO_PORTA,u8_LCD_E,u8_DIO_PIN_LOW) ;
					TIMER0_u8InterruptWait(u8_LCD_DEFAULT_WAITING_TIME_MS) ;
					LCD_stateData = LCD_data_state3 ; 
				}
				break ; 
				
			case LCD_data_state3:
			
				u8_timerState = TIMER0_u8GetIntWaitStatus() ;  
	
				if(u8_timerState==u8_FINISH_INTERRUPT_WAITING)
				{
					/*SETTING LOWER SIGNIFICANT BITS */
					DIO_u8SetPinVal(u8_DIO_PORTA,u8_LCD_E,u8_DIO_PIN_HIGH) ;
					DIO_u8SetPinVal(u8_DIO_PORTA,u8_LCD_D7,GET_BIT(u8_WantedData,u8_LCD_D3_BIT));
					DIO_u8SetPinVal(u8_DIO_PORTA,u8_LCD_D6,GET_BIT(u8_WantedData,u8_LCD_D2_BIT));
					DIO_u8SetPinVal(u8_DIO_PORTA,u8_LCD_D5,GET_BIT(u8_WantedData,u8_LCD_D1_BIT)) ;
					DIO_u8SetPinVal(u8_DIO_PORTA,u8_LCD_D4,GET_BIT(u8_WantedData,u8_LCD_D0_BIT)) ;
					TIMER0_u8InterruptWait(u8_LCD_DEFAULT_WAITING_TIME_MS) ;
					LCD_stateData = LCD_data_state4 ; 
	
				}
				break ; 
			
			case LCD_data_state4:
					
				u8_timerState = TIMER0_u8GetIntWaitStatus() ;  
	
				if(u8_timerState==u8_FINISH_INTERRUPT_WAITING)
				{
					DIO_u8SetPinVal(u8_DIO_PORTA,u8_LCD_E,u8_DIO_PIN_LOW) ;
					TIMER0_u8InterruptWait(u8_LCD_DEFAULT_WAITING_TIME_MS) ;
					LCD_stateData = LCD_data_state5 ; 
				}
				break ; 
			case LCD_data_state5:
				
				u8_timerState = TIMER0_u8GetIntWaitStatus() ;  
	
				if(u8_timerState==u8_FINISH_INTERRUPT_WAITING)
				{
					LCD_stateData = LCD_data_ready_state ;
					u8_returnState = u8_LCD_OK ;
				}
				break ;
			default:
				break ;
		}
	}

	return u8_returnState ; 
	
}

