/*
 * SW_Program.c

 *
 *  Created on: Nov 12, 2023
 *      Author: Nada
 */



#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "SW_Interface.h"
#include <util\delay.h>




void SW_VoidInit   (SW_Adjusting SW_Signal){


	DIO_enumSetPinDirection        (SW_Signal.PORT, SW_Signal.PIN, DIO_PIN_INPUT);
	if(SW_Signal.Pull_Status == SW_INT_PULL_UP){

		DIO_enumConnectedPullUp (SW_Signal.PORT, SW_Signal.PIN, DIO_PIN_HIGH);

	//DIO_enumSetPinValue (SW_Signal.PORT, SW_Signal.PIN, DIO_PIN_HIGH);
	}

}




u8   SW_GetPressed (SW_Adjusting SW_Signal){

	u8 LOC_u8Result = SW_NotPressed ;
	u8 LOC_u8PinVal = SW_NotPressed ;

	if((SW_Signal.Pull_Status == SW_INT_PULL_UP) || (SW_Signal.Pull_Status == SW_EXT_PULL_UP)){

		DIO_enumGetPinValue  (SW_Signal.PORT, SW_Signal.PIN, &LOC_u8PinVal);

		if(LOC_u8PinVal == 0){
			LOC_u8Result = SW_Pressed;
		}
		else if (LOC_u8PinVal == 1){
			LOC_u8Result = SW_NotPressed;
		}
	}

	else if (SW_Signal.Pull_Status == SW_EXT_PULL_DOWN) {

		DIO_enumGetPinValue  (SW_Signal.PORT, SW_Signal.PIN, &LOC_u8PinVal);

		if(LOC_u8PinVal == 0){
			LOC_u8Result = SW_NotPressed;
		}
		else if (LOC_u8PinVal == 1){
			LOC_u8Result = SW_Pressed;
		}

	}

	return LOC_u8Result;
}
