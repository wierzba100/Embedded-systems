#include <LPC21xx.H>
#include "timer.h"
#include "timer_interrupts.h"
#include "led.h"
#include "keyboard.h"
#include "Servo.h"
#include "uart.h"

int main(){
		
	unsigned int iMainLoopCtr;
	KeyboardInit();
	//ServoInit(10);
	DetectorInit();
	UART_InitWithInt(20);
	
	
	
	while(1){
		iMainLoopCtr++;
		
		}
}

