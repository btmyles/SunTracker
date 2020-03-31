/* Sun Tracker main
 * Ben Myles and Vanessa McGaw
 * 2020-02-26
 * */

#ifndef BUTTON_SEEN
#define BUTTON_SEEN

#include "fsl_device_registers.h"

//Uses SW2 on FRDM-K64F
void button_init() {
	// Enable clock
	SIM_SCGC5 |= (0x01 << 11) | SIM_SCGC5_PORTE_MASK;
	//Mux for Button
	PORTC_PCR6 |= PORT_PCR_MUX(1) | PORT_PCR_DSE_MASK;
	// button is input
	GPIOC_PDDR &= 0x40 ^ GPIO_PDDR_PDD_MASK;
}

// return 1 if pressed
int button_ispressed() {
	return !GPIOC_PDIR;
}

#endif
