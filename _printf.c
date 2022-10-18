#include <unistd.h>
#include <stdarg.h>

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

int _write_char(char element)
{
write(1, &element, 1);

return (0);
}

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
if (next == 'c')
{
_write_char(va_arg(arguments, int));
total_characters_printed++;
}
}
if (current == '%')
{
if (next == 's')
{
int length_of_string = _write_string(arguments);

total_characters_printed += length_of_string;
}
}
if (current == '%' && next == 'i')
{
_write_integer(arguments);
}
if (current == '%' && next == 'd')
{
_write_integer(arguments);
}
i++;
}
va_end(arguments);
return (total_characters_printed);
}
