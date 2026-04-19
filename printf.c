#include "main.h"

int _printf(const char *format, ...) {
  va_list args;
  int count;
  int flags;

  count = 0;
  buffer_index = 0;
  if (!format)
    return (-1);
  va_start(args, format);
  while (*format) {
    if (*format == '%') {
      format++;
      if (*format == '\0') {
        flush_buffer();
        return (-1);
      }

      flags = 0;
      while (*format == '+' || *format == ' ' || *format == '#') {
        if (*format == '+')
          flags |= FLAG_PLUS;
        else if (*format == ' ')
          flags |= FLAG_SPACE;
        else if (*format == '#')
          flags |= FLAG_HASH;
        format++;
      }

      if (*format == 'c')
        count += _putchar_buffer(va_arg(args, int));
      else if (*format == 's')
        count += print_string(va_arg(args, char *));
      else if (*format == 'S')
        count += print_string_nonprintable(va_arg(args, char *));
      else if (*format == 'd' || *format == 'i')
        count += print_number(va_arg(args, int), flags);
      else if (*format == 'u')
        count +=
            print_unsigned(va_arg(args, unsigned int), "0123456789", 10, flags);
      else if (*format == 'o')
        count +=
            print_unsigned(va_arg(args, unsigned int), "01234567", 8, flags);
      else if (*format == 'x')
        count += print_unsigned(va_arg(args, unsigned int), "0123456789abcdef",
                                16, flags);
      else if (*format == 'X')
        count += print_unsigned(va_arg(args, unsigned int), "0123456789ABCDEF",
                                16, flags);
      else if (*format == 'p')
        count += print_pointer(va_arg(args, void *));
      else if (*format == 'b')
        count += print_binary(va_arg(args, unsigned int), flags);
      else if (*format == '%')
        count += _putchar_buffer('%');
      else {
        count += _putchar_buffer('%');
        count += _putchar_buffer(*format);
      }
    } else
      count += _putchar_buffer(*format);
    format++;
  }
  va_end(args);
  flush_buffer();
  return (count);
}
