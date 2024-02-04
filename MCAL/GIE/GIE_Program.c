/*

 * GIE_Program.c
 *
 *  Created on: Dec 15, 2023
 *      Author: Nada
 */
// including Libraries
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

// including the GIE libraries
#include "GIE_interface.h"
#include "GIE_Private.h"


void GIE_VoidEnable (void)
{
	SET_BIT (SREG , SREG_I) ;
}

void GIE_VoidDisable (void)
{
	CLR_BIT (SREG , SREG_I) ;
}
