#include "ArduinoProgram.h"


void ArduinoProgram::setup(){
	counter = 0;
	Serial.begin(9600); 

	Serial.println("------------------");
	Serial.println("   hello world");
	Serial.println("------------------");
	
	//our class from our src/ folder
	thing = new TestThing();
	thing -> setup();
	
	// this is a stepper
	steppy = new Stepper(1,2,3);
	steppy->step(2);
	
}


void ArduinoProgram::loop(){
	counter ++;
	Serial.print("loop nr. ");
	Serial.println(counter, DEC);
	delay(100);	
}

