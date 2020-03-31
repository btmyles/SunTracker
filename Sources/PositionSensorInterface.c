/* Sun Tracker main
 * Ben Myles and Vanessa McGaw
 * 2020-02-26
 * */

#ifndef POSITION_SEEN
#define POSITION_SEEN

#include "fsl_device_registers.h"

int* position;

void positionsensor_init() {
    position = malloc(sizeof(int));
    *position = -40;
}

void position_set(int newposition) {
    *position = newposition;
}

int position_get() {
    return *position;
}

#endif
