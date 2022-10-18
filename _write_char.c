#include <unistd.h>

int _write_char(char element)
{
write(1, &element, 1);

return (0);
}
