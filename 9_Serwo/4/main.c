#include <LPC21xx.H>

#include "timer_interrupts.h"
#include "led.h"
#include "keyboard.h"
#include "timer.h"
#include "servo.h"

int main ()
{	
	unsigned int iMainLoopCtr;
	KeyboardInit();
	DetectorInit();
	InitTimer0();
	
	ServoInit(10);
	ServoCallib();
	
	while(1)
	{
		iMainLoopCtr++;
		ServoGoTo(12);
	}
}  
