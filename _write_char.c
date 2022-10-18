#include <unistd.h>

/**
 * _write_char - write a char to stdout
 * @element: character to print
 * Return: 0 for success
 */

int _write_char(char element)
{
write(1, &element, 1);

return (0);
}
