/* Sun Tracker motor controller
 * Ben Myles and Vanessa McGaw
 * 2020-02-29
 * Access the DAC and position sensor to move the motor to a new angle
 * */

#include "fsl_device_registers.h"
#include "Led.c"
#include "Uart.c"
#include "Dac.c"
#include "PositionSensor.c"

int degrees;
int angle;

void wait() {
	for(int i=0; i<1000; i++);
}

// It is assumed that this function rotates the motor clockwise by 20 degrees with attached solar panel
// This cannot be tested since the panel is not attached to the motor for the final submission
void move_motor() {
	for (int voltage = 0; voltage < 4095; voltage++) {
		dac_convert(voltage);
		wait();
	}
	for (int voltage = 4095; voltage > 0; voltage--) {
		dac_convert(voltage);
		wait();
	}
}

void rotate_to(int position) {
	if (position == 1)
		angle = -40;
	else if (position == 2)
		angle = -20;
	else if (position == 3)
		angle = 0;
	else if (position == 4)
		angle = 20;
	else if (position == 5)
		angle = 40;

	degrees = angle - position_get();

	if (degrees <= 0)
		degrees = degrees + 360;

	// Move motor i*20 degrees
	for(int i = 0; i < (degrees/20); i++)
		move_motor();
	
	position_set(angle);
}
