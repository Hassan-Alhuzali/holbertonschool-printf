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

int print_number(int n)
{
	int count;
	unsigned int num;

	count = 0;
	if (n < 0)
	{
		count += _putchar('-');
		num = -n;
	}
	else
		num = n;
	if (num / 10)
		count += print_number(num / 10);
	count += _putchar((num % 10) + '0');
	return (count);
}

int print_unsigned(unsigned int n, char *digits, int base)
{
	int count;

	count = 0;
	if (n == 0)
		return (_putchar('0'));
	if (n / base)
		count += print_unsigned(n / base, digits, base);
	count += _putchar(digits[n % base]);
	return (count);
}

int print_binary(unsigned int n)
{
	int count;

	count = 0;
	if (n == 0)
		return (_putchar('0'));
	if (n / 2)
		count += print_binary(n / 2);
	count += _putchar((n % 2) + '0');
	return (count);
}
