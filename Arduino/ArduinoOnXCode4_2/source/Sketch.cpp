#include "WProgram.h"
#include "I2C_Stepper.h"

// VARIABLES
int counter;

// a class in our src/ folder
TestThing* thing;



void setup(){
	counter = 0;
	Serial.begin(19200); 
    
	Serial.println("-----------------------------");
	Serial.println("   saying hi from XCode4     ");
    Serial.println("   ... again   ");
	Serial.println("-----------------------------");
	
}


void loop(){
    
	counter ++;
    
	Serial.print("loop nr. ");
	Serial.println(counter, DEC);
    
	delay(300);	
}

