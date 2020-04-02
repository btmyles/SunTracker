/* Sun Tracker DAC
 * Ben Myles and Vanessa McGaw
 * 2020-02-26
 * Functions to interact with the DAC on FRDM K64F
 * */

#ifndef DAC_SEEN
#define DAC_SEEN
#include "fsl_device_registers.h"

/**
 * Purpose: Initialize DAC
 * Inputs: none
 * Outputs: none
 * Called functions:
 * 		none
 * */
void dac_init() {
	// Enable the clock for DAC0 over AIPS1
	SIM_SCGC2 |= (1 << SIM_SCGC2_DAC0_SHIFT) | SIM_SCGC2_DAC0_MASK;

	// Enable DAC
	DAC0_C0 |= 1<<7; // DAC enable
	DAC0_C0 |= 1<<6; // DACREF2 = VDDA
	DAC0_C0 |= 1<<5; // software trigger selected
}

/**
 * Purpose: Convert integer value to DAC output
 * Inputs: integer representation of DAC signal
 * Outputs: none
 * Called functions:
 * 		none
 * */
void dac_convert(int num) {
	// Select channel to convert
	DAC0_DAT0L = (char) num & 0xFF;
	DAC0_DAT0H = (char) (num>>8) & 0xF;
}


#endif
