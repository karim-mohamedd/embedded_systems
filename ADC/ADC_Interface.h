/*
 * ADC_Interface.h
 *
 *  Created on: Aug 22, 2023
 *      Author: mahmo
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_


void MADC_voidInit(u8 A_u8Vref);

u8 MADC_u8GetChannelReading(u8 A_u8Channel);
u16 MADC_u16GetChannelReading(u8 A_u8ChannelNumber);
#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
