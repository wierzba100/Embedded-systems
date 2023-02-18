#include <LPC21xx.H>
#include "timer.h"
#include "timer_interrupts.h"
#include "led.h"
#include "keyboard.h"
#include "Servo.h"
#include "uart.h"

extern char cOdebranyZnak;

int main(){
		
	unsigned int iMainLoopCtr;
	KeyboardInit();
	LedInit();
	//ServoInit(10);
	DetectorInit();
	UART_InitWithInt(9600);
	
	
	
	while(1){
		iMainLoopCtr++;
		switch(cOdebranyZnak){
		case '1':
			LedOn(0);
			break;
		case '2':
			LedOn(1);
			break;
		case '3':
			LedOn(2);
			break;
		case '4':
			LedOn(3);
			break;
		case 'c':
			LedOn(4);
			break;
				
		}
	}
}

