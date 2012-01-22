

#include "WProgram.h"
#include "Sketch.cpp"

// Arduino doesn't know about new and delete, so let's teach 'm :
#include <stdlib.h> // for malloc and free
void* operator new(size_t size) { return malloc(size); }
void operator delete(void* ptr) { free(ptr); } 
// from: http://www.arduino.cc/cgi-bin/yabb2/YaBB.pl?num=1230935955


int main(void)
{
	init();
	setup();
	for (;;)
		loop();
	return 0;
}

