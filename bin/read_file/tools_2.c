#include "../../include/parsing.h"

size_t  ft_strlen_from(const char *str, int pos)
{
    size_t len;

    len = 0;
    while (str[pos] && str[pos] != SPACE)
    {
        len++;
        pos++;
    }
    return (len);
}
