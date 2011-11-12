#include "ArduinoProgram.h"


void ArduinoProgram::setup(){
	counter = 0;
	Serial.begin(9600); 

	Serial.println("------------------");
	Serial.println("   hello world");
	Serial.println("------------------");
	
	thing = new TestThing();
	thing -> setup();
	
	 steppy = new Stepper(1,2,3);
	 steppy->step(2);
	//Stepper steppy(1,2,4);
	//steppy.step(10);
	
}


void ArduinoProgram::loop(){
	counter ++;
	if(counter < 5){
		Serial.print("hello nr. ");
		Serial.println(counter, DEC);
	}else if(counter ==5) {
		Serial.println("I should not be sending hello.");
	}else {
		counter = 6;
	}

	// counter is int so will overflow!

	
}

