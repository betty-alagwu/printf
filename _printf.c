#include <unistd.h>
#include <stdarg.h>

#include "main.h"

/**
 * _is_restricted_character - 'check if character is restricted'
 * @element: stores the restricted characters
 * Return: true or false
 */

int _is_restricted_character(char element)
{
return (element == 'c' || element == 'd'
|| element == 'i' || element == 's'
||
element == 'p' || element == 'b' || element == 'u'
|| element == 'o' ||
element == 'x' || element == 'X'
|| element == '%');
}

/**
 * _handle_format_cases - handle various print formats'
 * @format: takes in the input
 * @arguments: va arguments
 * Return: Number of characters printed
 */
int _handle_format_cases(va_list arguments, char format)
{
if (format == 'c')
{
_write_char(va_arg(arguments, int));

return (1);
}
if (format == 's')
{
int length_of_string = _write_string(arguments);
return (length_of_string);
}
if (format == 'd' || format == 'i')
{
int length_of_string = _write_integer(arguments);
return (length_of_string);
}
return (0);
}

/**
 * _printf - Custom printf - 'clone of printf std function'
 * @format: takes in the input
 * Return: Number of characters printed
 */

int _printf(const char *format, ...)
{
int i = 0;
int total_characters_printed = 0;
va_list arguments;
if (format == NULL) {
    return (-1);
}
va_start(arguments, format);
while (format[i] != '\0')
{
char current = format[i];
char next = format[i + 1];
char previous = format[i - 1];

if (current != '%' && previous == '%')
{
if (_is_restricted_character(current) == 0)
{
_write_char(current);
total_characters_printed++;
}
}
if (current == '%' && _is_restricted_character(next) == 0)
{
_write_char('%');
total_characters_printed++;
}
if (current != '%' && previous != '%')
{
_write_char(current);
total_characters_printed++;
}
if (current == '%')
{
total_characters_printed += _handle_format_cases(arguments, next);
}
i++;
}

va_end(arguments);
return (total_characters_printed);
}
