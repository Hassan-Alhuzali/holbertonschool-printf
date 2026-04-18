#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int _putchar(char c);
int print_string(char *str);
int print_number(va_list args); /* Changed: now takes va_list */
int print_binary(unsigned int n);

#endif /* MAIN_H */
