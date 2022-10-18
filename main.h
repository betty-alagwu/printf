
#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

int _printf(const char *format, ...);
int _write_string(va_list arguments);
int _write_char(char element);
int _write_integer(va_list arguments);

#endif
