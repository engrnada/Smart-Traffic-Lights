* main.c
 *
 *  Created on: Nov 2, 2023
 *      Author: Nada
 */
/*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< DIO_Program.c>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
* Auther: Nada Hassan
* Layer : MCAL
* SWC : DIO/GPIO
*
*/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

DIO_ErrorState DIO_enumSetPortDirection    (u8 Copy_u8PORT, u8 Copy_u8DIRECTION){
    DIO_ErrorState LOC_enumState = DIO_OK;
 if((Copy_u8PORT <= DIO_PORTD)){
      switch (Copy_u8PORT){
       case DIO_PORTA : DDRA = Copy_u8DIRECTION ; break;
       case DIO_PORTB : DDRB = Copy_u8DIRECTION; break;
       case DIO_PORTC : DDRC = Copy_u8DIRECTION; break;
       case DIO_PORTD : DDRD = Copy_u8DIRECTION; break;

}

}
   else {LOC_enumState = DIO_NOK;

   }

 return LOC_enumState;

}


DIO_ErrorState DIO_enumSetPortValue (u8 Copy_u8PORT, u8 Copy_u8VALUE){
	 DIO_ErrorState LOC_enumState = DIO_OK;
	 if((Copy_u8PORT <= DIO_PORTD) && ( (Copy_u8VALUE<=255) || (Copy_u8VALUE==DIO_PORT_LOW) || (Copy_u8VALUE==DIO_PORT_HIGH) )){
      switch (Copy_u8PORT){
            case DIO_PORTA : PORTA = Copy_u8VALUE ; break;
            case DIO_PORTB : PORTB = Copy_u8VALUE; break;
            case DIO_PORTC : PORTC = Copy_u8VALUE; break;
            case DIO_PORTD : PORTD = Copy_u8VALUE; break;

 }

}
else {LOC_enumState = DIO_NOK;}

	 return LOC_enumState;

}


DIO_ErrorState DIO_enumSetPinDirection    (u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8DIRECTION){
    DIO_ErrorState LOC_enumState = DIO_OK;
 if((Copy_u8PORT <= DIO_PORTD) && (Copy_u8PIN <= DIO_PIN7)){
   if( Copy_u8DIRECTION == DIO_PIN_OUTPUT){
      switch (Copy_u8PORT){
       case DIO_PORTA : SET_BIT(DDRA, Copy_u8PIN); break;
       case DIO_PORTB : SET_BIT(DDRB, Copy_u8PIN); break;
       case DIO_PORTC : SET_BIT(DDRC,  Copy_u8PIN); break;
       case DIO_PORTD : SET_BIT(DDRD,  Copy_u8PIN); break;

 }

}
   else if( Copy_u8DIRECTION == DIO_PIN_INPUT){
      switch (Copy_u8PORT){
       case DIO_PORTA : CLR_BIT(DDRA, Copy_u8PIN); break;
       case DIO_PORTB : CLR_BIT(DDRB, Copy_u8PIN); break;
       case DIO_PORTC : CLR_BIT(DDRC, Copy_u8PIN); break;
       case DIO_PORTD : CLR_BIT(DDRD,Copy_u8PIN); break;

 }

}
   else {LOC_enumState = DIO_NOK;}
}
 return LOC_enumState;
}
DIO_ErrorState DIO_enumSetPinValue (u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8VALUE){
	 DIO_ErrorState LOC_enumState = DIO_OK;
	 if((Copy_u8PORT <= DIO_PORTD) && (Copy_u8PIN <= DIO_PIN7)){
if( Copy_u8VALUE == DIO_PIN_HIGH){
      switch (Copy_u8PORT){
       case DIO_PORTA : SET_BIT(PORTA, Copy_u8PIN); break;
       case DIO_PORTB : SET_BIT(PORTB,  Copy_u8PIN); break;
       case DIO_PORTC : SET_BIT(PORTC,  Copy_u8PIN); break;
       case DIO_PORTD : SET_BIT(PORTD, Copy_u8PIN); break;

 }

}
else if(Copy_u8VALUE == DIO_PIN_LOW){
      switch (Copy_u8PORT){
       case DIO_PORTA : CLR_BIT(PORTA,Copy_u8PIN); break;
       case DIO_PORTB : CLR_BIT(PORTB, Copy_u8PIN); break;
       case DIO_PORTC : CLR_BIT(PORTC, Copy_u8PIN); break;
       case DIO_PORTD : CLR_BIT(PORTD, Copy_u8PIN); break;

 }

}
else {LOC_enumState = DIO_NOK;}
}
	 return LOC_enumState;
}

DIO_ErrorState DIO_enumGetPinValue (u8 Copy_u8PORT, u8 Copy_u8PIN, u8* Copy_PtrData){
	 DIO_ErrorState LOC_enumState = DIO_OK;
 if((Copy_u8PORT <= DIO_PORTD) && (Copy_u8PIN <= DIO_PIN7)){
       switch (Copy_u8PORT){
       case DIO_PORTA : * Copy_PtrData = GET_BIT(PINA, Copy_u8PIN); break;
       case DIO_PORTB : * Copy_PtrData = GET_BIT(PINB,Copy_u8PIN); break;
       case DIO_PORTC : * Copy_PtrData = GET_BIT(PINC, Copy_u8PIN); break;
       case DIO_PORTD : * Copy_PtrData = GET_BIT(PIND, Copy_u8PIN); break;

 }
 }
else {
	LOC_enumState = DIO_NOK;
}
 return LOC_enumState;

}
DIO_ErrorState DIO_enumTogglePinValue (u8 Copy_u8PORT, u8 Copy_u8PIN){
	 DIO_ErrorState LOC_enumState = DIO_OK;
if( Copy_u8PIN <= DIO_PIN7){
      switch (Copy_u8PORT){
       case DIO_PORTA : TOG_BIT(PORTA, Copy_u8PIN);
       break;
       case DIO_PORTB : TOG_BIT(PORTB,  Copy_u8PIN);
       break;
       case DIO_PORTC : TOG_BIT(PORTC,  Copy_u8PIN);
       break;
       case DIO_PORTD : TOG_BIT(PORTD, Copy_u8PIN);
       break;

 }

}

else {LOC_enumState = DIO_NOK;}
return LOC_enumState;
}


DIO_ErrorState DIO_enumConnectedPullUp        (u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8InternalPullUp){

	DIO_ErrorState LOC_enumState = DIO_OK;
	if((Copy_u8PORT <= DIO_PORTD) && (Copy_u8PIN <= DIO_PIN7)){
		switch (Copy_u8PORT){
		case DIO_PORTA :
			if(Copy_u8InternalPullUp==DIO_PIN_HIGH){

				CLR_BIT(SFIOR,PUD);
				CLR_BIT(DDRA,Copy_u8PIN);
				SET_BIT(PORTA,Copy_u8PIN);

			}
			else {
				CLR_BIT(PORTA,Copy_u8PIN);
			}
			break;
		case DIO_PORTB :
				if(Copy_u8InternalPullUp==DIO_PIN_HIGH){

					CLR_BIT(SFIOR,PUD);
					CLR_BIT(DDRB,Copy_u8PIN);
					SET_BIT(PORTB,Copy_u8PIN);

				}
				else {
					CLR_BIT(PORTB,Copy_u8PIN);
				}
				break;
		case DIO_PORTC :
				if(Copy_u8InternalPullUp==DIO_PIN_HIGH){

					CLR_BIT(SFIOR,PUD);
					CLR_BIT(DDRC,Copy_u8PIN);
					SET_BIT(PORTC,Copy_u8PIN);

				}
				else {
					CLR_BIT(PORTC,Copy_u8PIN);
				}
				break;
		case DIO_PORTD :
					if(Copy_u8InternalPullUp==DIO_PIN_HIGH){

						CLR_BIT(SFIOR,PUD);
						CLR_BIT(DDRD,Copy_u8PIN);
						SET_BIT(PORTD,Copy_u8PIN);

					}
					else {
						CLR_BIT(PORTD,Copy_u8PIN);
					}
					break;

		}

	}

	else
	{
		LOC_enumState = DIO_NOK ;
	}

	return LOC_enumState;

}


DIO_ErrorState DIO_enumTogglePortValue (u8 Copy_u8PORT){
	 DIO_ErrorState LOC_enumState = DIO_OK;
if( Copy_u8PORT <= DIO_PORTD){
      switch (Copy_u8PORT){
       case DIO_PORTA : PORTA = ~PORTA;
       break;
       case DIO_PORTB : PORTB = ~PORTB;
       break;
       case DIO_PORTC : PORTC = ~PORTC;
       break;
       case DIO_PORTD : PORTD = ~PORTD;
       break;

 }

}

else {LOC_enumState = DIO_NOK;}
return LOC_enumState;
}


DIO_ErrorState DIO_enumGetPortValue (u8 Copy_u8PORT, u8* Copy_PtrData){
	 DIO_ErrorState LOC_enumState = DIO_OK;
 if((Copy_u8PORT <= DIO_PORTD)){
       switch (Copy_u8PORT){
       case DIO_PORTA : * Copy_PtrData = PINA; break;
       case DIO_PORTB : * Copy_PtrData = PINB; break;
       case DIO_PORTC : * Copy_PtrData = PINC; break;
       case DIO_PORTD : * Copy_PtrData = PIND; break;

 }
 }
else {
	LOC_enumState = DIO_NOK;
}
 return LOC_enumState;

}


DIO_ErrorState DIO_voidWriteHighNibbles (u8 Copy_u8PORT, u8 Copy_u8VALUE){
	 DIO_ErrorState LOC_enumState = DIO_OK;
if( Copy_u8PORT <= DIO_PORTD){
	Copy_u8VALUE = (Copy_u8VALUE<<4);
      switch (Copy_u8PORT){
       case DIO_PORTA : PORTA &= 0x0f;
       PORTA |= Copy_u8VALUE;
       break;
       case DIO_PORTB : PORTB &= 0x0f;
       PORTB |= Copy_u8VALUE;
       break;
       case DIO_PORTC : PORTC &= 0x0f;
       PORTC |= Copy_u8VALUE;
       break;
       case DIO_PORTD : PORTC &= 0x0f;
       PORTC |= Copy_u8VALUE;
       break;

 }

}

else {LOC_enumState = DIO_NOK;}
return LOC_enumState;
}


DIO_ErrorState DIO_voidWriteLowNibbles (u8 Copy_u8PORT, u8 Copy_u8VALUE){
	 DIO_ErrorState LOC_enumState = DIO_OK;
if( Copy_u8PORT <= DIO_PORTD){
	Copy_u8VALUE &= 0x0f ;
      switch (Copy_u8PORT){
       case DIO_PORTA : PORTA &= 0xf0;
                        PORTA |= Copy_u8VALUE;
       break;
       case DIO_PORTB : PORTB &= 0xf0;
                        PORTB |= Copy_u8VALUE;
       break;
       case DIO_PORTC : PORTC &= 0xf0;
                        PORTC |= Copy_u8VALUE;
       break;
       case DIO_PORTD : PORTC &= 0xf0;
                        PORTC |= Copy_u8VALUE;
       break;

 }

}

else {LOC_enumState = DIO_NOK;}
return LOC_enumState;
}





