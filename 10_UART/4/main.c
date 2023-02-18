#include "led.h"
#include "timer_interrupts.h"
#include "keyboard.h"
#include "servo.h"
#include "uart.h"

extern char cOdebranyZnak;

int main ()
{	
	unsigned int uiCurrentPosition;
	UART_InitWithInt(9600);
	ServoInit(100);
	uiCurrentPosition = 0;
	
	while (1) 
	{	
		switch(cOdebranyZnak) 
		{
			case '1':
				uiCurrentPosition += 12;
				ServoGoTo(uiCurrentPosition);
				cOdebranyZnak = '\0';
				break;
			case 'c':
				ServoCallib();
				uiCurrentPosition = 0;
			default:
				break;
		}
	}
}
