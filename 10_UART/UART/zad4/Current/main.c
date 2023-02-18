#include <LPC21xx.H>

#define NULL '\0'

#include "timer.h"
#include "timer_interrupts.h"
#include "led.h"
#include "keyboard.h"
#include "Servo.h"
#include "uart.h"

extern char cOdebranyZnak;
extern struct Servo eServo;

int main(){
		
	unsigned int iMainLoopCtr;
	KeyboardInit();
	ServoInit(200);
	DetectorInit();
	UART_InitWithInt(9600);
	
	
	
	while(1){
		iMainLoopCtr++;
		switch(cOdebranyZnak){
		case '1':
			eServo.uiDesiredPosition = eServo.uiDesiredPosition + 12;
			cOdebranyZnak = NULL;
			break;
		case 'c':
			eServo.eState = CALLIB;
			break;
				
		}
			switch(ReadKeyboardState()){
			case BUTTON_0:
				eServo.eState = CALLIB;
				break;
			case BUTTON_1:
				eServo.uiDesiredPosition = 12;
				break;
			case BUTTON_2:
				eServo.uiDesiredPosition = 24;
				break;
			case BUTTON_3:
				eServo.uiDesiredPosition = 36;
				break;
			default:
				break;
		}
	}
}

