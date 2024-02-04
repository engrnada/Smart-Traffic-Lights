/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    ADC_program.c   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


 *
 *  Author  : Nada Hassan
 *  Date    : 10/12/2023
 *  Version : V01
 *  Layer   : MCAL
 * 
 */ 
 
//=====================================================================================================================
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_interface.h"
#include "ADC_config.h"
#include "ADC_private.h"


static u16* ADC_PU16AsynchConversionResult = NULL;

static void(*ADC_pvNotificationFunc)(void) = NULL;

static u8 ADC_u8ISRState;

static u8* ADC_pu8ChainChannel;

static u8 ADC_u8ChainSize;

static u8 ADC_u8Index;

static u8 ADC_u8State = IDLE;

void ADC_VoidInit(void)
{
#if ADC_VREF == AREF
	CLR_BIT(ADMUX, ADMUX_REFS0);
	CLR_BIT(ADMUX, ADMUX_REFS1);

#elif ADC_VREF == AVCC
	SET_BIT(ADMUX, ADMUX_REFS0);
	CLR_BIT(ADMUX, ADMUX_REFS1);

#elif ADC_VREF == Internal_2_56
	SET_BIT(ADMUX, ADMUX_REFS0);
	SET_BIT(ADMUX, ADMUX_REFS1);

#else
#error "Wrong ADC_VREF Config"

#endif


#if ADC_Adjustment  == Right_Adjustment
	CLR_BIT(ADMUX, ADMUX_ADLAR);

#elif ADC_Adjustment  == Left_Adjustment
	SET_BIT(ADMUX, ADMUX_ADLAR);

#else
#error "Wrong ADC_Adjustment config"

#endif

	ADSAR &= ADC_PRE_MASK;
	ADSAR |= ADC_Prescaller;

#if ADC_Status == ADC_Disable
	CLR_BIT(ADSAR, ADSAR_ADEN);

#elif ADC_Status == ADC_Enable
	SET_BIT(ADSAR, ADSAR_ADEN);


#else
#error "Wrong ADC_Status Config"

#endif

#if INT_Status == INT_Disable
	CLR_BIT(ADSAR, ADSAR_ADIE);

#elif INT_Status == INT_Enable
	SET_BIT(ADSAR, ADSAR_ADIE);

#else
#error "Wrong INT_Status config"

#endif


}
u8   ADC_u8GetResultSync(u8 Copy_u8Channel, u16* Copy_pu16Result)
{
	u8 Local_u8ErrorState = OK;
	u32 Local_u32Timeoutcounter = 0;
	if (Copy_pu16Result != NULL)
	{
		if (ADC_u8State == IDLE)
		{
			ADC_u8State = BUSY;

			ADMUX &= ADC_CH_MASK;
			ADMUX |= Copy_u8Channel;

			SET_BIT(ADSAR, ADSAR_ADSC);

			while (((GET_BIT(ADSAR, ADSAR_ADIF)) == 0)&&(Local_u32Timeoutcounter< ADC_Timeout))
			{
				Local_u32Timeoutcounter++;
			}
			if (Local_u32Timeoutcounter == ADC_Timeout)
			{
				Local_u8ErrorState = TIMEOUT_STATE;
			}

			else
			{
				SET_BIT(ADSAR, ADSAR_ADIF);

#if ADC_Adjustment == Right_Adjustment

				*Copy_pu16Result = (ADCL|(ADCH << 8));

#elif ADC_Adjustment == Left_Adjustment
				*Copy_pu16Result = ADCH;
#else
#error "Wrong ADC_ADJUSTMENT Config"
#endif

			}

			ADC_u8State = IDLE;
		}

		else
		{
			Local_u8ErrorState = BUSY_STATE;
		}
	}

	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}

	return Local_u8ErrorState;
}
u8   ADC_u8StartConversionAsynch(u8 Copy_u8Channel, u16* Copy_pu16Result, void(*Copy_pvNotificationFunc)(void))
{
	u8 Local_u8ErrorState = OK;

	if ((Copy_pu16Result != NULL) && (Copy_pvNotificationFunc != NULL))
	{
		if (ADC_u8State == IDLE)
		{
			ADC_u8State = BUSY;

			ADC_u8ISRState  = Single_Channel_Asynch;

			ADC_PU16AsynchConversionResult = Copy_pu16Result;

			ADC_pvNotificationFunc = Copy_pvNotificationFunc;

			ADMUX &= ADC_CH_MASK;
			ADMUX |= Copy_u8Channel;

			SET_BIT(ADSAR, ADSAR_ADSC);

			SET_BIT(ADSAR, ADSAR_ADIE);
		}
		else
		{
			Local_u8ErrorState = BUSY_STATE;
		}
	}

	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}

	return Local_u8ErrorState;
}
u8   AdC_u8StartChainAsynch(Chain_t*Copy_Chain)
{
	u8 Local_u8ErrorState = OK ;

	if ((Copy_Chain != NULL) && (Copy_Chain ->Channel!= NULL)&& (Copy_Chain ->NotificationFunc != NULL) && (Copy_Chain ->Result))
	{
		if (ADC_u8State == IDLE)
		{
			ADC_u8State = BUSY;

			ADC_u8ISRState = Chain_Channel_Asynch;

			ADC_PU16AsynchConversionResult = Copy_Chain ->Result;
			ADC_pu8ChainChannel = Copy_Chain ->Channel;
			ADC_u8ChainSize = Copy_Chain ->Size;
			ADC_pvNotificationFunc = Copy_Chain ->NotificationFunc;

			ADC_u8Index = 0;

			ADMUX &= ADC_CH_MASK;
			ADMUX |= ADC_pu8ChainChannel[ADC_u8Index];

			SET_BIT(ADSAR, ADSAR_ADSC);

			SET_BIT(ADSAR, ADSAR_ADIE);

		}

		else
		{
			Local_u8ErrorState = BUSY_STATE;
		}
	}

	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}


	return Local_u8ErrorState;
}

void ADC_VoidEnable(void)
{
	SET_BIT(ADSAR, ADSAR_ADEN);
}

void ADC_VoidDisable(void)
{
	CLR_BIT(ADSAR, ADSAR_ADEN);
}

void ADC_VoidInterruptEnable(void)
{
	SET_BIT(ADSAR, ADSAR_ADIE);
}

void ADC_VoidInterruptDisable(void)
{
	CLR_BIT(ADSAR, ADSAR_ADIE);
}

u8 ADC_VoidInterruptPrescaler(u8 Copy_u8Prescaler)
{
	u8 Local_u8ErrorState = OK;

	if (Copy_u8Prescaler < 8)
	{
        ADSAR &= ADC_PRE_MASK;
        ADSAR |= Copy_u8Prescaler;
	}
	return Local_u8ErrorState;
}

void __vector_16 (void) __attribute__((signal));
void __vector_16 (void)
{
	if (ADC_u8ISRState == Single_Channel_Asynch)
	{
#if ADC_Adjustment == Right_Adjustment

		* ADC_PU16AsynchConversionResult = (ADCL|(ADCH << 8));

#elif ADC_Adjustment == Left_Adjustment

		* ADC_PU16AsynchConversionResult = ADCH;

#else
#error "Wrong ADC_Adjustment Config"

#endif

		ADC_u8State = IDLE;

		ADC_pvNotificationFunc();

		CLR_BIT(ADSAR, ADSAR_ADIE);

	}
	else
	{
#if ADC_Adjustment == Right_Adjustment

		*ADC_PU16AsynchConversionResult = (ADCL|(ADCH << 8))  ;

#elif ADC_Adjustment == Left_Adjustment

		*ADC_PU16AsynchConversionResult = ADCH ;

#else
#error "Wrong ADC_Adjustment Config"

#endif
		ADC_u8Index++;

		if (ADC_u8Index == ADC_u8ChainSize)
		{
			ADC_u8State = IDLE;
			ADC_pvNotificationFunc();

			CLR_BIT(ADSAR, ADSAR_ADIE);


		}

		else
		{
		ADMUX &= ADC_CH_MASK;
		ADMUX |= ADC_pu8ChainChannel[ADC_u8Index];

		SET_BIT(ADSAR, ADSAR_ADSC);
	}
  }
}

