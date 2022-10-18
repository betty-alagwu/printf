#include <unistd.h>
#include <stdarg.h>
#include "main.h"

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
