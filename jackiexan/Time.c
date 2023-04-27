#include "MKL25Z4.h"
#include "Serial.h"
#include "IO.h"
#include "string.h"
#include "Time.h"

void Time_Init()
{
	/*Desativa o módulo*/
	LPTMR0_BASE_PTR->CSR = 0;
	
	/*Fonte de clock: LPO (PCS = 1) e prescale div. 2 (PRESCALE = 0)*/
	LPTMR0_BASE_PTR->PSR = LPTMR_PSR_PCS(1) | LPTMR_PSR_PRESCALE(0);
	
	/*Habilita interrupções / Por padrão está no modo de temporizador*/
	LPTMR0_BASE_PTR->CSR = LPTMR_CSR_TIE_MASK;
	
	/*Valor de comparação*/
	LPTMR0_BASE_PTR->CMR = 500;
	
	/*Habilita interrupção do LPTM no NVIC*/
	NVIC_EnableIRQ(LPTMR0_IRQn);
	
	/*Habilita o timer*/
	LPTMR0_BASE_PTR->CSR |= LPTMR_CSR_TEN_MASK;
}


