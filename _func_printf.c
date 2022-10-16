#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _write_string - print string
 * @arguments: va_list
 *
 * Return: string
 */
int _write_string(va_list arguments)
{
	char *str;
	int i = 0;

	str = va_arg(arguments, char *);

	for (; *str; str++)
	{
		_write_char(*str);
		i++;
	}
	return (i);
}

/**
 * fun_integer - print integer and digit
 * @arguments: va_list
 *
 * Return: int
 */
int fun_integer(va_list arguments)
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
 * _is_restricted_character - selects the restricted charecters
 * @element: the character being written
 * return:  0
 */
int _is_restricted_character(char element)
{
	return
		(element == 'c' || element == 'd' || element == 'i' || element == 's' ||
		element == 'p' || element == 'b' || element == 'u' || element == 'o' ||
		element == 'x' || element == 'X' || element == '%');
	return (0);
}

