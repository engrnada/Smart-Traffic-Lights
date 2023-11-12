/*
 * SSD_interface.h
 *
 *  Created on: Nov 4, 2023
 *      Author: Nada
 */

#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

#define SSD_PORTA 0
#define SSD_PORTB 1
#define SSD_PORTC 2
#define SSD_PORTD 3


#define SSD_PIN0 0
#define SSD_PIN1 1
#define SSD_PIN2 2
#define SSD_PIN3 3
#define SSD_PIN4 4
#define SSD_PIN5 5
#define SSD_PIN6 6
#define SSD_PIN7 7

#define Common_Anode 1
#define Common_cathode 0

typedef struct {

	u8 Common;
	u8 DataPort;
	u8 EnablePort;
	u8 EnablePin;

}SSD_Adjusting;


void SSD_VoidInitPort(SSD_Adjusting SSD_Signal);

void SSD_VoidEnable(SSD_Adjusting SSD_Signal);

void SSD_VoidDisable(SSD_Adjusting SSD_Signal);

void SSD_VoidSendNumber(SSD_Adjusting SSD_Signal, u8 CopyNumber);


void Delay_time(int a);

#endif /* SSD_INTERFACE_H_ */
