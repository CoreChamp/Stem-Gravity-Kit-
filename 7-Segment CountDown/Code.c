#include "SevSeg.h"
SevSeg sevseg;
int S1 = 6;
int S2 = 7;
void setup()
{
  pinMode(S1,OUTPUT);
  pinMode(S2,OUTPUT);
  //Set to 1 for single digit display
  byte numDigits = 1;

  //defines common pins while using multi-digit display. Left empty as we have a single digit display
  byte digitPins[] = {};

  //Defines arduino pin connections in order: A, B, C, D, E, F, G, DP
  byte segmentPins[] = {2, 3, 4, 5, 10, 11, 12, 0};
  bool resistorsOnSegments = true;

  //Initialize sevseg object. Uncomment second line if you use common cathode 7 segment
  sevseg.begin(COMMON_ANODE, numDigits, digitPins, segmentPins, resistorsOnSegments);
  //sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins, resistorsOnSegments);

  sevseg.setBrightness(90);
}

void loop()
{ 
   digitalWrite(S2,HIGH);
   digitalWrite(S1,LOW);
   //Display numbers one by one with 2 seconds delay
   for(int i = 0; i < 10; i++)
   {
     sevseg.setNumber(i);
     sevseg.refreshDisplay(); 
     delay(2000);
   }
   digitalWrite(S1,HIGH);
   digitalWrite(S2,LOW);
   //Display numbers one by one with 2 seconds delay
   for(int i = 0; i < 10; i++)
   {
     sevseg.setNumber(i);
     sevseg.refreshDisplay(); 
     delay(2000);
   }
}
