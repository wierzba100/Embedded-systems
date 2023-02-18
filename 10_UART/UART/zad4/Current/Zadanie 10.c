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
	
	IO1DIR = LED3_bm;
	IO0CLR = LED0_bm;
	

	while(1){	
	IO1SET = LED3_bm;
	Delay(50);
	IO1CLR = LED3_bm;
	Delay(50);
	

}
	
}


