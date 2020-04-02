/* Sun Tracker string utils
 * Ben Myles and Vanessa McGaw
 * 2020-02-26
 * String functions to help deal with char* data type
 * */

#ifndef STRING_SEEN
#define STRING_SEEN

/**
 * Purpose: Convert an integer to a character array
 * Inputs: string of characters and integer to be converted
 * Outputs: string of characters holding representation of the integer which was passed as input
 * Called functions:
 * 		none
 * */
void int2str(char str[], int num) {
    int i, rem, len = 0, n;

    n = num;
    while (n != 0) {
        len++;
        n /= 10;
    }
    for (i = 0; i < len; i++) {
        rem = num % 10;
        num = num / 10;
        str[len - (i + 1)] = rem + '0';
    }
    str[len] = '\0';
}

/**
 * Purpose: clear a character array of all values
 * Inputs: character pointer to string, length of input string
 * Outputs: character pointer to empty string
 * Called functions:
 * 		none
 * */
void zeros(char* str, int length) {
	for (int i=0; i<length; i++) {
		str[i] = '\0';
	}
}

#endif
