#include <ams_as5048b.h>
// authors: David Howlett, Peter Dobson, 

// the constant U_DEG means the results are given in degrees
#define U_DEG 3

// declare an array of sensors
# define NUM_SENSORS 4
AMS_AS5048B sensors[NUM_SENSORS];
FlightSimFloat angles[NUM_SENSORS];

void setup() {
  //Start serial
  Serial.begin(9600);
  while (!Serial) ; //wait until Serial ready
  //init AMS_AS5048B objects, each with it's own address
  for(int i=0;i<NUM_SENSORS;i++){
    sensors[i].chipAddress = 0x40+i;
    sensors[i].begin();
  }
}

void loop() {
  for(int i=0;i<NUM_SENSORS;i++){
    Serial.print("auto gain: ");
    Serial.print(sensors[i].getAutoGain());
    Serial.print(" angle: ");
    angles[i] = sensors[i].angleR(U_DEG,true);
    Serial.print(angles[i]);
    Serial.print(' ');
  }
  Serial.print('\n');
  FlightSim.update();
  delay (5);
}
