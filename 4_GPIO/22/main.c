#include <LPC21xx.H>

#define LED0_bm 1<<16
#define LED1_bm 1<<17
#define LED2_bm 1<<18
#define LED3_bm 1<<19

#define BUTTON0_bm 1<<4
#define BUTTON1_bm 1<<5
#define BUTTON2_bm 1<<6
#define BUTTON3_bm 1<<7

typedef enum{LEFT, RIGHT}Direction;

typedef enum  {RELEASED, BUTTON_0, BUTTON_1, BUTTON_2, BUTTON_3} KeyboardState;

void delay(int iMillisecond)
{
	int iLoopCounter;
	iMillisecond=iMillisecond*12000;
	for(iLoopCounter=0;iLoopCounter<iMillisecond;iLoopCounter++) {}
}

void LedInit()
{
    IO1DIR=IO1DIR|LED0_bm|LED1_bm|LED2_bm|LED3_bm;
    IO1SET=LED0_bm;
}

void LedOn(unsigned char ucLedlndeks)
{
    IO1CLR=(LED0_bm | LED1_bm | LED2_bm | LED3_bm);
    switch(ucLedlndeks)
    {
			case 0:
			{
				IO1SET=IO1SET | LED0_bm;
				break;
			}
			case 1:
			{
				IO1SET=IO1SET | LED1_bm;
				break;
			}
			case 2:
			{
				IO1SET=IO1SET | LED2_bm;
				break;
			}
			case 3:
			{
				IO1SET=IO1SET | LED3_bm;
				break;
			}
		}
}

void KeyboardInit()
{
    IODIR0=IODIR0 & BUTTON0_bm & BUTTON1_bm & BUTTON2_bm & BUTTON3_bm;
}

KeyboardState eKeyboard_Read(void)
{
    if(!(IO0PIN & BUTTON0_bm))
		{
			return BUTTON_0;
		}
    else if (!(IO0PIN & BUTTON1_bm))
		{
			return BUTTON_1;
		}
    else if (!(IO0PIN & BUTTON2_bm))
		{
			return BUTTON_2;
		}
    else if (!(IO0PIN & BUTTON3_bm))
		{
			return BUTTON_3;
		}
    else
		{
			return RELEASED;
		}
}

unsigned int uiStateLed;
void LedStep(Direction eDirection)
{
  switch(eDirection)
	{
    case LEFT:
    {
        uiStateLed++;
        LedOn(uiStateLed%4);
        break;
    }
    case RIGHT:
    {
        uiStateLed--;
        LedOn(uiStateLed%4);
        break;
    }
   }
}

int main() 
{
	LedInit();
	KeyboardInit();
	while(1)
	{
		unsigned int uiLoopCounter;
		for(uiLoopCounter=0;uiLoopCounter<9;uiLoopCounter++)
		{
			LedStep(RIGHT);
			delay(500);
		}
		for(uiLoopCounter=0;uiLoopCounter<9;uiLoopCounter++)
		{
			LedStep(LEFT);
			delay(500);
		}
	}
}
