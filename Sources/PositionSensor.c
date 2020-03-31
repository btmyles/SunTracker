/* Sun Tracker main
 * Ben Myles and Vanessa McGaw
 * 2020-02-26
 **/
 
 /* This is for simulation purposes only, as we do not have a position sensor.*/

#ifndef POSITION_SEEN
#define POSITION_SEEN

#include "fsl_device_registers.h"

int* position;

void positionsensor_init() {
    position = malloc(sizeof(int));
    *position = -60;
}

void position_set(int newposition) {
    *position = newposition;
}

int position_get() {
    return *position;
}

#endif