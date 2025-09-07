/*
 * ATSAM3X8E_LED_Blink_With_SysTick_Timer.c
 *
 * Created: 08-Sep-25 2:08:40 AM
 * Author : P C Prusti
 */ 

#define F_CPU 84000000UL // 84 MHz
#include "sam.h"

#define LED_PIN PIO_PB27 // PB27
volatile uint32_t tick_count = 0;

void SysTick_Handler(void) 
{
	tick_count++;
	if (tick_count % 500 == 0) 
	{
		(PIOB->PIO_ODSR & LED_PIN) ? (PIOB->PIO_CODR |=LED_PIN) : (PIOB->PIO_SODR |=LED_PIN);  // Toggle LED
	}
}

void GpioInit()
{
	//PMC->PMC_PCER0 |= (1 << ID_PIOB);       // Enable PIOB clock
	//PIOB->PIO_PER |= LED_PIN;               // Enable control of PB27
	PIOB->PIO_OER |= LED_PIN;               // Set PB27 as output
}

int main(void) 
{
	/* Initialize the SAM system */
	SystemInit();
	
	/* Initialize the IO Pins */
	GpioInit();
	
	// Configure SysTick for 1ms interrupts
	SysTick_Config(F_CPU / 1000);

	while (1) 
	{
		// Main loop stays free for other tasks
	}
}

