/*
 *  LED.h
 *  Arduino-1
 *
 *  Created by OlS (MacBook) on 15/02/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef LED_h
#define LED_h

class LED
{
private:
	int _pin;
public:
    LED();
    void begin(int pin);
	void on();
    void off();
    void blink(int times, int duration);
};

#endif
