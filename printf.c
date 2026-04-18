#include "main.h"

static char buffer[1024];
static int buffer_index;

void flush_buffer(void)
{
	if (buffer_index > 0)
	{
		write(1, buffer, buffer_index);
		buffer_index = 0;
	}
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

int _printf(const char *format, ...)
{
	va_list args;
	int count;

	count = 0;
	buffer_index = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
			{
				flush_buffer();
				return (-1);
			}
			if (*format == 'c')
				count += _putchar_buffer(va_arg(args, int));
			else if (*format == 's')
				count += print_string(va_arg(args, char *));
			else if (*format == 'd' || *format == 'i')
				count += print_number(va_arg(args, int));
			else if (*format == 'u')
				count += print_unsigned(va_arg(args,
				unsigned int), "0123456789", 10);
			else if (*format == 'o')
				count += print_unsigned(va_arg(args,
				unsigned int), "01234567", 8);
			else if (*format == 'x')
				count += print_unsigned(va_arg(args,
				unsigned int), "0123456789abcdef", 16);
			else if (*format == 'X')
				count += print_unsigned(va_arg(args,
				unsigned int), "0123456789ABCDEF", 16);
			else if (*format == 'b')
				count += print_binary(va_arg(args, unsigned int));
			else if (*format == '%')
				count += _putchar_buffer('%');
			else
			{
				count += _putchar_buffer('%');
				count += _putchar_buffer(*format);
			}
		}
		else
			count += _putchar_buffer(*format);
		format++;
	}
	va_end(args);
	flush_buffer();
	return (count);
}
