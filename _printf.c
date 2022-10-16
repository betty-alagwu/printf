#include <stdlib.h>
#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
/**
 * _printf - recreates the printf function
 * @format: string with format specifier
 * Return: number of characters printed
 */
int _printf(const char *format, ...) {
    int i = 0;
	int total_characters_printed = 0;
    va_list arguments;

    va_start(arguments, format);

    while (format[i] != '\0') {
        char current = format[i];
        char next = format[i + 1];
        char previous = format [i - 1];

        if(current == '%' && next == '%' ){
          _write_char('%');
			total_characters_printed++;
        }

		if (current != '%' && previous == '%') {
			if (_is_restricted_character(current) == 0) {
				_write_char(current);
				total_characters_printed++;
			}
		}


        if (current != '%' && previous != '%') {
            _write_char(current);
			total_characters_printed++;
        }

        if (current == '%') {
            if (next == 'c') {
                _write_char(
                    va_arg(arguments, int)
                );
				total_characters_printed++;
            }
        }
      
        if (current == '%'){
          if (next == 's'){
            int length_of_string = _write_string(arguments);

			  total_characters_printed += length_of_string;
          }
        }

        i++;
    }

    va_end(arguments);

    return total_characters_printed;
}
