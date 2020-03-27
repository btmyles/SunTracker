/* Sun Tracker main
 * Ben Myles and Vanessa McGaw
 * 2020-02-26
 * */

#ifndef CLOCK_SEEN
#define CLOCK_SEEN
#include "fsl_device_registers.h"

unsigned long long * pOverflowCounter;

// sets up timer module
void timer_init() {
	// Enable clock to the module via
	    // SIM_SCGC6 for FTM0, FTM1, FTM2
	    SIM_SCGC6 |= 1<<25;

	    // Configure port bits for FTM instead of GPIO
	    // PTB12 alt 3 is mapped to FTM1_CH0

	    // Enable port
	    SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK;
	    // setup pin mux
	    PORTB_PCR12 |= PORT_PCR_MUX(3);
	    //PORTB_PCR20 |= PORT_PCR_MUX(6);
	    // configure pins (PDDR?)
	    SIM_SOPT4 |= 1<<18;

	    // Mod is max value
	    FTM1_MOD = 0xFFFF;
	    // WPDIS = 1 & FTMEN = 1
	    FTM1_MODE = 0x5;
	    // Output and combine
	    FTM1_C0SC &= 0x28;
	    // Use system clock
	    FTM1_SC |= 1<<3;
	    // prescale factor = divide by 128
	    FTM1_SC |= 0x7;

	    pOverflowCounter = (unsigned long long *) malloc(sizeof(unsigned long long));
}

// Resets timer
void timer_reset() {
	FTM1_CNTIN = 0;
	FTM1_CNT = 0;
	*pOverflowCounter = 0;
}

// Function returns boolean true if time has passed
int timer_isdone() {

	if ((FTM1_SC>>7) == 1) {
		// counter has overflowed
		(*pOverflowCounter)++;
	}

	unsigned long long extra = FTM1_CNT;

	// (number of overflows * cycles per overflow + remaining cycles in most recent overflow) * (3/120000/820) converting to ms
	long time = ((*pOverflowCounter)*0xFFFF + extra)*3/120000/820;

	//ms to seconds
	if ((time / 1000) > 15)
		return 1;
	else
		return 0;
}



#endif
