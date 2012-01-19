#include "ArduinoProgram.h"
#include "LED.h"

// variables
LED myLed; // = LED(); 


// this is for a bug in Arduino 017/018:
extern "C" void __cxa_pure_virtual() { while (1); }

void setup(){
	Serial.begin(9600);	// opens serial port, sets data rate to 9600 bps
    
    
	myLed.begin(13);
	
	Serial.println("------------------");
	Serial.println("   hello world");
	Serial.println("------------------");
	
	myLed.on();
	delay(1000);
}


void blinking(uint8_t times) {
    myLed.blink(times, 1000/times);
}
    


void loop(){
	Serial.print("\n another blink! \n");
    blinking(3);
    blinking(5);
	delay(1000); // wait 1 sec
}

