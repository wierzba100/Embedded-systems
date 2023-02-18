#include <LPC21xx.H>

void delay(int i){
	int licznik;
	i=i*12000;
	for(licznik=0;licznik<i;licznik++) {
		
	}
}


int main() {
	IO1DIR=IO1DIR | 0x00010000;
	while(1){
		IO1SET=IO1SET | 0x00010000;
		delay(1001);
		IO1CLR=IO1CLR | 0x00010000;
	}
}
