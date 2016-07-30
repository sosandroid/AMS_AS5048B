#include <ams_as5048b.h>
// authors: David Howlett, Peter Dobson, 
// the constant U_DEG means the results are given in degrees
#define U_DEG 3

// declare an array of 4 sensors
AMS_AS5048B sensors[4];

void setup() {
  //Start serial
  Serial.begin(9600);
  while (!Serial) ; //wait until Serial ready
  //init AMS_AS5048B objects
  for(int i=0;i<4;i++){
    //sensors[i]
    sensors[i].begin();
  }
}

void loop() {
  /*
  //print to serial the degree angle
  knob0 = mysensor.angleR(U_DEG,true);
  knob0Diff = knob0 - knob0Prev;
  // If the knob0Diff is larger then 2 or less then -2
  // then the change should be sent over serial. 
  if (knob0Diff >= 10 || knob0Diff <= -10) {
    Serial.print("  Angle deg : ");
    Serial.print (knob0Diff);
    Serial.print(" : ");
    Serial.println (knob0);
    knob0Prev = knob0;
  }
  */

  Serial.println(sensors[0].angleRegR());
  delay (10);
}
