#include <LPC21xx.H>
#include "timer.h"
#include "timer_interrupts.h"
#include "led.h"
#include "keyboard.h"
#include "Servo.h"

#define DETECTOR_bm	(1<<10)

enum DetectirStat{ACTIVE, INACTIVE};
enum ServoSate {CALLIB, IDLE, IN_PROGRESS};

struct Servo{
	enum ServoSate eState;
	unsigned int uiCurrentPosition;
	unsigned int uiDesiredPosition;
};

struct Servo eServo;

enum DetectirStat eReadDetector(){
	if((IO0PIN & DETECTOR_bm) == 0){
		return ACTIVE;
	}
	else{
		return INACTIVE;
	}
}

void DetectorInit(){
	IO0DIR = (IO0DIR & (~DETECTOR_bm));

}



void Automat(){
	
	//eServoState = CALLIB;
	
	switch(eServo.eState){
			case CALLIB:
				if(eReadDetector() == ACTIVE){
					eServo.uiCurrentPosition = 0;
					eServo.uiDesiredPosition = 0;
					eServo.eState = IDLE;
						}
				else{
					LedStepRight();}
					break;	
			case IDLE:
				if(eServo.uiCurrentPosition == eServo.uiDesiredPosition){
					eServo.eState = IDLE;}
				else{
					eServo.eState = IN_PROGRESS;}		
				break;
			case IN_PROGRESS:
				if(eServo.uiCurrentPosition < eServo.uiDesiredPosition){	
					LedStepRight();
					eServo.uiCurrentPosition++;}					
				else if(eServo.uiCurrentPosition > eServo.uiDesiredPosition){
					LedStepLeft();
					eServo.uiCurrentPosition--;}					
				else{
					eServo.eState = IDLE;}
					break;
			
		}
	}

void ServoCallib(){
	eServo.eState = CALLIB;
}

void ServoInit(unsigned int uiServoFrequency){
	LedInit();
	ServoCallib();
	Timer0Interrupts_Init(((1/(double)uiServoFrequency))*1000000, &Automat);
}

void ServoGoTo(unsigned int uiPosition){
	eServo.uiDesiredPosition = uiPosition;
}
