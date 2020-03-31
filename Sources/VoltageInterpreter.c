/* Sun Tracker voltage interpreter
 * Ben Myles and Vanessa McGaw
 * 2020-02-26
 * Interact with the ADC and UART to read voltage values and print them to the PuTTY terminal
 * */

#include "fsl_device_registers.h"
#include "Led.c"
#include "Uart.c"
#include "Adc.c"
#include "String.c"

#define STRLEN 10

void output_voltage(int result) {
	char result_str[STRLEN];

	result = result*3300/65535;

	// result must be converted to character in order to print it.
	int2str(result_str, result);

	uart_putstr(result_str);
	uart_putstr("\n");
	uart_putchar(0xd);
}

int get_voltage() {
	// Read result of conversion
	int result = adc_convert();
	output_voltage(result);

	return result;
}
