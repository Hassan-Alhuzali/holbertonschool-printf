#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

#define FLAG_PLUS   (1 << 0)
#define FLAG_SPACE  (1 << 1)
#define FLAG_HASH   (1 << 2)

extern char buffer[1024];
extern int buffer_index;

int _printf(const char *format, ...);
int _putchar(char c);
int _putchar_buffer(char c);
void flush_buffer(void);
int print_string(char *str);
int print_string_nonprintable(char *str);
int print_number(int n, int flags);
int print_unsigned(unsigned int n, char *digits, int base, int flags);
int print_binary(unsigned int n, int flags);
int print_pointer(void *ptr);

#endif /* MAIN_H */
