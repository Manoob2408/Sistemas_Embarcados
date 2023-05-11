#include "MKL25Z4.h"
#include "Serial.h"
#include "IO.h"
#include "string.h"
#include "Time.h"
#include "ADC.h"

int main(void) {
	
  ENABLE_PORTS(PORT_A);
  ENABLE_PORTS(PORT_B);
	ENABLE_PORTS(PORT_D);

	SetPinMode(PORT_B, 18);
	SetPinMode(PORT_B, 19);
	SetPinMode(PORT_D, 1);
	
	Pin_OutputMode(PORT_B,18);
	Pin_OutputMode(PORT_B,19);
	Pin_OutputMode(PORT_B,18);
	
	PLL_Init();
  Serial_Init();
 
	Time_Init();
	ADC_Init();
	
	uint8_t byteReceived = 0;
	uint32_t voltage;

  
	while(1){
		
		ADC_ReadChannel(13);
		voltage = ADC_GetVoltage(ADC_ReadChannel(13), 3.3);
		
		if(voltage < 1){
			Pin_Clear(PORT_D, 1);
			Pin_Set(PORT_B, 18);
			Pin_Set(PORT_B, 19);
		}
		
		else if(voltage >= 1 && voltage < 2)
		{
			Pin_Clear(PORT_B, 19);
			Pin_Set(PORT_B, 18);
			Pin_Set(PORT_D, 1);
		}
		
		else{
			Pin_Clear(PORT_B, 18);
			Pin_Set(PORT_B, 19);
			Pin_Set(PORT_D, 1);
		}
	}
	
 
}

void LPTMR0_IRQHandler()
{
	/*Verifica se a flag de interrupção está ativada*/
		if(LPTMR0_BASE_PTR->CSR & LPTMR_CSR_TCF_MASK)
		{
			/*zera a flag de interrupção*/
			LPTMR0_BASE_PTR->CSR = LPTMR0_BASE_PTR->CSR | LPTMR_CSR_TCF_MASK;
			/*inverte o estado do led*/
			GPIOB_BASE_PTR->PTOR = (1 << 18);
		}
}
