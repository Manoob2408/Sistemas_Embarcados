#include "MKL25Z4.h"
#include "IO.h"

void Pin_OutputMode(int port, int pin)
{
	uint32_t val = (1UL << pin);
	
	switch(port)
	{
		case PORT_A:
		GPIOA_BASE_PTR->PDDR |= val;
		break;
		
		case PORT_B:
		GPIOB_BASE_PTR->PDDR |= val;
		break;
		
		case PORT_C:
		GPIOC_BASE_PTR->PDDR |= val;
		break;
		
		case PORT_D:
		GPIOD_BASE_PTR->PDDR |= val;
		break;
		
		case PORT_E:
		GPIOE_BASE_PTR->PDDR |= val;
		break;
	}
}
/*************************************************/

void Pin_Set(int port, int pin){
	
	uint32_t val = (1UL << pin);
	
	switch(port)
	{
		case PORT_A:
			GPIOA_BASE_PTR->PSOR |= val;
			break;
		
		case PORT_B:
			GPIOB_BASE_PTR->PSOR |= val;
			break;
		
		case PORT_C:
			GPIOC_BASE_PTR->PSOR |= val;
			break;
		
		case PORT_D:
			GPIOD_BASE_PTR->PSOR |= val;
			break;
		
		case PORT_E:
			GPIOE_BASE_PTR->PSOR |= val;
			break;
	}
	
}
/*************************************************/

void Pin_Clear(int port, int pin){
	
	uint32_t val = (1UL << pin);
	
	switch(port)
	{
		case PORT_A:
			GPIOA_BASE_PTR->PCOR |= val;
			break;
		
		case PORT_B:
			GPIOB_BASE_PTR->PCOR |= val;
			break;
		
		case PORT_C:
			GPIOC_BASE_PTR->PCOR |= val;
			break;
		
		case PORT_D:
			GPIOD_BASE_PTR->PCOR |= val;
			break;
		
		case PORT_E:
			GPIOE_BASE_PTR->PCOR |= val;
			break;
	} 
}

/*************************************************/

void ENABLE_PORTS(int port)
{
	
	switch(port)
	{
		case PORT_A:
		SIM_BASE_PTR->SCGC5 |= (1<<9);
		break;
		
		case PORT_B:
		SIM_BASE_PTR->SCGC5 |= (1<<10);
		break;
		
		case PORT_C:
		SIM_BASE_PTR->SCGC5 |= (1<<11);
		break;
		
		case PORT_D:
		SIM_BASE_PTR->SCGC5 |= (1<<12);
		break;
		
		case PORT_E:
		SIM_BASE_PTR->SCGC5 |= (1<<13);
		break;
	}
}

/*************************************************/

void SetPinMode(int port, int pin){
	
	
	switch(port)
	{
		case PORT_A:
		PORTA_BASE_PTR->PCR[pin] = (1<<8);
		break;
		
		case PORT_B:
		PORTB_BASE_PTR->PCR[pin] = (1<<8);
		break;
		
		case PORT_C:
		PORTC_BASE_PTR->PCR[pin] = (1<<8);
		break;
		
		case PORT_D:
		PORTD_BASE_PTR->PCR[pin] = (1<<8);
		break;
		
		case PORT_E:
		PORTE_BASE_PTR->PCR[pin] = (1<<8);
		break;
	}
}

/*************************************************/
int GetPinValue(int port, int pin){
	
	uint32_t val = (1UL << pin);
	
	switch(port)
	{
		case PORT_A:
			return GPIOA_BASE_PTR->PDIR & val;
			break;
		
		case PORT_B:
			return GPIOB_BASE_PTR->PDIR & val;
			break;
		
		case PORT_C:
			return GPIOC_BASE_PTR->PDIR & val;
			break;
		
		case PORT_D:
			return GPIOD_BASE_PTR->PDIR & val;
			break;
		
		case PORT_E:
			return GPIOE_BASE_PTR->PDIR & val;
			break;
	} 
}