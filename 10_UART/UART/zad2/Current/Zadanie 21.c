#include <LPC21xx.H>
#define LED0_bm 0x10000
#define LED1_bm 0x20000
#define LED2_bm 0x40000
#define LED3_bm 0x80000
#define LED0_3_bm 0xF0000
#define BUT0_bm 0x10
#define BUT1_bm 0x40
#define BUT2_bm 0x20
#define BUT3_bm 0x80

unsigned int uiStepLeftCounter = 3;
unsigned int uiStepRightCounter = 8;



enum KeyboardState {RELASED, BUTTON_0, BUTTON_1, BUTTON_2, BUTTON_3};

void Delay(int DelayTime){
	
	int iLoopCtrl;
	
	for(iLoopCtrl = 0 ; iLoopCtrl < DelayTime * 1754.38283 ; iLoopCtrl++);
			
}

void LedInit(){
	
	IO1DIR = IO1DIR | (LED0_bm | LED1_bm | LED2_bm | LED3_bm);
	IO1SET = LED0_bm;

}

void LedOn(unsigned char ucLedIndeks){
	
		IO1DIR = IO1DIR | LED0_3_bm;	

	if(ucLedIndeks == 0){
		IO1CLR = LED0_3_bm;
		IO1SET = LED0_bm;}
	else if(ucLedIndeks == 1){
		IO1CLR = LED0_3_bm;
		IO1SET = LED1_bm;}
	else if(ucLedIndeks == 2){
		IO1CLR = LED0_3_bm;
		IO1SET = LED2_bm;}
	else if(ucLedIndeks == 3){
		IO1CLR = LED0_3_bm;
		IO1SET = LED3_bm;}
	else if(ucLedIndeks == 4){
		IO1CLR = LED0_3_bm;}
}

enum KeyboardState ReadKeyboardState(){
	
	
	if((IO0PIN & BUT0_bm) == 0){
		return BUTTON_0;}
	else if((IO0PIN & BUT1_bm) == 0){
		return BUTTON_1;}
	else if((IO0PIN & BUT2_bm) == 0){
		return BUTTON_2;}
	else if((IO0PIN & BUT3_bm) == 0){
		return BUTTON_3;}
	else{
		return RELASED;}
}


void KeyboardInit(){
	IO0DIR = IO0DIR & ~(BUT0_bm + BUT1_bm + BUT2_bm + BUT3_bm);
}	

void StepLeft(){
	uiStepLeftCounter++;
	LedOn(uiStepLeftCounter % 4);
	
}

void StepRight(){
	uiStepRightCounter--;
	LedOn(uiStepRightCounter % 4);
	
}
int main(){
	
	StepRight();
	Delay(50);
	StepRight();
	Delay(50);
	StepRight();
	Delay(50);
	StepRight();
	Delay(50);
	IO1SET = LED0_3_bm;
	
}


