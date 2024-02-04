/*
 * Port_Program.c
 *
 *  Created on: Dec 8, 2023
 *      Author: Nada
 */


#include "../../LIB/STD_TYPES.h"

#include "Port_Config.h"
#include "Port_Interface.h"
#include "Port_Private.h"
#include "Port_register.h"


void PORT_voidInit(void)
{
	DDRA_Register=PORTA_DIR;
	DDRB_Register=PORTB_DIR;
	DDRC_Register=PORTC_DIR;
	DDRD_Register=PORTD_DIR;

	/*
		Hint : will set 1 if The pin input Pullup
	*/
	PORTA_Register=PORTA_INITIAL_VALUE;
	PORTB_Register=PORTB_INITIAL_VALUE;
	PORTC_Register=PORTC_INITIAL_VALUE;
	PORTD_Register=PORTD_INITIAL_VALUE;
}


