#include "WProgram.h"
#include "TestThing.h"
#include "I2C_Stepper.h"

// VARIABLES
int counter;

// a class in our src/ folder
TestThing* thing;



void setup(){
	counter = 0;
	Serial.begin(9600); 
    
	Serial.println("-----------------------------");
	Serial.println("   saying hi from XCode4     ");
    Serial.println("   ... again   ");
	Serial.println("-----------------------------");
	
	//our class from our src/ folder
	thing = new TestThing();
	thing -> setup();
}


void loop(){
    
	counter ++;
    
	Serial.print("loop nr. ");
	Serial.println(counter, DEC);
    
    thing->doSomething();
    
    thing->anotherMethod(5);
    
	delay(300);	
}

