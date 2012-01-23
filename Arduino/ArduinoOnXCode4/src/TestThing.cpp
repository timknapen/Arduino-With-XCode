
#include "TestThing.h"


void TestThing::setup(){
	Serial.println(" TestThing is setup again!");
}

void TestThing::doSomething(){
    Serial.println(" TestThing: do something!");
}


void TestThing::anotherMethod(int i){
    Serial.println(" another thing");
    delay(10);
    
}
