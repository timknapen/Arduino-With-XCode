/*
 *  LED.cpp
 *  Arduino-4
 *
 *  Created by OlS (MacBook) on 15/02/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */
// #include "WConstants.h"
#include "WProgram.h"
#include "LED.h"



//	Constructor
LED::LED() {
	
}

// User API
void LED::begin(int pin) {
	_pin = pin;
	pinMode(_pin, OUTPUT);      // sets the digital pin as output
}

void LED::on() {
	digitalWrite(_pin, HIGH);
}

void LED::off() {
	digitalWrite(_pin, LOW);
}

void LED::blink(int times, int duration) {
	if (times>0) {
		for (int i=0; i<times; i++) {
			on();
			delay(duration);
			off();
			delay(duration);
		}
	}
}


