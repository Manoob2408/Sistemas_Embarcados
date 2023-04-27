#include "MKL25Z4.h"
#include "Serial.h"
#include "IO.h"
#include "string.h"
#include "Time.h"

void Time_Init()
{
	/*Desativa o m�dulo*/
	LPTMR0_BASE_PTR->CSR = 0;
	
	/*Fonte de clock: LPO (PCS = 1) e prescale div. 2 (PRESCALE = 0)*/
	LPTMR0_BASE_PTR->PSR = LPTMR_PSR_PCS(1) | LPTMR_PSR_PRESCALE(0);
	
	/*Habilita interrup��es / Por padr�o est� no modo de temporizador*/
	LPTMR0_BASE_PTR->CSR = LPTMR_CSR_TIE_MASK;
	
	/*Valor de compara��o*/
	LPTMR0_BASE_PTR->CMR = 500;
	
	/*Habilita interrup��o do LPTM no NVIC*/
	NVIC_EnableIRQ(LPTMR0_IRQn);
	
	/*Habilita o timer*/
	LPTMR0_BASE_PTR->CSR |= LPTMR_CSR_TEN_MASK;
}


