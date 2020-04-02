/* Sun Tracker UART module
 * Ben Myles and Vanessa McGaw
 * 2020-02-26
 * Functions to interface the UART module on the FRDM K64F
 * */

#ifndef UART_SEEN
#define UART_SEEN

#include "fsl_device_registers.h"

/**
 * Purpose: Initialize UART
 * Inputs: none
 * Outputs: none
 * Called functions:
 * 		none
 * */
void uart_init() {
	// Enable Clock for UART0
	SIM_SCGC4 |= SIM_SCGC4_UART0_MASK;

	// Configure port bits
	SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK;

	PORTB_PCR16 |= PORT_PCR_MUX(3); // Rx
	PORTB_PCR17 |= PORT_PCR_MUX(3); // Tx

	// Configure UART for 8 bits
	UART0_C1 = 0;

	// Disable Transmitter & Receiver
	UART0_C2 &= ~(UART_C2_TE_MASK | UART_C2_RE_MASK);

	// Set Baud Rate = 9600
	UART0_BDH = 0;
	UART0_BDL = 0x88;

	// Enable Transmitter & Receiver
	UART0_C2 |= UART_C2_TE_MASK;
	UART0_C2 |= UART_C2_RE_MASK;
}

/**
 * Purpose: Output one character to UART
 * Inputs: character value
 * Outputs: none
 * Called functions:
 * 		none
 * */
void uart_putchar(char c) {
	//Poll TDRE
	int tdre = UART0_S1 >> 7;
	while (!tdre)
		tdre = UART0_S1 >> 7;

	// Write Character to UART
	UART0_D = c;
}

/**
 * Purpose: Output a string of characters to UART
 * Inputs: Pointer to character string
 * Outputs: none
 * Called functions:
 * 		Uart.c : uart_putchar
 * */
void uart_putstr(char* str) {
	int i = 0;
	while (str[i])
	{
		uart_putchar(str[i]);
		i++;
	}
}

/**
 * Purpose: Retrieve character input from the UART
 * Inputs: none
 * Outputs: character data from UART
 * Called functions:
 * 		none
 * */
char uart_getchar() {
	//Poll RDRF
	while (! (UART0_S1 & 0b00100000 ));

	return UART0_D;
}

#endif
