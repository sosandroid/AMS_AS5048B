/**************************************************************************/
/*!
    @file     xplane_dials.ino
    @author   @DavidHowlett (David Howlett, Peter Dobson)
    @license  BSD (see license.txt)

	This example uses an array of 4 sensors
	
    @section  HISTORY

    v1.0.0 - First release

*/
/**************************************************************************/

#include <ams_as5048b.h>
//FlightSimFloat.h missing

// the constant U_DEG means the results are given in degrees
#define U_DEG 3

// declare an array of sensors
# define NUM_SENSORS 4
AMS_AS5048B sensors[NUM_SENSORS] = {AMS_AS5048B(0x40), AMS_AS5048B(0x41), AMS_AS5048B(0x42), AMS_AS5048B(0x43)};

FlightSimFloat angles[NUM_SENSORS];

void setup() {
	//Start serial
	Serial.begin(9600);
	while (!Serial) ; //wait until Serial ready
	
	
	for(int i=0;i<NUM_SENSORS;i++){
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