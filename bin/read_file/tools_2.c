#include "../../include/parsing.h"


int     is_wall(char c)
{
    return (c == WALL);
}

char    *remove_char(char *str, char c)
{
    int     i;
    int     j;
    char    *res;

    i = 0;
    j = 0;
    while (str[i] && str[i] == SPACE)
        i++;
    res = malloc((ft_strlen_without(str, i, c) + 1) * sizeof(char*));
    while (str[i] && str[i] != '\n')
    {
        if (str[i] != c)
        {
            res[j] = str[i];
            j++;
        }
        i++;
    }
    free (str);
    res[j] = 0;
    return (res);
}
size_t  ft_strlen_without(const char *str, int pos, char exc)
{
    size_t len;

    len = 0;
    while (str[pos])
    {
        if (str[pos] != exc && str[pos] != '\n')
            len++;
        pos++;
    }
    return (len);
}


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
