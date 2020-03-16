/* Sun Tracker DAC
 * Ben Myles and Vanessa McGaw
 * 2020-02-26
 * */

#ifndef DAC_SEEN
#define DAC_SEEN
#include "fsl_device_registers.h"

void dac_init() {
	// Enable the clock for DAC0 over AIPS1
	SIM_SCGC2 |= (1 << SIM_SCGC2_DAC0_SHIFT) | SIM_SCGC2_DAC0_MASK;

	// disable buffer
	//DAC0_C1 = 0;

	// Enable DAC
	DAC0_C0 |= 1<<7; // DAC enable
	DAC0_C0 |= 1<<6; // DACREF2 = VDDA
	DAC0_C0 |= 1<<5; // software trigger selected
}

void dac_convert(int num) {
	// Select channel to convert
	DAC0_DAT0L = (char) num & 0xFF;
	DAC0_DAT0H = (char) (num>>8) & 0xF;
}


#endif
