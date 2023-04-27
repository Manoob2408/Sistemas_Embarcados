#include "MKL25Z4.h"
#include "Serial.h"
#include "IO.h"
#include "string.h"
#include "Time.h"

int main(void) {
	
  ENABLE_PORTS(PORT_A);
  ENABLE_PORTS(PORT_B);
	ENABLE_PORTS(LPTMR);

  //SetPinMode(PORT_C, 13);
	SetPinMode(PORT_B, 18);
	
	Pin_OutputMode(PORT_B,18);
	
	PLL_Init();
  Serial_Init();
  uint8_t byteReceived = 0;
	Time_Init();

  
	while(1){
		if (READ_BIT(UART0->S1, UART0_S1_RDRF_MASK) != 0)
		{
			byteReceived = UART0->D;
		}
		if(byteReceived != 0)
		{
			if (READ_BIT(UART0->S1, UART0_S1_TDRE_MASK) != 0)
			{
			UART0->D = byteReceived + 1;
			byteReceived = 0;
			}
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
