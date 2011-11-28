#include "ArduinoProgram.h"


//----------------------------------------------------
void ArduinoProgram::setup(){
	Serial.begin(9600); 
	Serial.println("------------------");
	Serial.println("   hello world");
	Serial.println("------------------");
	delay(100);
}

//----------------------------------------------------
void ArduinoProgram::loop(){
		
}

