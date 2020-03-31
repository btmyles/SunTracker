/* Sun Tracker ADC module
 * Ben Myles and Vanessa McGaw
 * 2020-02-26
 * Functions which allow easy access to the ADC functionality
 * */

#ifndef ADC_SEEN
#define ADC_SEEN
#include "fsl_device_registers.h"

void adc_init() {
	// Enable the clock
	SIM_SCGC3 |= (1 << SIM_SCGC3_ADC1_SHIFT) | SIM_SCGC3_ADC1_MASK;

	// Reference voltage max = 5V by beginning calibration
	ADC1_SC3 |= 1<<7;
	while (ADC1_SC3 & (~ADC_SC3_CAL_MASK));

	// 16 bit mode
	ADC1_CFG1 |= 1<<3;
	ADC1_CFG1 |= 1<<2;
}

int adc_convert() {
	// Select channel to convert
	ADC1_SC1A &= ADC_SC1_ADCH(18);

	// Wait for conversion to complete
	while (!ADC1_SC1A >> 7);

	// Return result of conversion
	return ADC1_RA;
}

int adc_getvoltage() {
	int result = adc_convert();
	// Convert result to a voltage value
	result = result*1.2/254;
	return result;
}

#endif
