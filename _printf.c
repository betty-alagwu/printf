#include <unistd.h>
#include <stdarg.h>

#include "main.h"

/**
 * _is_restricted_character: 
 *
 * Description: 'check if character is restricted'
 *
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
 * _write_integer
 *
 * Description: 'handle writing an integer'
 *
 * Return: Number of characters printed
 */

int _write_integer(va_list arguments)
{
int i;
int d;
int length;
unsigned int x;

i = va_arg(arguments, int);
d = 1;
length = 0;

if (i < 0)
{
length = length + _write_char('-');
x = i * -1;
}
else
{
x = i;
}

while (x / d > 9)
d = d * 10;

while (d != 0)
{
length = length + _write_char('0' + x / d);
x = x % d;
d = d / 10;
}
return (length);
}
/**
 * _handle_format_cases
 *
 * Description: 'handle various print formats'
 *
 * Return: Number of characters printed
 */

int _handle_format_cases(va_list arguments, char format)
{
if (format == 'c')
{
_write_char(va_arg(arguments, int));
}
if (format == 's')
{
int length_of_string = _write_string(arguments);
return (length_of_string);
}
return (1);
}

/**
 * _printf - Custom printf
 *
 * Description: 'clone of printf std function'
 *
 * Return: Number of characters printed
 */

int _printf(const char *format, ...)
{
int i = 0;
int total_characters_printed = 0;
va_list arguments;
va_start(arguments, format);
while (format[i] != '\0')
{
char current = format[i];
char next = format[i + 1];
char previous = format[i - 1];
if (current == '%' && next == '%')
{
_write_char('%');
total_characters_printed++;
}
if (current != '%' && previous == '%')
{
if (_is_restricted_character(current) == 0)
{
_write_char(current);
total_characters_printed++;
}
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
