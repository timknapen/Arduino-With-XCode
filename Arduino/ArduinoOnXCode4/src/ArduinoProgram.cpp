#include "ArduinoProgram.h"

void ArduinoProgram::setup(){
	counter = 0;
	Serial.begin(9600); 
    
	Serial.println("-----------------------------");
	Serial.println("   saying hi from XCode4     ");
    Serial.println("   ... again   ");
	Serial.println("-----------------------------");
	
	//our class from our src/ folder
	thing = new TestThing();
	thing -> setup();
    
    // XCode does completion for this now too!
    servo->readMicroseconds();
}


void ArduinoProgram::loop(){
    
	counter ++;
    
	Serial.print("loop nr. ");
	Serial.println(counter, DEC);
    
    thing->doSomething();
    
    thing->anotherMethod(5);
    
	delay(300);	
}

