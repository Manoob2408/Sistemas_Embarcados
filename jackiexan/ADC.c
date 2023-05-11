#include "MKL25Z4.h"
#include "ADC.h"

void ADC_Init()
{
	/*Habilita clock do m�dulo AD*/
	SIM_BASE_PTR->SCGC6 = SIM_SCGC6_ADC0_MASK;
	/*Configura o pino que ser� utilizado como entrada do AD*/
	SIM_BASE_PTR->SCGC5 = SIM_SCGC5_PORTB_MASK;
	PORTB_BASE_PTR->PCR[3] = PORT_PCR_MUX(0);
	/*Configura ADC no modo de 12bits com prescale de 4*/
	ADC0_BASE_PTR->CFG1 = (ADC_CFG1_MODE(1) | ADC_CFG1_ADIV(2));
}

uint32_t ADC_ReadChannel(uint8_t channel)
{
	/*Inicia a convers�o do canal 13*/
	ADC0_BASE_PTR->SC1[0] = 13;
	/*
	* Aguarda convers�o
	* A flag ADACT � 1 enquanto a convers�o est� sendo realizada
	*/
	while(ADC0_BASE_PTR->SC2 & ADC_SC2_ADACT_MASK);
	/*L� o resultado da convers�o*/
	return ADC0_BASE_PTR->R[0];
}

float ADC_GetVoltage(uint32_t rawData, float vref)
{
	return rawData*(vref/4095);
}