/* Sun Tracker CalibrationController
 * Ben Myles and Vanessa McGaw
 * 2020-02-26
 * Main program which defines the calibration sequence and when to execute it.
 * */

/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "fsl_device_registers.h"
#include "Led.c"
#include "Button.c"
#include "Uart.c"
#include "Adc.c"
#include "Dac.c"
#include "Clock.c"
#include "VoltageInterpreter.c"
#include "PositionSensor.c"

void calibrate();

int main(void)
{
	led_init();
	button_init();
	uart_init();
	adc_init();
	dac_init();
	timer_init();
	positionsensor_init();

	// Begin initial calibration sequence
	calibrate();
	timer_reset();

	// Main loop
	while (1) {

		if(timer_isdone() || button_ispressed())
		{
			calibrate();
			timer_reset();
		}
		
		// Constantly printing voltage to PuTTY
		get_voltage();
	}

    return 0;
}

// Calibration sequence
void calibrate() {
	int v, i;
	int highv = 0, highi = 0;

	// Turn LED on to signify SunTracker is busy
	led_on('r');

	// for each predefined angle, rotate to it and check the voltage levels
	for (i=1; i<=5; i++) {
		// move motor to position #i
		rotate_to(i);

		// check voltage
		v = get_voltage();

		// store highest voltage location
		if (v > highv) {
			highv = v;
			highi = i;
		}
	}

	// Move motor back to best position
	rotate_to(highi);

	// Turn LED off, going back to idle state
	led_off('a');
}
