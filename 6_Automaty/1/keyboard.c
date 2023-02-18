#include<LPC21xx.h>

#include "keyboard.h"

#define BUTTON0_bm 1<<4
#define BUTTON1_bm 1<<5
#define BUTTON2_bm 1<<6
#define BUTTON3_bm 1<<7

void KeyboardInit(void)
{
    IODIR0=IODIR0 & BUTTON0_bm & BUTTON1_bm & BUTTON2_bm & BUTTON3_bm;
}

KeyboardState eKeyboardRead(void)
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
        return RELEASED_;
    }
}

ButtonState ReadButton1(void)
{
    if(IO0PIN&BUTTON0_bm)
    {
        return RELEASED;
    }
    else
    {
        return PRESSED;
    }
}

