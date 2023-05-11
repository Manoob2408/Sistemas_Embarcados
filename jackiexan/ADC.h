#ifndef ADC_H_
#define ADC_H_
#include "MKL25Z4.h"

void ADC_Init();
uint32_t ADC_ReadChannel(uint8_t channel);
float ADC_GetVoltage(uint32_t rawData, float vref);

#endif