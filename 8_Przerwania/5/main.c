#include "timer_interrupts.h"
#include "led.h"
#include "keyboard.h"

void automat()
{
	enum LedState{STOP,LED_RIGHT,LED_LEFT};
	static enum LedState eLedState=STOP;

	switch(eLedState)
	{
		case LED_RIGHT:
			LedStepRight();
			if(eKeyboardRead()==BUTTON_2)
			{
				eLedState=STOP;
			}
			break;
		case STOP:
			if(eKeyboardRead()==BUTTON_0)
			{
				eLedState=LED_LEFT;
			}else if(eKeyboardRead()==BUTTON_1)
			{
				eLedState=LED_RIGHT;
			}
			break;
		case LED_LEFT:
			LedStepLeft();
			if(eKeyboardRead()==BUTTON_2)
			{
				eLedState=STOP;
			}
			break;
	}
}


int main (){
	
	unsigned int iMainLoopCtr;
	LedInit();
	Timer0Interrupts_Init(20000, &automat);

	while(1){}
}  
