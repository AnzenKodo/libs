/********************************************************************************
 * str.c: A header file that provides string manipulation function to C programs.
 * Code samples & inspiration taken from:
 *  - https://github.com/gingerBill/gb/blob/master/gb.h by Ginger Bill
 *  - https://github.com/gingerBill/gb/blob/master/gb_string.h by Ginger Bill
 *  - https://github.com/ennorehling/clibs/blob/master/strings.c by Enno Rehling
 * -----------------------------------------------------------------------------
 * MIT License
 *
 * Copyright 2024 AnzenKodo
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
********************************************************************************/


#ifndef LIBS_STR
#define LIBS_STR

#include <assert.h>
#include <stdbool.h>

int str_cmp(char const *s1, char const *s2) {
	while (*s1 && (*s1 == *s2)) {
		s1++, s2++;
	}
	return *(unsigned char *)s1 - *(unsigned char *)s2;
}

char *str_cpy(char *dest, char const *source) {
	assert(dest);
	if (source) {
		char *str = dest;
		while (*source) *str++ = *source++;
	}
	return dest;
}

unsigned int str_len(const char *str)
{
    unsigned int i = 0;
    const char *start = str;

    while(*str!='\0')
    {
        i++;
        str++;
    }

    return str - start;
}

char str_only_digit(char *str) {
    while (str)
    {
        if ((*str >= '0' && *str <= '9'))
            return false;
       str++;
    }
    return true;
}

unsigned int str_atoi(char *str) {
    assert(str_only_digit(str));

    int k = 0;
    while (*str) {
        k = (k << 3) + (k << 1) + (*str) - '0';
        str++;
     }
     return k;
}

#endif // LIBS_STR
