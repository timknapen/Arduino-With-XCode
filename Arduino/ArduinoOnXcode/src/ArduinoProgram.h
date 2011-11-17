#ifndef _ARDUINO_PROGRAM_H
#define _ARDUINO_PROGRAM_H

#include "WProgram.h"

/********************************************
 LIBRARIES

 To add your own libraries see the README file
 
 *********************************************/
	
#include "Stepper.h"	

#include "TestThing.h"

class ArduinoProgram {
public:
	
	
	// FUNCTIONS
	void setup();
	void loop();
	
	// VARIABLES
	int counter;
	
	// a class in our src/ folder
	TestThing* thing;
	
	// a library inside the Arduino App.
	Stepper* steppy;

};

#endif

