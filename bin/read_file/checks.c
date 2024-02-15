#include "../../include/parsing.h"

char    *remove_spaces_id(char *str, t_map *m)
{
    int     i;
    char    *res;

    i = 2;
    if (!str)
        quit_program (MISSING_IDENTIFIER, m);
    while (str[i] == SPACE && str[i])
        i++;
    res = ft_substr(str, i, ft_strlen_from(str, i));
    free (str);
    str = 0;
    if (res[0] == '\0')
        quit_program (MISSING_IDENTIFIER, m);
    return (res);
}

void    clean_directions(t_map *m)
{
    m->no = remove_spaces_id(m->no, m);
    m->so = remove_spaces_id(m->so, m);
    m->we = remove_spaces_id(m->we, m);
    m->ea = remove_spaces_id(m->ea, m);
    m->f = remove_spaces_id(m->f, m);
    m->c = remove_spaces_id(m->c, m);
}