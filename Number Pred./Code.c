#include "SevSeg.h"
SevSeg sevseg; 
const int buttonPin = 13;     // the number of the pushbutton pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int S1 = 6;
int S2 = 7;

void setup(){
  pinMode(S1,OUTPUT);
  pinMode(S2,OUTPUT);
  
    byte numDigits = 1;
    byte digitPins[] = {};
     byte segmentPins[] = {2, 3, 4, 5, 10, 11, 12, 0};
    bool resistorsOnSegments = true;
 
    sevseg.begin(COMMON_ANODE, numDigits, digitPins, segmentPins, resistorsOnSegments);
    sevseg.setBrightness(90);
  
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop()
{
  digitalWrite(S2,HIGH);
   digitalWrite(S1,LOW);
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  
  if (buttonState == HIGH) 
  {
    sevseg.setNumber(random(1,7));
    sevseg.refreshDisplay(); 
  }
}
