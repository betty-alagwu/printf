<<<<<<< HEAD
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
if (format == NULL)
{
return (-1);
}
va_start(arguments, format);
while (format[i] != '\0')
{
char current = format[i];
char next = format[i + 1];
char previous = format[i - 1];
if (current != '%' && previous == '%'
&& _is_restricted_character(current) == 0)
{
_write_char(current);
total_characters_printed++;
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
=======
#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = _print_formatted_output(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
>>>>>>> f9e7ca3bdb5c6ce1e5b49631c1839dd840ba7efc
}
