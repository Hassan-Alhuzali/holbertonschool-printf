#include "main.h"

int _putchar(char c)
{
	return (write(1, &c, 1));
}

int print_string(char *str)
{
	int count;

	count = 0;
	if (!str)
		str = "(null)";
	while (*str)
		count += _putchar(*str++);
	return (count);
}
