
/*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< DIO_Program.c>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
* Auther: Nada Hassan
* Layer : HAL
* SWC : LED Driver
*
*/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "LED_interface.h"


void LED_VoidInit(LED_Adjusting LED_Signal){

	DIO_enumSetPinDirection(LED_Signal.Port, LED_Signal.Pin, DIO_PIN_OUTPUT);


}

void LED_VoidOn(LED_Adjusting LED_Signal){


		if(LED_Signal.Status == Active_High){

			DIO_enumSetPinValue(LED_Signal.Port, LED_Signal.Pin, DIO_PIN_HIGH);

		}
		else if (LED_Signal.Status == Active_Low){
			DIO_enumSetPinValue(LED_Signal.Port, LED_Signal.Pin, DIO_PIN_LOW);

		}

}

void LED_VoidOf(LED_Adjusting LED_Signal){

	if(LED_Signal.Status == Active_High){

				DIO_enumSetPinValue(LED_Signal.Port, LED_Signal.Pin, DIO_PIN_LOW);

			}
			else if (LED_Signal.Status == Active_Low){
				DIO_enumSetPinValue(LED_Signal.Port, LED_Signal.Pin, DIO_PIN_HIGH);

			}
}

void LED_VoidToggle(LED_Adjusting LED_Signal){

	DIO_enumTogglePinValue(LED_Signal.Port, LED_Signal.Pin);



}

