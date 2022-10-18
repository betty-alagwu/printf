// Online C compiler to run C program online
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int _is_restricted_character(char element) {
  return element == 'c' || element == 'd' || element == 'i' || element == 's' ||
         element == 'p' || element == 'b' || element == 'u' || element == 'o' ||
         element == 'x' || element == 'X' || element == '%';
}

int _write_char(char element) {
  write(1, &element, 1);

  return 0;
}

// testing for string
int _write_string(va_list arguments) {
  char *str;
  int i = 0;

  str = va_arg(arguments, char *);

  for (; *str; str++) {
    _write_char(*str);
    i++;
  }
  return i;
}

// testing for i and d

int fun_integer(va_list arguments) {
  int i;
  int d;
  int length;
  unsigned int x;

  i = va_arg(arguments, int);
  d = 1;
  length = 0;

  if (i < 0) {
    length = length + _write_char('-');
    x = i * -1;
  } else {
    x = i;
  }

  while (x / d > 9)
    d = d * 10;

  while (d != 0) {
    length = length + _write_char('0' + x / d);
    x = x % d;
    d = d / 10;
  }
  return (length);
}

// printf function
int _printf(const char *format, ...) {
  int i = 0;
  int total_characters_printed = 0;
  va_list arguments;

  va_start(arguments, format);

  // Percent:[%%][%c]
  while (format[i] != '\0') {
    char current = format[i];
    char next = format[i + 1];
    char previous = format[i - 1];

    if (current == '%' && next == '%') {
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
        _write_char(va_arg(arguments, int));
        total_characters_printed++;
      }
    }

    if (current == '%') {
      if (next == 's') {
        int length_of_string = _write_string(arguments);

        total_characters_printed += length_of_string;
      }
    }
    if (current == '%' && next == 'i') {
      fun_integer(arguments);
    }
    if (current == '%' && next == 'd') {
      fun_integer(arguments);
    }

    i++;
  }

  va_end(arguments);

  return total_characters_printed;
}

int main() {
  int len = _printf("Let's try to printf a simple sentence.\n");
  int len2 = printf("Let's try to printf a simple sentence.\n");
  _printf("String:[%s]\n", "I am a string !");
  printf("String:[%s]\n", "I am a string !");
  _printf("%s", "this is a string\n");
  len = _printf("Percent:[%%]\n");
  len2 = printf("Percent:[%%]\n");
  _printf("Character:[%c]\n", 'H');
  printf("Character:[%c]\n", 'H');
  _printf("Length:[%d, %i]\n", len, len);
  printf("Length:[%d, %i]\n", len2, len2);
  _printf("Negative:[%d]\n", -762534);
  printf("Negative:[%d]\n", -762534);

  printf("My length is %d and printf length is %d", len, len2);

  return 0;
}
