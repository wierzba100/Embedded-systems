#include <LPC21xx.H>

int main() {
	IO1DIR=IO1DIR | 0x00010000;
	while(1){
		IO1SET=IO1SET | 0x00010000;
		IO1CLR=IO1CLR | 0x00010000;
	}
}
