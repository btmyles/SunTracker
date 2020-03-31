/* Sun Tracker motor controller
 * Ben Myles and Vanessa McGaw
 * 2020-02-29
 * */

#include <stdio.h>
#include "fsl_device_registers.h"
#include "Led.c"
#include "Uart.c"
#include "Dac.c"
#include "PositionSensor.c"
int i;
int degrees;
int angle;

void wait()
{
	for(i=0; i<1000; i++)
	{}
}
// It is assumed that this function rotates the motor clockwise by 20 degrees with attached solar panel
void move_motor()
{
	for (int voltage = 0; voltage < 4095; voltage++)
	{
		dac_convert(voltage);
		wait();
	}
	for (int voltage = 4095; voltage > 0; voltage--)
	{
		dac_convert(voltage);
		wait();
	}
}

void rotate_to(int position)
{
	int i;

	if (position == 1){
		angle = -40;
	}
	if (position == 2){
			angle = -20;
		}
	if (position == 3){
			angle = 0;
		}
	if (position == 4){
			angle = 20;
		}
	if (position == 5){
			angle = 40;
		}

	degrees = angle - position_get();

	if (degrees <= 0)
		{
			degrees = degrees + 360;
		}

	for(i = 0; i < (degrees/20); i++)// moves motor i*20 degrees
		{
			move_motor();

		}
	position_set(angle);
}
