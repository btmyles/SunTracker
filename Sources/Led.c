/* Sun Tracker LED module
 * Ben Myles and Vanessa McGaw
 * 2020-02-26
 * Functions to interact with LEDs on FRDM K64F
 * */

#ifndef LED_SEEN
#define LED_SEEN

#include "fsl_device_registers.h"

// Possible values: 'a', 'r', 'b', 'g'
void led_on(char color) {
	if (color == 'a' || color == 'g')
		GPIOE_PCOR |= 0x01 << 26;
	if (color == 'a' || color == 'b')
		GPIOB_PCOR |= 0x01 << 21;
	if (color == 'a' || color == 'r')
		GPIOB_PCOR |= 0x01 << 22;
}

// Possible values: 'a', 'r', 'b', 'g'
void led_off(char color) {
	if (color == 'a' || color == 'g')
		GPIOE_PSOR |= 0x01 << 26;
	if (color == 'a' || color == 'b')
		GPIOB_PSOR |= 0x01 << 21;
	if (color == 'a' || color == 'r')
		GPIOB_PSOR |= 0x01 << 22;
}

// led_init enables all LEDs
void led_init() {
	// Enable clock
	SIM_SCGC5 |= (0x01 << 13) | SIM_SCGC5_PORTE_MASK;	//g
	SIM_SCGC5 |= (0x01 << 10) | SIM_SCGC5_PORTE_MASK;	//br

	// Mux for LED
	PORTE_PCR26 |= PORT_PCR_MUX(1) | PORT_PCR_DSE_MASK;	//g
	PORTB_PCR21 |= PORT_PCR_MUX(1) | PORT_PCR_DSE_MASK;	//b
	PORTB_PCR22 |= PORT_PCR_MUX(1) | PORT_PCR_DSE_MASK;	//r

	// LED is output
	GPIOE_PDDR |= 0x01 << 26;	//g
	GPIOB_PDDR |= 0x01 << 21;	//b
	GPIOB_PDDR |= 0x01 << 22;	//r

	led_off('a');
}

#endif
