#include <LPC21xx.H>

//IO1DIR=IO1DIR | (0x1<<0x00010000);
//IO1SET=IO1SET | (0x1<<0x00010000);

int main() {
	IO1DIR=0x00010000;
	IO1SET=0x00010000;
	while(1){}
}