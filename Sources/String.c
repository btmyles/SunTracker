/* Sun Tracker string utils
 * Ben Myles and Vanessa McGaw
 * 2020-02-26
 * */

#ifndef STRING_SEEN
#define STRING_SEEN

//void int2str(int i, char* str, int length) {
//	char c;
//	int index = 0;
//	zeros(str, length);
//	while (i > 0) {
//		//convert each digit to its character counterpart
//		c = i%10 + '0';
//		str[index] = c;
//		i = i/10;
//	}
//}

void int2str(char str[], int num)
{
    int i, rem, len = 0, n;

    n = num;
    while (n != 0)
    {
        len++;
        n /= 10;
    }
    for (i = 0; i < len; i++)
    {
        rem = num % 10;
        num = num / 10;
        str[len - (i + 1)] = rem + '0';
    }
    str[len] = '\0';
}

void zeros(char* str, int length) {
	for (int i=0; i<length; i++) {
		str[i] = '\0';
	}
}

#endif
