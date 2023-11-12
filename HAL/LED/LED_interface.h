/*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< DIO_Program.c>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
* Auther: Nada Hassan
* Layer : HAL
* SWC : LED Driver
*
*/

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

#define LED_PORTA 0
#define LED_PORTB 1
#define LED_PORTC 2
#define LED_PORTD 3


#define LED_PIN0 0
#define LED_PIN1 1
#define LED_PIN2 2
#define LED_PIN3 3
#define LED_PIN4 4
#define LED_PIN5 5
#define LED_PIN6 6
#define LED_PIN7 7

#define Active_High 1
#define Active_Low 0

typedef struct {

	u8 Port;
	u8 Pin;
	u8 Status;

}LED_Adjusting;

void LED_VoidInit(LED_Adjusting LED_Signal);

void LED_VoidOn(LED_Adjusting LED_Signal);

void LED_VoidOf(LED_Adjusting LED_Signal);

void LED_VoidToggle(LED_Adjusting LED_Signal);


void Delay_time(int a);

#endif /* LED_INTERFACE_H_ */
