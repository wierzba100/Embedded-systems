#include <LPC21xx.H>

#include "timer.h"

#define Counter_Enable 1<<0
#define Counter_Reset 1<<1
#define MR0_Interrupt 1<<0
#define MR0_Reset 1<<1
#define MR0_Stop 1<<2   

void initTimer0(void)
{
	T0TCR=Counter_Enable;
}

void WaitOnTimer0(unsigned int uiTime)
{
	T0TCR=T0TCR | Counter_Reset;
	T0TCR=T0TCR & (~(Counter_Reset));
	while(T0TC < (uiTime*15)){}
}

void InitTimer0Match0(unsigned int uiDelayTime)
{
	T0MR0=uiDelayTime*15;													//wpisuje do T0MR0 ilosc taktow o ile ma czekac
	T0TCR=T0TCR | MR0_Reset;											//resetuje timer
	T0TCR=T0TCR & (~(MR0_Reset));									//zeruje flage resetu
	T0TCR=T0TCR | Counter_Enable;									//uruchamiam timer
	T0MCR=T0MCR | MR0_Interrupt;									//ustawiam timer by zglosil przerwanie gdy rejestr TC=T0MR0
	T0MCR=T0MCR | MR0_Reset;											//ustawiam timer by zresetowal rejestr TC gdy rejestr TC=T0MR0
}

void WaitOnTimer0Match0(void)
{
	while((T0IR & MR0_Interrupt)==0){}				//czekam na ustawienie flagi przerwania w rejestrze IR
	T0IR=MR0_Interrupt;												//kasuje flage przerwania
}
