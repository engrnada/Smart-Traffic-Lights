/*
 * CLCD_Program.c

 *
 *  Created on: Nov 23, 2023
 *      Author: Nada
 */

#include "CLCD_Config.h"
#include "CLCD_interface.h"
#include "CLCD_Private.h"
#include "../../MCAL/DIO/DIO_interface.h"
//#include "CLCD_extrachar.h"


#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include <util/delay.h>


void CLCD_Init (void){
#if CLCD_Mode == 8
	_delay_ms(50);

	DIO_enumSetPinDirection        (CLCD_ControlPort, CLCD_RS, DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection        (CLCD_ControlPort, CLCD_Rw, DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection        (CLCD_ControlPort, CLCD_En, DIO_PIN_OUTPUT);
	DIO_enumSetPortDirection       (CLCD_DataPort, DIO_PIN_OUTPUT);

	CLCD_SendComand            (CLCD_Return_Home);
	_delay_ms(1);
	CLCD_SendComand            (EIGHT_BITS);
	_delay_ms(1);
	CLCD_SendComand            (CLCD_DisplayOn_Cursoroff);
	_delay_ms(1);
	CLCD_ClearScreen();
	CLCD_SendComand (CLCD_Increment_Cursor);
	_delay_ms(1);

#elif CLCD_Mode == 4
	_delay_ms(50);
	DIO_enumSetPinDirection        (CLCD_ControlPort, DIO_PIN4, DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection        (CLCD_ControlPort, DIO_PIN5, DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection        (CLCD_ControlPort, DIO_PIN6, DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection        (CLCD_ControlPort, DIO_PIN7, DIO_PIN_OUTPUT);

	DIO_enumSetPinDirection        (CLCD_ControlPort, CLCD_RS, DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection        (CLCD_ControlPort, CLCD_Rw, DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection        (CLCD_ControlPort, CLCD_En, DIO_PIN_OUTPUT);

	CLCD_SendComand            (CLCD_Return_Home);
	_delay_ms(30);
	CLCD_SendComand            (0x28);
	_delay_ms(1);
	CLCD_SendComand            (CLCD_DisplayOn_Cursoroff);
	_delay_ms(1);
	CLCD_ClearScreen();
	CLCD_SendComand (CLCD_Increment_Cursor);
	_delay_ms(1);


#endif


}
void CLCD_SendData              (u8 Copy_u8Data){
#if CLCD_Mode == 8
	DIO_enumSetPortValue           (CLCD_DataPort, Copy_u8Data);
	DIO_enumSetPinValue            (CLCD_ControlPort, CLCD_RS, DIO_PIN_HIGH);
	DIO_enumSetPinValue            (CLCD_ControlPort, CLCD_Rw, DIO_PIN_LOW);

	CLCD_SendFallingEdge();

#elif CLCD_Mode == 4
	DIO_enumSetPinValue            (CLCD_ControlPort, CLCD_RS, DIO_PIN_HIGH);
	DIO_enumSetPinValue            (CLCD_ControlPort, CLCD_Rw, DIO_PIN_LOW);
	DIO_voidWriteHighNibbles       (CLCD_DataPort, (Copy_u8Data>>4));
	CLCD_SendFallingEdge();
	DIO_voidWriteHighNibbles       (CLCD_DataPort, Copy_u8Data);
	CLCD_SendFallingEdge();


#endif

	_delay_ms(1);

}

void CLCD_SendComand              (u8 Copy_u8Data){
#if CLCD_Mode == 8
	DIO_enumSetPortValue           (CLCD_DataPort, Copy_u8Data);
	DIO_enumSetPinValue            (CLCD_ControlPort, CLCD_RS, DIO_PIN_LOW);
	DIO_enumSetPinValue            (CLCD_ControlPort, CLCD_Rw, DIO_PIN_LOW);

	CLCD_SendFallingEdge();

#elif CLCD_Mode == 4
	DIO_enumSetPinValue            (CLCD_ControlPort, CLCD_RS, DIO_PIN_LOW);
	DIO_enumSetPinValue            (CLCD_ControlPort, CLCD_Rw, DIO_PIN_LOW);
	DIO_voidWriteHighNibbles       (CLCD_DataPort, (Copy_u8Data>>4));
	CLCD_SendFallingEdge();
	DIO_voidWriteHighNibbles       (CLCD_DataPort, Copy_u8Data);
	CLCD_SendFallingEdge();



#endif

	_delay_ms(1);

}

void CLCD_SendFallingEdge       (void){


	DIO_enumSetPinValue            (CLCD_ControlPort, CLCD_En, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_enumSetPinValue            (CLCD_ControlPort, CLCD_En, DIO_PIN_LOW);
	_delay_ms(1);


}

void CLCD_SendString            (const u8 * Copy_u8PTRString){

	u8 counter = 0;
	while (Copy_u8PTRString[counter] != '\0'){
		CLCD_SendData  (Copy_u8PTRString[counter]);
		counter++;

	}


}

void CLCD_SendNumber            (u64 Copy_u64Number){
	u64 LOC_Reserved = 1;
	if (Copy_u64Number == 0){

		CLCD_SendData    ('0');

	}
	else {
		while (Copy_u64Number != 0){

			LOC_Reserved = (LOC_Reserved*10) + (Copy_u64Number%10);
			Copy_u64Number/=10;
		}
		while (Copy_u64Number != 1){

			CLCD_SendData   ((LOC_Reserved%10)+48);
			LOC_Reserved/=10;

		}
	}


}
void CLCD_SetPosition           (u8 Copy_u8Row, u8 Copy_u8Column){

	u8 LOC_u8data;
	if (Copy_u8Row>2||Copy_u8Row<1||Copy_u8Column>16||Copy_u8Column<1){

		LOC_u8data = CLCD_Rtrn_CursorToBegining1st;

	}
	else if (Copy_u8Row == CLCD_Row1){

		LOC_u8data = ((CLCD_Rtrn_CursorToBegining1st) + (Copy_u8Column-1));


	}
	else if (Copy_u8Row == CLCD_Row2){

		LOC_u8data = ((CLCD_Rtrn_CursorToBegining1st) + (64) + (Copy_u8Column-1));


	}
	CLCD_SendComand  (LOC_u8data);
	_delay_ms(1);

}


void CLCD_ClearScreen           (void){

	CLCD_SendComand  (CLCD_CLR_Display);


}

/*void CLCD_SendExtraChar   (u8 Copy_u8Row, u8 Copy_u8Column){
	u8 LOC_Iterator;
	CLCD_SendComand(CLCD_CGRAM);
	for (LOC_Iterator = 0; LOC_Iterator < sizeof(LCD_u8ExtraChar)/sizeof(LCD_u8ExtraChar[0]); LOC_Iterator ++){

		CLCD_SendData(LCD_u8ExtraChar[LOC_Iterator]);

	}
	CLCD_SetPosition (Copy_u8Row, Copy_u8Column);

	for (LOC_Iterator = 0; LOC_Iterator < 8; LOC_Iterator ++){

		CLCD_SendData(LOC_Iterator);

	}


}*/

















