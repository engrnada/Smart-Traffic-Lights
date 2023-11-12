/*
 * Program.c
 *
 *  Created on: Nov 4, 2023
 *      Author: Nada
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "DIO_interface.h"
#include "SSD_interface.h"
#include "SSD_Private.h"




static u8 SSDnumber [6] = SSD_Arr;


	void SSD_VoidInitPort(SSD_Adjusting SSD_Signal){

		DIO_enumSetPortDirection    (SSD_Signal.DataPort, DIO_PORT_OUTPUT);


	}



	void SSD_VoidSendNumber(SSD_Adjusting SSD_Signal, u8 CopyNumber){
		if (SSD_Signal.Common == Common_cathode){
			DIO_enumSetPortValue    (SSD_Signal.DataPort, SSDnumber[CopyNumber]);

				}
				else if (SSD_Signal.Common == Common_Anode){
					DIO_enumSetPortValue    (SSD_Signal.DataPort, ~(SSDnumber[CopyNumber]));

				}
	}


void SSD_VoidEnable(SSD_Adjusting SSD_Signal){
	if (SSD_Signal.Common == Common_cathode){
	DIO_enumSetPinDirection    (SSD_Signal.EnablePort,SSD_Signal.EnablePin, DIO_PIN_OUTPUT);
	DIO_enumSetPinValue        (SSD_Signal.EnablePort, SSD_Signal.EnablePin, DIO_PIN_LOW);
	}
	else if (SSD_Signal.Common == Common_Anode){
		DIO_enumSetPinDirection    (SSD_Signal.EnablePort,SSD_Signal.EnablePin, DIO_PIN_OUTPUT);
			DIO_enumSetPinValue        (SSD_Signal.EnablePort, SSD_Signal.EnablePin, DIO_PIN_HIGH);
	}

}

void SSD_VoidDisable(SSD_Adjusting SSD_Signal){

	if (SSD_Signal.Common == Common_cathode){
		DIO_enumSetPinDirection    (SSD_Signal.EnablePort,SSD_Signal.EnablePin, DIO_PIN_OUTPUT);
		DIO_enumSetPinValue        (SSD_Signal.EnablePort, SSD_Signal.EnablePin, DIO_PIN_HIGH);
		}
		else if (SSD_Signal.Common == Common_Anode){
			DIO_enumSetPinDirection    (SSD_Signal.EnablePort,SSD_Signal.EnablePin, DIO_PIN_OUTPUT);
				DIO_enumSetPinValue        (SSD_Signal.EnablePort, SSD_Signal.EnablePin, DIO_PIN_LOW);
		}


}


void Delay_time(int a){
	int add;
	int time;
	int i;
	time = a * 1000;
	for(i=0; i<time ; i++){
		add*=i;
		add++;
		add++;

	}

}







