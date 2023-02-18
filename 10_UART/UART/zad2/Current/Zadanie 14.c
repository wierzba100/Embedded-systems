#include <LPC21xx.H>
#define LED0_bm 0x10000
#define LED1_bm 0x20000
#define LED2_bm 0x40000
#define LED3_bm 0x80000
#define LED0_3_bm 0xF0000



void Delay(int DelayTime){
	
	int iLoopCtrl;
	
	for(iLoopCtrl = 0 ; iLoopCtrl < DelayTime * 1754.38283 ; iLoopCtrl++);
			
}

void LedInit(){
	IO1DIR = LED0_bm + LED1_bm + LED2_bm + LED3_bm;
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

int main(){
	
	LedInit();
	
	
	while(1){

		
		LedOn(0);
		Delay(250);
	
		IO1CLR = LED0_bm;
		Delay(250);

		LedOn(1);
		Delay(250);

		IO1CLR = LED1_bm;
		Delay(250);

		LedOn(2);
		Delay(250);
	
		IO1CLR = LED2_bm;
		Delay(250);
	
		LedOn(3);
		Delay(250);

		IO1CLR = LED3_bm;
		Delay(250);
	

	}
	
}



