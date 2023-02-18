#include <LPC21xx.H>
#define LED0_bm 0x10000
#define LED1_bm 0x20000
#define LED2_bm 0x40000
#define LED3_bm 0x80000



void Delay(int DelayTime){
	
	int iLoopCtrl;
	
	for(iLoopCtrl = 0 ; iLoopCtrl < DelayTime * 1754.38283 ; iLoopCtrl++);
			
}

int main(){
	
	IO1DIR = 0xF0000;

	IO1SET = LED0_bm;
	IO1SET = LED1_bm;
	IO1SET = LED2_bm;
	IO1SET = LED3_bm;
	

	//while(1){}
	
}



