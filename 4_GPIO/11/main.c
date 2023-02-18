#include <LPC21xx.H>

#define LED0_bm 1<<16
#define LED1_bm 1<<17
#define LED2_bm 1<<18
#define LED3_bm 1<<19

void delay(int i){
	int licznik;
	i=i*12000;
	for(licznik=0;licznik<i;licznik++) {
		
	}
}


int main() 
{
	IO1DIR=IO1DIR | LED0_bm;
	IO1DIR=IO1DIR | LED1_bm;
	IO1DIR=IO1DIR | LED2_bm;
	IO1DIR=IO1DIR | LED3_bm;
	while(1)
	{
		IO1SET=IO1SET | LED0_bm;
		IO1SET=IO1SET | LED1_bm;
		IO1SET=IO1SET | LED2_bm;
		IO1SET=IO1SET | LED3_bm;
	}
}
