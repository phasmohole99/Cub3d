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
    char    *tmp;

    tmp = NULL;
    tmp = remove_spaces_id(m->no, m);
    m->no = ft_strdup(tmp);
    free (tmp);
    tmp = remove_spaces_id(m->so, m);
    m->so = ft_strdup(tmp);
    free (tmp);
    tmp = remove_spaces_id(m->we, m);
    m->we = ft_strdup(tmp);
    free (tmp);
    tmp = remove_spaces_id(m->ea, m);
    m->ea = ft_strdup(tmp);
    free (tmp);
    tmp = remove_spaces_id(m->f, m);
    m->f = ft_strdup(tmp);
    free (tmp);
    tmp = remove_spaces_id(m->c, m);
    m->c = ft_strdup(tmp);
    free (tmp);
}
