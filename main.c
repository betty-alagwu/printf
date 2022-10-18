// Online C compiler to run C program online
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "main.h"

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
