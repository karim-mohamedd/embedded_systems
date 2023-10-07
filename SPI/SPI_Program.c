

#include<avr/io.h>
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include"SPI_Interface.h"






void MSPI_voidMasterInit(){

	/*Master Init*/
	SET_BIT(SPCR, 4);

	/*Clock Select Prescaller 16*/
	SET_BIT(SPCR, 0);
	CLR_BIT(SPCR, 1);
	CLR_BIT(SPSR, 0);


	/*SPi Enable*/
	SET_BIT(SPCR,6);
}

void MSPI_voidSlaveInit(){

	/*Slave Init*/
	CLR_BIT(SPCR, 4);

	/*SPi Enable*/
	SET_BIT(SPCR,6);
}


u8 MSPI_u8Transcieve(u8 A_u8Data){

	/*Send Data*/
	SPDR = A_u8Data;
	/*Wait Till Transfer Finished*/
	while(GET_BIT(SPSR, 7) == 0);

	return SPDR;

}




