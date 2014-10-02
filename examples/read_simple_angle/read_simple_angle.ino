/**************************************************************************/
/*!
    @file     read_simple_angle.ino
    @author   SOSAndroid (E. Ha.)
    @license  BSD (see license.txt)

	read a simple angle from AS5048B over I2C bus
	
    @section  HISTORY

    v1.0 - First release
*/
/**************************************************************************/

/**************************************************************************/
/*!
	Il semblerait que l'initialisation de l'objet FRAM en dehors de la fonction setup plante le programme
	Ce même objet initialisé dans la fonction setup n'est pas accessible d'ailleurs...
*/
/**************************************************************************/

#include <ams_as5048b.h>

AMS_AS5048B mysensor;

void setup() {

	//Start serial
	Serial.begin(9600);
	while (!Serial) ; //wait until Serial ready
	
	//Start Wire object. Unneeded here as this is done (optionnaly) by AMS_AS5048B object (see lib code - #define USE_WIREBEGIN_ENABLED)
	//Wire.begin();

	//init AMS_AS5048B object
	mysensor.begin();
	
	//consider the current position as zero
	mysensor.setZeroReg();

}

void loop() {
	//print to serial the raw angle and degree angle every 2 seconds
	//print 2 times the exact same angle - only one measurement
	Serial.print("Angle sensor raw : ");
	Serial.println(mysensor.angleR("RAW", true), DEC);
	
	Serial.print("Angle degree : ");
	Serial.println(mysensor.angleR("DEG", false), DEC);
	
	delay(2000);
}