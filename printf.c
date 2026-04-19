#include "main.h"

int _printf(const char *format, ...) {
  va_list args;
  int count;
  int flags;
  int length_mod;

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

      length_mod = 0;
      if (*format == 'h') {
        length_mod |= LENGTH_H;
        format++;
      } else if (*format == 'l') {
        length_mod |= LENGTH_L;
        format++;
      }

      if (*format == 'c')
        count += _putchar_buffer(va_arg(args, int));
      else if (*format == 's')
        count += print_string(va_arg(args, char *));
      else if (*format == 'S')
        count += print_string_nonprintable(va_arg(args, char *));
      else if (*format == 'd' || *format == 'i') {
        if (length_mod & LENGTH_L)
          count += print_number_long(va_arg(args, long), flags);
        else if (length_mod & LENGTH_H)
          count += print_number_short((short)va_arg(args, int), flags);
        else
          count += print_number(va_arg(args, int), flags);
      } else if (*format == 'u') {
        if (length_mod & LENGTH_L)
          count += print_unsigned_long(va_arg(args, unsigned long),
                                       "0123456789", 10, flags);
        else if (length_mod & LENGTH_H)
          count +=
              print_unsigned_short((unsigned short)va_arg(args, unsigned int),
                                   "0123456789", 10, flags);
        else
          count += print_unsigned(va_arg(args, unsigned int), "0123456789", 10,
                                  flags);
      } else if (*format == 'o') {
        if (length_mod & LENGTH_L)
          count += print_unsigned_long(va_arg(args, unsigned long), "01234567",
                                       8, flags);
        else if (length_mod & LENGTH_H)
          count += print_unsigned_short(
              (unsigned short)va_arg(args, unsigned int), "01234567", 8, flags);
        else
          count +=
              print_unsigned(va_arg(args, unsigned int), "01234567", 8, flags);
      } else if (*format == 'x') {
        if (length_mod & LENGTH_L)
          count += print_unsigned_long(va_arg(args, unsigned long),
                                       "0123456789abcdef", 16, flags);
        else if (length_mod & LENGTH_H)
          count +=
              print_unsigned_short((unsigned short)va_arg(args, unsigned int),
                                   "0123456789abcdef", 16, flags);
        else
          count += print_unsigned(va_arg(args, unsigned int),
                                  "0123456789abcdef", 16, flags);
      } else if (*format == 'X') {
        if (length_mod & LENGTH_L)
          count += print_unsigned_long(va_arg(args, unsigned long),
                                       "0123456789ABCDEF", 16, flags);
        else if (length_mod & LENGTH_H)
          count +=
              print_unsigned_short((unsigned short)va_arg(args, unsigned int),
                                   "0123456789ABCDEF", 16, flags);
        else
          count += print_unsigned(va_arg(args, unsigned int),
                                  "0123456789ABCDEF", 16, flags);
      } else if (*format == 'p')
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
