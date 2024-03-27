#include "../../include/parsing.h"

void    convert_rgb_to_hex(t_map *m, char *str)
{
    char    *tmp;
    int     start;
    int     num;
    int     i;
    int     j;

    i = 0;
    j = 0;
    m->f_hex = malloc(sizeof(char) * 8);
    if (!m->f_hex)
        quit_program (0, m);
    m->f_hex[0] = '#';
    while (j < 3)
    {
        start = i;
        while (str[i] != ',')
            i++;
        tmp = ft_substr(str, start, i - start);
        num = ft_atoi(tmp);
        free (tmp);
        //num = ft_convert_to_hex(num);
        tmp = ft_itoa(num);
        printf("#%s\n", tmp);
        m->f_hex = ft_strjoin(m->f_hex, tmp);
        free (tmp);
        i++;
        j++;
    }
}

int     check_ranges(char *str)
{
    char    *tmp;
    int     start;
    int     num;
    int     i;
    int     j;

    i = 0;
    j = 0;
    while (j < 3)
    {
        start = i;
        while (str[i] != ',' && str[i])
            i++;
        tmp = ft_substr(str, start, i - start);
        num = ft_atoi(tmp);
        if (num > 255 || num < 0)
        {
            free (tmp);
            return (-1);
        }
        free (tmp);
        i++;
        j++;
    }
    return (1);
}

int     count_commas(char *str)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (str[i])
    {
        if (str[i] == ',')
            count++;
        i++;
    }
    if (count != 2)
        return (-1);
    return (0);
}
