#include <LPC21xx.H>

#define LED0_bm 1<<16
#define LED1_bm 1<<17
#define LED2_bm 1<<18
#define LED3_bm 1<<19

#define BUTTON1_bm 1<<4
#define BUTTON2_bm 1<<5
#define BUTTON3_bm 1<<6
#define BUTTON4_bm 1<<7

typedef enum {RELEASED, PRESSED} ButtonState;

void delay(int i){
	int licznik;
	i=i*12000;
	for(licznik=0;licznik<i;licznik++) {
		
	}
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
        IO1SET=IO1SET | LED0_bm;
        break;
    case 1:
        IO1SET=IO1SET | LED1_bm;
        break;
    case 2:
        IO1SET=IO1SET | LED2_bm;
        break;
    case 3:
        IO1SET=IO1SET | LED3_bm;
        break;

    }
}

ButtonState ReadButton1()
{
    if(IO0PIN&BUTTON1_bm)
    {
        return RELEASED;
    }
    else
    {
        return PRESSED;
    }
}

void KeyboardInit()
{
    IODIR0=IODIR0 | BUTTON1_bm | BUTTON2_bm | BUTTON3_bm | BUTTON4_bm;
}

int main() 
{
	KeyboardInit();
	while(1)
	{
		
	}
}
