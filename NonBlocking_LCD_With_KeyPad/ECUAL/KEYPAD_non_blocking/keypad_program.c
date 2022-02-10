/*
 *  Author: Mina Mamdouh Youssef
 *  Driver: KEYPAD
 *  Layer arch : ECUAL
 *	Modified on : Feb 8, 2022
 *  Created on: Jan 17, 2022
 *	version: 2
 *
 */
 
#include "../../LIBRARY/atmega32_registers.h"

#include "../../LIBRARY/primitive_data_types.h"
#include "../../LIBRARY/BIT_MATH.h"
#include "../../MCAL/DIO/dio_interface.h"
#include "../../MCAL/TIMERS/timers_interface.h"

#include "keypad_private.h"
#include "keypad_interface.h"


typedef enum 
{
	stableState,
	BouncningFromPressedState,
	BouncningFromNotPressedState
}CHANGE_STATE_t;

///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
typedef enum 
{
	keyPressed,
	keyNotPressed,
	keyBouncing
	
}KEY_STATE_t;

///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
typedef struct KEYPAD_STATE_t
{
	KEY_STATE_t keyState ; 
	CHANGE_STATE_t keyLastStableState ; 
	uint8_t u8_KeyRow ; 
	uint8_t u8_KeyCol ; 
}KEYPAD_STATE_t;

KEYPAD_STATE_t StateOfKeyPad ;

///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
void KEYPAD_voidInit(void) 
{
	TIMER2_voidInit() ;
	//SETTING ROWS AS OUTPUT PINS
	DIO_u8SetPinDir(u8_KEYPAD_PORT,u8_KEYPAD_ROW1,u8_DIO_OUTPUT_PIN) ; 
	DIO_u8SetPinDir(u8_KEYPAD_PORT,u8_KEYPAD_ROW2,u8_DIO_OUTPUT_PIN) ; 
	DIO_u8SetPinDir(u8_KEYPAD_PORT,u8_KEYPAD_ROW3,u8_DIO_OUTPUT_PIN) ; 
	//SETTING COL PINS AS INPUT PINS
	DIO_u8SetPinDir(u8_KEYPAD_PORT,u8_KEYPAD_COL1,u8_DIO_INPUT_PIN) ; 
	DIO_u8SetPinDir(u8_KEYPAD_PORT,u8_KEYPAD_COL2,u8_DIO_INPUT_PIN) ; 
	DIO_u8SetPinDir(u8_KEYPAD_PORT,u8_KEYPAD_COL3,u8_DIO_INPUT_PIN) ;
	//ENABLE ALL PULL-UP PINS
	DIO_voidEnablePullUps() ;      
	//SETTING INTIAL HIGH VALUE FOR OUTPUT ROW PINS		
	DIO_u8SetPinVal(u8_KEYPAD_PORT,u8_KEYPAD_ROW1,u8_DIO_PIN_HIGH) ; 
	DIO_u8SetPinVal(u8_KEYPAD_PORT,u8_KEYPAD_ROW2,u8_DIO_PIN_HIGH) ; 
	DIO_u8SetPinVal(u8_KEYPAD_PORT,u8_KEYPAD_ROW3,u8_DIO_PIN_HIGH) ;
	//SETTING PULL-UP FOR INPUT PINS
	DIO_u8SetPinVal(u8_KEYPAD_PORT,u8_KEYPAD_COL1,u8_DIO_PIN_HIGH) ; 
	DIO_u8SetPinVal(u8_KEYPAD_PORT,u8_KEYPAD_COL2,u8_DIO_PIN_HIGH) ; 
	DIO_u8SetPinVal(u8_KEYPAD_PORT,u8_KEYPAD_COL3,u8_DIO_PIN_HIGH) ;
	
	StateOfKeyPad.keyState = keyNotPressed ;
	StateOfKeyPad.u8_KeyRow = u8_KEYPAD_ROW_NOT_PRESSED ;
	StateOfKeyPad.u8_KeyCol = u8_KEYPAD_COL_NOT_PRESSED ;
	StateOfKeyPad.keyLastStableState = stableState ; 
}




/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////

//FUNCTION KEYPAD_u8GetKeyNum RETURN ERROR STATE AND TAKE POINTER TO RETURN PRESSED KEY NUM IN ASCII OR ASCII OF ZERO IF NO KEY PRESSED 
uint8_t KEYPAD_u8GetKeyNum(uint8_t* pu8_ReturnKeyNum)
{
	uint8_t u8_ReturnState = u8_KEYPAD_NOK ;
	uint8_t u8_timerState ; 
	uint8_t	u8_ButtonState = u8_KEYPAD_NOT_PRESSED; 

	if(pu8_ReturnKeyNum!=NULL_POINTER)
	{
		
		switch(StateOfKeyPad.keyState)
		{
			case keyPressed :
					DIO_u8SetPinVal(u8_KEYPAD_PORT,StateOfKeyPad.u8_KeyRow,u8_DIO_PIN_LOW) ; 
					DIO_u8GetPinVal(u8_KEYPAD_PORT,StateOfKeyPad.u8_KeyCol,&u8_ButtonState) ;
					DIO_u8SetPinVal(u8_KEYPAD_PORT,StateOfKeyPad.u8_KeyRow,u8_DIO_PIN_HIGH) ;
					if(u8_ButtonState!=u8_KEYPAD_PRESSED)
					{
						StateOfKeyPad.keyState =  keyBouncing ; 
						StateOfKeyPad.keyLastStableState  = BouncningFromPressedState ; 
						TIMER2_u8InterruptWait(u8_KEYPAD_DEBOUNCING_TIME) ;

					}

					break ; 
			case keyNotPressed :
					KEYPAD_voidcheckedIfNotPressed(pu8_ReturnKeyNum) ;
					u8_ReturnState = u8_KEYPAD_OK ; 
					break ; 
			case keyBouncing :

					u8_timerState = TIMER2_u8GetIntWaitStatus();
					if(u8_timerState == u8_FINISH_INTERRUPT_WAITING)
					{
						if(StateOfKeyPad.keyLastStableState == BouncningFromNotPressedState)
						{
							StateOfKeyPad.keyState =  keyPressed ; 
							StateOfKeyPad.keyLastStableState  = stableState ; 

						}
						else if(StateOfKeyPad.keyLastStableState == BouncningFromPressedState)
						{
							StateOfKeyPad.keyState =  keyNotPressed ; 
							StateOfKeyPad.keyLastStableState  = stableState ; 
						}
						TIMERS_u8IntModesDis(u8_TIMER2_COMPARE_ON_MATCH) ;
					}

					break ; 
		}
	}
	else 
	{
		//IF THE POINTER IS SEND AS NULL_POINTER, RETURN u8_KEYPAD_NOK
		 u8_ReturnState = u8_KEYPAD_NOK ;
	}
	return u8_ReturnState ; 
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////

static void KEYPAD_voidcheckedIfNotPressed(uint8_t* pu8_PressedNum)
{
	uint8_t u8_ColCounter = u8_KEYPAD_COL1,u8_RowCounter = u8_KEYPAD_ROW1,u8_TotalCount = u8_KEYPAD_INTIALIZING_VAR ;
	uint8_t u8_ButtonState = u8_KEYPAD_NOT_PRESSED ;
	//LOOP TO PASS ON ALL COLUMNS 
	*pu8_PressedNum = u8_KEYPAD_ALL_KEYS_NOT_PRESSED ; 
	StateOfKeyPad.u8_KeyRow = u8_KEYPAD_ROW_NOT_PRESSED ;
	StateOfKeyPad.u8_KeyCol = u8_KEYPAD_COL_NOT_PRESSED ;
	for(u8_RowCounter = u8_KEYPAD_ROW1; u8_RowCounter<=u8_KEYPAD_ROW3;u8_RowCounter++)   
	{
		//SETTING PIN OF ONE COL. TO LOW SO THAT WE CAN CHECK IF ANY KEY PRESSED 
		DIO_u8SetPinVal(u8_KEYPAD_PORT,u8_RowCounter,u8_DIO_PIN_LOW) ; 
		//LOOP TO PASS ON ALL ROWS 
		for (u8_ColCounter = u8_KEYPAD_COL1; u8_ColCounter<=u8_KEYPAD_COL3;u8_ColCounter++)
		{	
			// CHECK IF THE KEY PRESSED WITHOUT THE BOUNCING EFFECT 
			//TOTAL NUMBER OF BUTTONS WE CHECK SO THAT WHEN THEY ARE ADDED TO INTIAL '0' VALUE, WE CAN RETURN THE BUTTON NUM PRESSED
			u8_TotalCount++ ;
			DIO_u8GetPinVal(u8_KEYPAD_PORT,u8_ColCounter,&u8_ButtonState) ;
			if(u8_ButtonState==u8_KEYPAD_PRESSED)
			{
				DIO_u8SetPinVal(u8_KEYPAD_PORT,u8_RowCounter,u8_DIO_PIN_HIGH) ;
				*pu8_PressedNum = u8_TotalCount ;
				StateOfKeyPad.keyLastStableState = BouncningFromNotPressedState ; 
				StateOfKeyPad.keyState =  keyBouncing ; 
				StateOfKeyPad.u8_KeyRow = u8_RowCounter ; 
				StateOfKeyPad.u8_KeyCol = u8_ColCounter ; 
				TIMER2_u8InterruptWait(u8_KEYPAD_DEBOUNCING_TIME) ;
				break ;
			}
		}
		if(StateOfKeyPad.keyState == keyBouncing )
		{
			break ; 
		}
		// MAKE THE COL HIGH AGAIN SO THAT WE CAN CHECK SAME ROWS WITH DIFFERENT COLs. 
		DIO_u8SetPinVal(u8_KEYPAD_PORT,u8_RowCounter,u8_DIO_PIN_HIGH) ; 
	}

}

