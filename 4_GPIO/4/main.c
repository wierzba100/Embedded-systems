#include <LPC21xx.H>

void delay(){
	int i;
	for(i=0;i<1000;i++) {
		
	}
}

int main() {
	IO1DIR=IO1DIR | 0x00010000;
	while(1){
		IO1SET=IO1SET | 0x00010000;
		delay();
		IO1CLR=IO1CLR | 0x00010000;
	}
}
