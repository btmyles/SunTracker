/* Sun Tracker Button module
 * Ben Myles and Vanessa McGaw
 * 2020-02-26
 * Provides a layer of abstraction with functions to interact with the buttons on FRDM K64F
 * */

#ifndef BUTTON_SEEN
#define BUTTON_SEEN

#include "fsl_device_registers.h"

void button_init() {
	// Enable clock
	SIM_SCGC5 |= (0x01 << 11) | SIM_SCGC5_PORTE_MASK;
	// Mux for SW2
	PORTC_PCR6 |= PORT_PCR_MUX(1) | PORT_PCR_DSE_MASK;
	// SW2 is input
	GPIOC_PDDR &= 0x40 ^ GPIO_PDDR_PDD_MASK;
}

// Return 1 if pressed
int button_ispressed() {
	return !GPIOC_PDIR;
}

#endif
