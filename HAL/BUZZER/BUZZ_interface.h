/*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< DIO_Program.c>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
* Auther: Nada Hassan
* Layer : HAL
* SWC : BUZZ Driver
*
*/

#ifndef BUZZ_INTERFACE_H_
#define BUZZ_INTERFACE_H_

#define BUZZ_PORTA 0
#define BUZZ_PORTB 1
#define BUZZ_PORTC 2
#define BUZZ_PORTD 3


#define BUZZ_PIN0 0
#define BUZZ_PIN1 1
#define BUZZ_PIN2 2
#define BUZZ_PIN3 3
#define BUZZ_PIN4 4
#define BUZZ_PIN5 5
#define BUZZ_PIN6 6
#define BUZZ_PIN7 7

#define Active_High 1
#define Active_Low 0

typedef struct {

	u8 Port;
	u8 Pin;
	u8 Status;

}BUZZ_Adjusting;

void BUZZ_VoidInit(BUZZ_Adjusting BUZZ_Signal);

void BUZZ_VoidOn(BUZZ_Adjusting BUZZ_Signal);

void BUZZ_VoidOf(BUZZ_Adjusting BUZZ_Signal);

void BUZZ_VoidToggle(BUZZ_Adjusting BUZZ_Signal);


void Delay_time(int a);

#endif /* BUZZ_INTERFACE_H_ */
