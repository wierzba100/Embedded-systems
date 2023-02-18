#include <LPC21xx.H>

#include "timer_interrupts.h"
#include "led.h"
#include "keyboard.h"
#include "timer.h"

#define DETECTOR_bm (1<<10)

enum DetectorState {ACTIVE,INACTIVE};

void DetectorInit()
{
	IO0DIR=(IO0DIR & (~DETECTOR_bm));
}

enum DetectorState eReadDetector()
{
	if((IO0PIN & DETECTOR_bm)==0)
	{
		return ACTIVE;
	}else
	{
		return INACTIVE;
	}
}

void automat()
{
	enum LedState{STOP,LED_RIGHT,LED_LEFT,CALLIB};
	static enum LedState eLedState=CALLIB;

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
		case CALLIB: 
			if(eReadDetector()==ACTIVE)
			{
				eLedState=STOP;
			}else 
			{
				LedStepRight();	
			}
			break;
	}
}


int main ()
{	
	unsigned int iMainLoopCtr;
	LedInit();
	KeyboardInit();
	DetectorInit();
	InitTimer0();
	Timer0Interrupts_Init(20000, &automat);
	while(1)
	{
		iMainLoopCtr++;
	}
}  
