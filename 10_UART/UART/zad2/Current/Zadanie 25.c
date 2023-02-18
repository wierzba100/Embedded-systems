#include <LPC21xx.H>
#include "led.h"
#include "keyboard.h"

int main(){

	KeyboardInit();
	LedInit();
	
	while(1){
		switch(ReadKeyboardState()){
			case BUTTON_1:
				LedStep(RIGHT);
				break;
			case BUTTON_2:
				LedStep(LEFT);
				break;
			case RELASED:
				break;
			default:
				break;
		}
		Delay(50);
	}
}


