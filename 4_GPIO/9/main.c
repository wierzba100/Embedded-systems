#include <LPC21xx.H>

#define LED0_bm 1<<16

void delay(int i){
	int licznik;
	i=i*12000;
	for(licznik=0;licznik<i;licznik++) {
		
	}
}


int main() {
	IO1DIR=IO1DIR | LED0_bm;
	while(1){
		IO1SET=IO1SET | LED0_bm;
		delay(100);
		IO1CLR=IO1CLR | LED0_bm;
		delay(100);
	}
}
