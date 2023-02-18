#include "led.h"
#include "keyboard.h"

void Delay(int iMillisecond)
{
	int iLoopCounter;
	iMillisecond=iMillisecond*12000;
	for(iLoopCounter=0;iLoopCounter<iMillisecond;iLoopCounter++) {}
}

void automat1()
{
	enum LedState{LED_LEFT,LED_RIGHT};
	enum LedState eLedState = LED_LEFT;
	while(1)
	{
		switch(eLedState)
		{
			case LED_LEFT:
				eLedState = LED_RIGHT;
				LedStepRight();
				break;
			case LED_RIGHT:
				eLedState = LED_LEFT;
				LedStepLeft();
				break;

		}
		Delay(250);
	}
}

void automat2()
{
	enum LedState {STATE0, STATE1, STATE2,STATE3,STATE4, STATE5};
	enum LedState eLedState=STATE0;
	while(1)
	{
		switch(eLedState)
		{
			case STATE0:
				eLedState = STATE1;
				LedStepRight();
				break;
      case STATE1:
				eLedState = STATE2;
				LedStepRight();
				break;
      case STATE2:
				eLedState = STATE3;
				LedStepRight();
				break;
      case STATE3:
        eLedState = STATE4;
        LedStepLeft();
        break;
      case STATE4:
        eLedState = STATE5;
        LedStepLeft();
        break;
      case STATE5:
        eLedState = STATE0;
        LedStepLeft();
        break;
		}
		Delay(250);
	}
}

void automat3()
{
	enum LedState{LED_LEFT,LED_RIGHT};
	enum LedState eLedState=LED_RIGHT;
	unsigned char LedStepsCounter=0;
	while(1)
	{
		switch(eLedState)
		{
			case LED_LEFT:
				LedStepLeft();
				if(LedStepsCounter==3)
				{
					eLedState=LED_RIGHT;
					LedStepsCounter=0;
				}
				break;
      case LED_RIGHT:
				LedStepRight();
				if(LedStepsCounter==3)
				{
					eLedState=LED_LEFT;
					LedStepsCounter=0;
				}
				break;
		}
		LedStepsCounter++;
		Delay(500);
	}
}

void automat4()
{
	enum LedState{STOP,LED_RIGHT};
	enum LedState eLedState=LED_RIGHT;
	unsigned char LedStepsCounter=0;
	while(1)
	{
		switch(eLedState)
		{
			case LED_RIGHT:
				LedStepRight();
				if(LedStepsCounter==3)
				{
					eLedState=STOP;
					LedStepsCounter=0;
				}
				LedStepsCounter++;
				break;
			case STOP:
				if(eKeyboardRead()==BUTTON_0)
				{
					eLedState=LED_RIGHT;
				}
				break;
		}
		Delay(250);
	}
}

void automat5()
{
	enum LedState{STOP,LED_RIGHT};
	enum LedState eLedState=LED_RIGHT;
	while(1)
	{
		switch(eLedState)
		{
			case LED_RIGHT:
				LedStepRight();
				if(eKeyboardRead()==BUTTON_0)
				{
					eLedState=STOP;
				}
				break;
			case STOP:
				if(eKeyboardRead()==BUTTON_2)
				{
					eLedState=LED_RIGHT;
				}
				break;
		}
		Delay(100);
	}
}

void automat6()
{
	enum LedState{STOP,LED_RIGHT,LED_LEFT};
	enum LedState eLedState=STOP;
	while(1)
	{
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
		Delay(100);
	}
}


int main()
{
	LedInit();
	KeyboardInit();
	//automat1();
	//automat2();
	//automat3();
	//automat4();
	//automat5();
	automat6();
}
