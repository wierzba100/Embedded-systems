#include <LPC21xx.H>

#include "timer_interrupts.h"
#include "led.h"
#include "keyboard.h"
#include "servo.h"
#include "uart.h"

int main ()
{	
	unsigned int iMainLoopCtr;
	
	UART_InitWithInt(10);
	
	while(1)
	{
		iMainLoopCtr++;
	}
}  
