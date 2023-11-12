/*
0 * DIO_interface.h
 *
 *  Created on: Nov 2, 2023
 *      Author: Nada
 */

/*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< DIO_Interface.h>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
* Auther: Nada Hassan
* Layer : MCAL
* SWC : DIO/GPIO
*
*/

typedef enum {

	DIO_NOK,
	DIO_OK


} DIO_ErrorState;

#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_

#define DIO_PORT_HIGH 		0xFF
#define DIO_PORT_LOW  		0

#define DIO_PORT_OUTPUT		0xFF
#define DIO_PORT_INPUT 		0

#define DIO_PIN_OUTPUT 1
#define DIO_PIN_INPUT 0

#define DIO_PIN_HIGH 1
#define DIO_PIN_LOW 0

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7

#define PUD 2

//first we have to set the port direction and determine weather this port is high or low.

DIO_ErrorState DIO_enumSetPortDirection       (u8 Copy_u8PORT, u8 Copy_u8DIRECTION);
DIO_ErrorState DIO_enumSetPortValue           (u8 Copy_u8PORT, u8 Copy_u8VALUE);

//Second we have to set the pin direction and determine weather this pin is high or low.

DIO_ErrorState DIO_enumSetPinDirection        (u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8DIRECTION);
DIO_ErrorState DIO_enumSetPinValue            (u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8VALUE);
DIO_ErrorState DIO_enumGetPinValue            (u8 Copy_u8PORT, u8 Copy_u8PIN, u8 * Copy_u8PtrData);
DIO_ErrorState DIO_enumTogglePinValue         (u8 Copy_u8PORT, u8 Copy_u8PIN);
DIO_ErrorState DIO_enumConnectedPullUp        (u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8InternalPullUp);
DIO_ErrorState DIO_enumTogglePortValue        (u8 Copy_u8PORT);
DIO_ErrorState DIO_enumGetPortValue           (u8 Copy_u8PORT, u8* Copy_PtrData);
DIO_ErrorState DIO_voidWriteHighNibbles       (u8 Copy_u8PORT, u8 Copy_u8VALUE);
DIO_ErrorState DIO_voidWriteLowNibbles        (u8 Copy_u8PORT, u8 Copy_u8VALUE);
