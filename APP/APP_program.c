/*
 * APP_program.c

 *
 *  Created on: 12 Oct 2022
 *      Author: Mahmoud Karem
 */

/*LIB includes */
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"

/*MCAL includes */
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/EXTI/EXTI_Config.h"
#include "../MCAL/EXTI/EXTI_interface.h"
#include "../MCAL/GIE/GIE_interface.h"
#include "../MCAL/PORT/Port_Config.h"
#include "../MCAL/PORT/Port_register.h"
#include "../MCAL/PORT/Port_Interface.h"
#include "../MCAL/TIMER0/TIMER_config.h"
#include "../MCAL/TIMER0/TIMER_register.h"
#include "../MCAL/TIMER0/TIMER_interface.h"

/*HAL includes */
#include "../HAL/CLCD/CLCD_Config.h"
#include "../HAL/CLCD/CLCD_interface.h"
#include "../HAL/LED/LED_interface.h"
#include "../HAL/SSD/SSD_interface.h"
#include "../HAL/SWITCH/SW_Interface.h"

/*APP includes */
#include "APP_interface.h"


/**************************************************************************/
/********************* Proj Objects *****************/
/* Car Leds */

LED_Adjusting Car_Red =    {LED_PORTB, LED_PIN0, Active_High};
LED_Adjusting Car_Green =  {LED_PORTB, LED_PIN1, Active_High};
LED_Adjusting Car_Yellow = {LED_PORTB, LED_PIN2, Active_High};

/* Pedestrains Leds */

LED_Adjusting Ped_Red =    {LED_PORTA, LED_PIN3, Active_High};
LED_Adjusting Ped_Green =  {LED_PORTA, LED_PIN4, Active_High};
LED_Adjusting Ped_Yellow = {LED_PORTA, LED_PIN5, Active_High};


/* Control SW */
SW_Adjusting Switch1 = {DIO_PORTA, DIO_PIN2, SW_INT_PULL_UP };

/* SSD */

SSD_Adjusting SSD1 = {Common_cathode, SSD_PORTC, SSD_PORTC, SSD_PIN7};
/**************************************************************************/
/********************* Proj Enums *****************/

/*Init Car LED States*/

LED_STATE_t CarLed_Red =    LED_IDLE;
LED_STATE_t CarLed_Yellow = LED_IDLE;
LED_STATE_t CarLed_Green =  LED_IDLE;

/*Init pedestrian LED States*/

LED_STATE_t PedLed_Red =    LED_IDLE;
LED_STATE_t PedLed_Yellow = LED_IDLE;
LED_STATE_t PedLed_Green =  LED_IDLE;

/*initial mode state*/

MODE_t Mode_States = NORMAL_MODE;


/**************************************************************************/
/********************* For Timer (CTC Mode) *****************/
/* COV Value */

#define COV                 1000

/* Preload Value */

#define PreLoad_Val         125

/* Any SW Counters / Global Variables*/

u16 Timer0_Counter = 0;

u16 Modes_Counter = 0;


/**************************************************************************/

/*All application logic*/
void APP_voidPeriodicTask(void)
{
	// INC SW Counter
	// We want ---> Action Every One Sec
	// Switch on Modes and do its actions according to Flow Chart

	Timer0_Counter ++;

	if (Timer0_Counter == COV)
	{
		SSD_VoidSendNumber(SSD1, (Modes_Counter%5));

		Modes_Counter ++;

		switch (Mode_States)
		{
		case NORMAL_MODE:

			if (Modes_Counter <= 5)
			{

			CLCD_SetPosition(CLCD_Row1, CLCD_COL1);
			CLCD_SendString ((u8*) "You Can Move Now");

			LED_VoidOn (Ped_Green);
			PedLed_Green = LED_ACTIVE;
			LED_VoidOf (Ped_Red);
			PedLed_Red = LED_IDLE;
			LED_VoidOf (Ped_Yellow);
			PedLed_Yellow = LED_IDLE;



			LED_VoidOn (Car_Red);
			CarLed_Red = LED_ACTIVE;
			LED_VoidOf (Car_Green);
			CarLed_Green = LED_IDLE;
			LED_VoidOf (Car_Yellow);
			CarLed_Yellow = LED_IDLE;


			}

			else if ((Modes_Counter > 5) && (Modes_Counter <= 10) )
			{
			CLCD_SetPosition(CLCD_Row1, CLCD_COL1);
			CLCD_SendString ((u8*) "Don't Move!      ");

			LED_VoidOn (Ped_Red);
			PedLed_Red = LED_ACTIVE;
			LED_VoidOf (Ped_Green);
			PedLed_Green = LED_IDLE;
			LED_VoidOf (Ped_Yellow);
			PedLed_Yellow = LED_IDLE;



			LED_VoidOn (Car_Green);
			CarLed_Green = LED_ACTIVE;
			LED_VoidOf (Car_Red);
			CarLed_Red = LED_IDLE;
			LED_VoidOf (Car_Yellow);
			CarLed_Yellow = LED_IDLE;

			}
			else if ((Modes_Counter > 10) && (Modes_Counter <= 15) )
			{
			CLCD_SetPosition(CLCD_Row1, CLCD_COL1);
			CLCD_SendString ((u8*) "Wait......!       ");

			LED_VoidOn (Ped_Yellow);
			PedLed_Yellow = LED_ACTIVE;
			LED_VoidOf (Ped_Green);
			PedLed_Green = LED_IDLE;
			LED_VoidOf (Ped_Red);
			PedLed_Red = LED_IDLE;



			LED_VoidOn (Car_Yellow);
			CarLed_Yellow = LED_ACTIVE;
			LED_VoidOf (Car_Red);
			CarLed_Red = LED_IDLE;
			LED_VoidOf (Car_Green);
			CarLed_Green = LED_IDLE;

			if (Modes_Counter == 15)
			{
				Modes_Counter = 0;
			}

			}

			else if ((Modes_Counter > 15) && (Modes_Counter <= 20) )
			{
			CLCD_SetPosition(CLCD_Row1, CLCD_COL1);
			CLCD_SendString ((u8*) "Wait......!        ");

			LED_VoidOf (Ped_Green);
			PedLed_Green = LED_IDLE;
			LED_VoidOf (Ped_Red);
			PedLed_Red = LED_IDLE;


			LED_VoidOf (Car_Red);
			CarLed_Red = LED_IDLE;
			LED_VoidOf (Car_Green);
			CarLed_Green = LED_IDLE;

			LED_VoidToggle(Ped_Yellow);
			LED_VoidToggle(Car_Yellow);

			if (Modes_Counter == 20)
			{
				Modes_Counter = 0;
			}

			}

			break;

		case PEDESTRIAN_MODE:

			if ((CarLed_Red == LED_ACTIVE) && (CarLed_Yellow == LED_IDLE) && (CarLed_Green == LED_IDLE))
			{
				Modes_Counter = 0;
				Mode_States = NORMAL_MODE;
			}
			else if ((CarLed_Red == LED_IDLE) && ((CarLed_Yellow == LED_ACTIVE) || (CarLed_Green == LED_ACTIVE)))
			{
				Modes_Counter = 16;
				Mode_States = NORMAL_MODE;
			}

              break;
		}

		Timer0_Counter = 0;
		TIMER0_voidSetPreload (PreLoad_Val) ;
	}
		
}

/*all Initials I need */
void APP_voidInit(void)
{
	    PORT_voidInit();
	    SSD_VoidInitPort(SSD1);
	    SSD_VoidEnable(SSD1);
	    CLCD_Init();
	    EXTI_voidSetSignalLatch(EXTI_FALLING_EDGE, EXTI_LINE0);
	    EXTI_voidSetCallBack(INT0_ISR,0);
	    EXTI_voidEnableInterrupt(EXTI_LINE0);
		SW_VoidInit(Switch1);
		TIMER_u8SetCallBack(APP_voidPeriodicTask,TIMER0_CTC_VECTOR_ID);
		TIMER0_voidInit();
		GIE_VoidEnable();
}

/* EXTI CallBack Func */
void INT0_ISR(void)
{
	/* Do not edit this section (ISR have to be very small) */
	Mode_States = PEDESTRIAN_MODE;
}
