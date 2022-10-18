#include <unistd.h>

/**
 * _write_char
 *
 * Description: 'write a single character'
 *
 * Return: 0 for success
 */

int _write_char(char element)
{
write(1, &element, 1);

return (0);
}
