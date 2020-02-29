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

	// Disable buffer
	DAC0_C1 = 0;

	// Enable DAC
	DAC0_C0 |= 1<<7;

}

void dac_convert() {
	// Select channel to convert
	DAC0_DAT0L = DAC_DATL_DATA0_MASK;
	DAC0_DAT0H = DAC_DATH_DATA1_MASK;
}


#endif
