/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    ADC_interface.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

 *
 *  Author : Nada Hassan
 *  Layer  : MCAL
 *  SWC    : ADC
 *
 */ 
 

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#define ADC_Disable              0
#define ADC_Enable               1


#define INT_Disable              0
#define INT_Enable               1

#define AREF                     0
#define AVCC                     1
#define Internal_2_56            3

#define Right_Adjustment         0
#define Left_Adjustment          1


#define ADC_Channel0             0
#define ADC_Channel1             1
#define ADC_Channel2             2
#define ADC_Channel3             3
#define ADC_Channel4             4
#define ADC_Channel5             5
#define ADC_Channel6             6
#define ADC_Channel7             7



#define ADC_Single_Conversion    0
#define ADC_Free_Running         1
#define ADC_Analog_Comparator    2
#define ADC_EXTI0                3
#define ADC_TIM0_CTC             4
#define ADC_TIM0_OVF             5
#define ADC_TIM1_CTC_Channel8    6
#define ADC_TIM1_OVF             7
#define ADC_TIM1_ICU             8



#define ADC_Pre_2               0
#define ADC_Pre_4               2
#define ADC_Pre_8               3
#define ADC_Pre_16              4
#define ADC_Pre_32              5
#define ADC_Pre_64              6
#define ADC_Pre_128             7


typedef struct
{
	u8*  Channel;
	u16* Result;
	u8   Size;
	void (*NotificationFunc)(void);
}Chain_t;


void ADC_VoidInit(void);
u8   ADC_u8GetResultSync(u8 Copy_u8Channel, u16* Copy_pu16Result);
u8   ADC_u8StartConversionAsynch(u8 Copy_u8Channel, u16* Copy_pu16Result, void(*Copy_pvNotificationFunc)(void));
u8   AdC_u8StartChainAsynch(Chain_t * Copy_Chain);

void ADC_VoidEnable(void);
void ADC_VoidDisable(void);
void ADC_VoidInterruptEnable(void);
void ADC_VoidInterruptDisable(void);

u8 ADC_VoidInterruptPrescaler(u8 Copy_u8Prescaler);


#endif /* ADC_INTERFACE_H_ */
