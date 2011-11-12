#ifndef _ARDUINO_PROGRAM_H
#define _ARDUINO_PROGRAM_H

#include "WProgram.h"

/********************************************
 LIBRARIES
 uncomment to use.
 in the makefile, I added INCLUDE_LIBRARIES and  CPP_LIBRARIES
 
 INCLUDE_LIBRARIES are the paths to the library folder for adding with -I :
	# Place -I options here : include libraries
	CINCS = -I$(ARDUINO) $(INCLUDE_LIBRARIES)
	CXXINCS = -I$(ARDUINO) $(INCLUDE_LIBRARIES)
 
 CPP_LIBRARIES collects the .cpp files in these folders for adding to: CXXSRC
*********************************************/
// #include "LiquidCrystal.h"   
// #include "EEPROM.h"			
// #include "Servo.h"	
#include "Stepper.h"	

#include "TestThing.h"

class ArduinoProgram {
public:
	
	
	// FUNCTIONS
	void setup();
	void loop();
	
	// VARIABLES
	int counter;
	
	// a class in our src folder
	TestThing* thing;
	
	// a library inside the Arduino App.
	Stepper* steppy;

};

#endif

