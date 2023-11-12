/*
 * SW_Interface.h
 *
 *  Created on: Nov 12, 2023
 *      Author: Nada
 */

#ifndef SW_INTERFACE_H_
#define SW_INTERFACE_H_


#define SW_Pressed     1
#define SW_NotPressed  0



#define SW_INT_PULL_UP   0
#define SW_EXT_PULL_UP   1
#define SW_EXT_PULL_DOWN 2
#define SW_FLOATING      3


typedef struct {
	
	u8 PORT;
	u8 PIN;
	u8 Pull_Status;
	
	
}SW_Adjusting;


void SW_VoidInit   (SW_Adjusting SW_Signal);
u8   SW_GetPressed (SW_Adjusting SW_Signal);




#endif /* SW_INTERFACE_H_ */
