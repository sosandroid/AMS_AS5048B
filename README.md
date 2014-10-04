Arduino library for AS5048B from AMS
==============

	v1.0 - First release

AS5048B is a 14-bit magnetic rotary position sensor with digital angle (I2C) and PWM output.
This library deals only with the I2C channel


[AS5048B's](http://www.ams.com/eng/Products/Position-Sensors/Magnetic-Rotary-Position-Sensors/AS5048B) AMS page.

## Features ##
- Manage zero position
- Counts CW or CCW
- Reads Auto Gain & Diagnostics registers
- Reads 14 bits magnitude
- Reads 14 bits angle with various units output (raw, turn, degree, radian, grade, minute of arc, second of arc, Nato mil, Russian mil, Swedish mil)
- Computes an angular exponential moving average
- Reads exponential moving average angle and outputting with various units
- Resets Exp moving Avg

## Code examples ##
- Single angle reading, outputs 2 units
- Angular exponential moving average reading, outputs read angle and average
- Wind vane, outputs azimuth and compass direction

## Not available yet features ##
- PWM reading
- OTP setting
- OTP programming sequence
- Debug

## Testing ##
- Tested against AS5048B's official [adapter board](http://www.ams.com/eng/Support/Demoboards/Position-Sensors/Rotary-Magnetic-Position-Sensors/AS5048B-Adapterboard)
- Tested on Arduino Mega with Arduino IDE 1.0.5
- Please comment about other devices

