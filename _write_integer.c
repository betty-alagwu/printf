#include <stdarg.h>
#include "main.h"

/**
 * _write_integer - entry point - 'handle writing an integer'
 * @arguments: takes in the argument
 * Return: Number of characters printed
 */
int _write_integer(va_list arguments)
{
	int i, d, length;
	unsigned int x;

	i  = va_arg(arguments, int);
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
