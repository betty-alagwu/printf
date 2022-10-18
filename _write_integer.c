#include <stdarg.h>

/**
 * fun_integer - print integer and digit
 * @arguments: va_list
 * Return: int
 */
int write_integer(va_list arguments)
{
	int i, d, length;
	unsigned int x;

	i  = va_arg(arguments, int);
	d = 1;
	length = 0;

	if (i < 0)
	{
		length = length + _putchar('-');
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
		length = length + _putchar('0' + x / d);
		x = x % d;
		d = d / 10;
	}
	return (length);
}
