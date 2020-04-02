/* Sun Tracker Position Sensor simulated module
 * Ben Myles and Vanessa McGaw
 * 2020-02-26
 * Functions to interact with a simulated position sensor. If a position sensor were available, this
 * module would instead be an interface for it.
 **/

#ifndef POSITION_SEEN
#define POSITION_SEEN

#include "fsl_device_registers.h"

// Global variable to keep track of simulated position sensor status
int* position;

/**
 * Purpose: Initialize Simulated Position Sensor
 * Inputs: none
 * Outputs: none
 * Called functions:
 * 		malloc
 * */
void positionsensor_init() {
    position = malloc(sizeof(int));
    // Initial position is position #1
    *position = -40;
}

/**
 * Purpose: set the value of the simulated position sensor
 * Inputs: angle in degrees of new position represented as an integer
 * Outputs: none
 * Called functions:
 * 		none
 * */
void position_set(int newposition) {
    *position = newposition;
}

/**
 * Purpose: get the value of the simulated position sensor
 * Inputs: none
 * Outputs: angle in degrees of current position represented as an integer
 * Called functions:
 * 		none
 * */
int position_get() {
    return *position;
}

#endif
