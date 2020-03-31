/* Sun Tracker string utils
 * Ben Myles and Vanessa McGaw
 * 2020-02-26
 * String functions to help deal with char* data type
 * */

#ifndef STRING_SEEN
#define STRING_SEEN

// Convert an integer to a character array
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

// Clear a character array of all values
void zeros(char* str, int length) {
	for (int i=0; i<length; i++) {
		str[i] = '\0';
	}
}

#endif
