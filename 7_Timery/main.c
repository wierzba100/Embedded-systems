#include "led.h"
#include "keyboard.h"
#include "timer.h"

void Program1()
{
	LedInit();
	initTimer0();
	while(1)
	{
		LedStepLeft();
		WaitOnTimer0(1000000);
	}
}

void Program2()
{
	LedInit();
	InitTimer0Match0(1000000);
	while(1)
	{
		LedStepLeft();
		WaitOnTimer0Match0();
	}
}


int main(void)
{
	//Program1();
	Program2();
}
