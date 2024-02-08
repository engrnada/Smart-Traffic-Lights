/*
 * CLCD_interface.h
 *
 *  Created on: Nov 23, 2023
 *      Author: Nada
 */

#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_

#include "CLCD_Config.h"
#include "../../LIB/STD_TYPES.h"


#if CLCD_Mode == 4
#define FOUR_BITS        0x28
#elif CLCD_Mode == 8
#define EIGHT_BITS       0x38
#endif


#define CLCD_CLR_Display                 0x01
#define CLCD_Return_Home                 0x02
#define CLCD_Decrement_Cursor            0x04
#define CLCD_Increment_Cursor            0x06
#define CLCD_Shift_Display_Right         0x05
#define CLCD_Shift_Display_Left          0x07
#define CLCD_DisplayOff_Cursoroff        0x08
#define CLCD_DisplayOff_Cursoron         0x0A
#define CLCD_DisplayOn_Cursoroff         0x0C
#define CLCD_DisplayOn_CursorBlink       0x0E
#define CLCD_Shift_Cursor_left           0x10
#define CLCD_Shift_Cursor_right          0x14
#define CLCD_Shift_Display_right         0x1C
#define CLCD_Shift_Display_left          0x18
#define CLCD_Rtrn_CursorToBegining1st    0x80
#define CLCD_Rtrn_CursorToBegining2nd    0xC0
#define CLCD_CGRAM                       0x40
#define CLCD_FunctionReset               0x30



#define CLCD_Row1               0
#define CLCD_Row2               1


#define CLCD_COL1               1
#define CLCD_COL2               2
#define CLCD_COL3               3
#define CLCD_COL4               4
#define CLCD_COL5               5
#define CLCD_COL6               6
#define CLCD_COL7               7
#define CLCD_COL8               8
#define CLCD_COL9               9
#define CLCD_COL10              10
#define CLCD_COL11              11
#define CLCD_COL12              12
#define CLCD_COL13              13
#define CLCD_COL14              14
#define CLCD_COL15              15
#define CLCD_COL16              16


void CLCD_Init                  (void);
void CLCD_SendData              (u8 Copy_u8Data);
void CLCD_SendComand            (u8 Copy_u8Comand);
void CLCD_SendFallingEdge       (void);
void CLCD_SendString            (const u8 * Copy_u8PTRString);
void CLCD_SendNumber            (u64 Copy_u64Number);
void CLCD_SetPosition           (u8 Copy_u8Row, u8 Copy_u8Column);
void CLCD_ClearScreen           (void);
void CLCD_SendExtraChar         (u8 Copy_u8Row, u8 Copy_u8Column);






#endif /* CLCD_INTERFACE_H_ */
