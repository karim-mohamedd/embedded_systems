
#include<avr/io.h>

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include"ADC_Interface.h"

/*
 *
 * ARFE     0
 * AVCC     1
 * Internal 2
 *
 * */

void MADC_voidInit(u8 A_u8Vref){

	/*Select Ref Voltage*/
	switch(A_u8Vref){
		//ARFE     0
		case 0:
			CLR_BIT(ADMUX, 6);
			CLR_BIT(ADMUX, 7);
		break;
		//AVCC     1
		case 1:
			SET_BIT(ADMUX, 6);
			CLR_BIT(ADMUX, 7);
		break;
		//Internal 2
		case 2:
			SET_BIT(ADMUX, 6);
			SET_BIT(ADMUX, 7);
		break;
	}

	/*ADC Left Adjust*/
	//SET_BIT(ADMUX, 5);

	/*Select Ps 128 ps*/
	SET_BIT(ADCSRA, 0);
	SET_BIT(ADCSRA, 1);
	SET_BIT(ADCSRA, 2);

	/*Enable ADC*/
	SET_BIT(ADCSRA, 7);

}


u8 MADC_u8GetChannelReading(u8 A_u8Channel){

	/*1- Select ADC Channel*/
	ADMUX = ADMUX&0b11100000;

	ADMUX = ADMUX|A_u8Channel;

	/*2- Start Conversion */
	SET_BIT(ADCSRA, 6);

	/*Wait Till ADIF Is Fired */
	while(GET_BIT(ADCSRA, 4) == 0);

	/*Clear ADC Flag*/
	SET_BIT(ADCSRA,4);

	return ADCH;
}

u16 MADC_u16GetChannelReading(u8 A_u8ChannelNumber){

	/*Clear Channel Bits*/
	ADMUX &= 0b11100000;
	/*Put Channel Number On ADmux*/
	ADMUX |= A_u8ChannelNumber;

	/*Start Conversion */
	SET_BIT(ADCSRA, 6);

	/*Wait For ADC Flag*/
	while(GET_BIT(ADCSRA, 4) == 0);

	/*Clear The ADC Flag By Writing 1 to it*/
	SET_BIT(ADCSRA,4);

	/*Rertun ADC Reading */
	u16 ADC_u16Reading = (ADCL)|(ADCH>>8);

	return ADC_u16Reading;


}



