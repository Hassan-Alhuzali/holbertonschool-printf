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
int print_number_recursive(int n);
int print_number(va_list args) /* Changed: takes va_list */
{
  int n = va_arg(args, int); /* Get the number from args */
  int count;
  unsigned int num;

  count = 0;
  if (n < 0) {
    count += _putchar('-');
    num = -n;
  } else
    num = n;
  /* Recursively print each digit */
  if (num / 10)
    count += print_number_recursive(num / 10);
  count += _putchar((num % 10) + '0');
  return (count);
}
/* Helper function for recursion */
int print_number_recursive(int n)
{
	int count = 0;

	if (n/ 10)
          count += print_number_recursive(n / 10);
        count += _putchar((n % 10) + '0');
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
