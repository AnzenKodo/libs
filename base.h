/********************************************************************************
 * base.c: A header file that provides base functionality to C programs.
 * Code samples & inspiration taken from:
 *  - https://github.com/gingerBill/gb/blob/master/gb.h by Ginger Bill
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

#ifndef LIBS_BASE
#define LIBS_BASE

#define SYSCALL_EXIT 60
#define SYSCALL_WRITE 1

extern unsigned int _strlen(const char *str);

void base_print(const char *str) {
    asm (
        "syscall"
        :
        : "a"(SYSCALL_WRITE), "D"(1), "S"(str), "d"(_strlen(str))
        : "rcx", "r11", "memory"
    );
}

void base_println(const char *str) {
}

unsigned int base_rand(unsigned int Index) {
	Index = (Index << 13) ^ Index;
	return ((Index * (Index * Index * 15731 + 789221) + 1376312589) & 0x7fffffff);
}

unsigned int _strlen(const char *str)
{
    const char *start = str;

    while(*str!='\0')
    {
        str++;
    }

    return str - start;
}
#endif // LIBS_BASE
