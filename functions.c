#include "main.h"

char buffer[1024];
int buffer_index;

int _putchar(char c)
{
	return (write(1, &c, 1));
}

int _putchar_buffer(char c)
{
	buffer[buffer_index++] = c;
	if (buffer_index == 1024)
	{
		write(1, buffer, buffer_index);
		buffer_index = 0;
	}
	return (1);
}

void flush_buffer(void)
{
	if (buffer_index > 0)
	{
		write(1, buffer, buffer_index);
		buffer_index = 0;
	}
}

int print_string(char *str)
{
	int count;

	count = 0;
	if (!str)
		str = "(null)";
	while (*str)
		count += _putchar_buffer(*str++);
	return (count);
}

int print_number(int n)
{
	int count;
	unsigned int num;

	count = 0;
	if (n < 0)
	{
		count += _putchar_buffer('-');
		num = -n;
	}
	else
		num = n;
	if (num / 10)
		count += print_number(num / 10);
	count += _putchar_buffer((num % 10) + '0');
	return (count);
}

int print_unsigned(unsigned int n, char *digits, int base)
{
	int count;

	count = 0;
	if (n == 0)
		return (_putchar_buffer('0'));
	if (n / base)
		count += print_unsigned(n / base, digits, base);
	count += _putchar_buffer(digits[n % base]);
	return (count);
}

int print_binary(unsigned int n)
{
	int count;

	count = 0;
	if (n == 0)
		return (_putchar_buffer('0'));
	if (n / 2)
		count += print_binary(n / 2);
	count += _putchar_buffer((n % 2) + '0');
	return (count);
}
