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

void positionsensor_init() {
    position = malloc(sizeof(int));
    // Initial position is position #1
    *position = -40;
}

void position_set(int newposition) {
    *position = newposition;
}

int position_get() {
    return *position;
}

#endif
