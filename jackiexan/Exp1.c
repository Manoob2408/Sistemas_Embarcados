#include "MKL25Z4.h"

int main(void)
{
	/*Habilita o clock para o PORTB e PORTD*/
	SIM_BASE_PTR->SCGC5 = (1<<10) | (1<<12);
	
	/*Configura a função do pino PTB18 como I/O*/
	//Led Vermelho
	PORTB_BASE_PTR->PCR[18] = (1<<8);
	
	//Verde
	PORTB_BASE_PTR->PCR[19] = (1<<8);
	
	//Azul
	PORTD_BASE_PTR->PCR[1] = (1<<8);
	
	/*Configura a direção do pino PTB18 como saída*/
	GPIOB_BASE_PTR->PDDR=(1<<18);
	
	//Verde
	//Função OU para não sobrepor o valor no PDDR
	GPIOB_BASE_PTR->PDDR|=(1<<19);
	
	//Azul
	GPIOD_BASE_PTR->PDDR=(1<<1);
	
	while(1){
		
		for(int a=0;a<100000;a++)
		{
			GPIOB_BASE_PTR->PCOR=(1<<18);
			GPIOB_BASE_PTR->PSOR=(1<<18);
		}
		
		for(int a=0; a<100000; a++)
		{

			GPIOB_BASE_PTR->PCOR=(1<<19);
			GPIOB_BASE_PTR->PSOR=(1<<19);
				
		}
		
		for(int a=0; a<100000; a++)
		{

			GPIOD_BASE_PTR->PCOR=(1<<1);
			GPIOD_BASE_PTR->PSOR=(1<<1);
				
		}
	}
	
	
	return 0;
}