/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    ADC_register.h / ADC_private.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

 *
 *  Author : Nada Hassan
 *  Layer  : MCAL
 *  SWC    : ADC
 *
 */ 
 

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define ADC_PRE_MASK            0b11111000
#define ADC_CH_MASK             0b11100000


#define ADMUX                  *((volatile u8*)0x27)
#define ADMUX_REFS1             7
#define ADMUX_REFS0             6
#define ADMUX_ADLAR             5


#define ADSAR                   *((volatile u8*)0x26)

#define ADSAR_ADEN              7
#define ADSAR_ADSC              6
#define ADSAR_ADTE              5
#define ADSAR_ADIF              4
#define ADSAR_ADIE              3
#define ADSAR_ADPS2             2
#define ADSAR_ADPS1             1
#define ADSAR_ADPS0             0


#define ADCH                    *((volatile u8*)0x25)
#define ADCL                    *((volatile u8*)0x24)
#define ADC_DATA_RE             *((volatile u16*)0x24)
#define SFIOR                   *((volatile u8 *)0x50)

#define SFIOR_ADTS2             7
#define SFIOR_ADTS1             6
#define SFIOR_ADTS0             5

#define Single_Channel_Asynch   0
#define Chain_Channel_Asynch    1



#endif /* ADC_PRIVATE_H_ */
