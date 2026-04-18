#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

extern char buffer[1024];
extern int buffer_index;

int _printf(const char *format, ...);
int _putchar(char c);
int _putchar_buffer(char c);
void flush_buffer(void);
int print_string(char *str);
int print_number(int n);
int print_unsigned(unsigned int n, char *digits, int base);
int print_binary(unsigned int n);

#endif /* MAIN_H */
