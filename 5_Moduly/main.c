#include "led.h"
#include "keyboard.h"

void delay(int iMillisecond)
{
	int iLoopCounter;
	iMillisecond=iMillisecond*12000;
	for(iLoopCounter=0;iLoopCounter<iMillisecond;iLoopCounter++) {}
}

int main()
{
	LedInit();
	KeyboardInit();
	while(1)
	{
		switch(eKeyboardRead())
		{
        case BUTTON_1:
        {
          LedStepRight();
          break;
        }
        case BUTTON_2:
        {
          LedStepLeft();
          break;
        }
        default:
        {
					break;
				}
    }
		delay(100);
	}
}
