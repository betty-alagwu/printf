#include <stdio.h>
#include <unistd.h>
#include "main.h"

/**
 * _write_char - writes the character element to stdout
 * @element: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _write_char(char element) {
    write(1, &element, 1);

    return 0;
}
