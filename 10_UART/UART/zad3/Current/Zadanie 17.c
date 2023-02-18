#include <LPC21xx.H>
#define LED0_bm 0x10000
#define LED1_bm 0x20000
#define LED2_bm 0x40000
#define LED3_bm 0x80000
#define LED0_3_bm 0xF0000
#define BUT0_bm 0x10

enum ButtonState {RELASED, PRESSED};

void Delay(int DelayTime){
	
	int iLoopCtrl;
	
	for(iLoopCtrl = 0 ; iLoopCtrl < DelayTime * 1754.38283 ; iLoopCtrl++);
			
}

void LedInit(){
	
	IO1DIR = IO1DIR | (LED0_bm | LED1_bm | LED2_bm | LED3_bm);
	IO1SET = LED0_bm;

}

void LedOn(unsigned char ucLedIndeks){

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
}

enum ButtonState ReadButton1(){
	
	
	if((IO0PIN & BUT0_bm) == 0){
		return PRESSED;}
	else{
		return RELASED;}
}



int main(){
	IO0DIR = IO0DIR & BUT0_bm;
	IO1DIR = IO1DIR | (LED0_bm | LED1_bm);	
	
	
	
	while(1){
		
		switch(ReadButton1()){
			case PRESSED:
				LedOn(1);
				break;
			case RELASED:
				LedOn(0);
				break;
		}
	}
		
}



