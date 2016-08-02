/**************************************************************************/
/*!
    @file     xplane_dials_2.ino
    @author   @DavidHowlett (David Howlett, Peter Dobson)
    @license  BSD (see license.txt)

	This example uses an array of 4 sensors
	
    @section  HISTORY

    v1.0.0 - First release
	v1.0.1 - Make this example more generic

*/
/**************************************************************************/

#include <ams_as5048b.h>

// the constant U_DEG means the results are given in degrees
#define U_DEG 3

// declare an array of sensors
#define NUM_SENSORS 4
AMS_AS5048B sensors[NUM_SENSORS] = {AMS_AS5048B(0x40), AMS_AS5048B(0x41), AMS_AS5048B(0x42), AMS_AS5048B(0x43)};

double angles[NUM_SENSORS];
uint8_t AutoGain[NUM_SENSORS];

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
		AutoGain[i] = sensors[i].getAutoGain();
		angles[i] = sensors[i].angleR(U_DEG,true);
	}
	serialOutput();

	delay (5);
}

void serialOutput () {
	for(int i=0;i<NUM_SENSORS;i++){
		Serial.print("Sensor ");
		Serial.print(i);
		Serial.print(" | auto gain: ");
		Serial.print(AutoGain[i]);
		Serial.print(" | angle: ");
		Serial.println(angles[i]);
	}
	Serial.println("--------");
}