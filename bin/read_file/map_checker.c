#include "../../include/parsing.h"

void    check_lines_width(t_map *m)
{
    int i;

    i = 0;
    while (m->map[i])
    {
        if (ft_strlen(m->map[i]) != m->width)
        {
            printf ("--> %zu on %d\n", ft_strlen(m->map[i]), i);
            quit_program (INVALID_MAP, m);
        }
        i++;
    }
}

void    check_walls(t_map *m)
{
    int i;
    int j;

    j = -1;
    i = 1;
    while (m->map[0][++j])
        if (!is_wall(m->map[0][j]))
            quit_program (INVALID_MAP, m);
    while (m->map[i])
    {
        if (m->map[i][ft_strlen(m->map[i]) - 1] != WALL
            || m->map[i][0] != WALL)
            quit_program (INVALID_MAP, m);
        i++;
    }
    j = -1;
    while (m->map[ft_2dlen(m->map) - 1][++j])
        if (!is_wall(m->map[0][j]))
            quit_program (INVALID_MAP, m);
}

void    check_elements(t_map *m)
{
    int i;
    int j;

    i = -1;
    while (m->map[++i])
    {
        j = -1;
        while (m->map[i][++j])
        {
            if (m->map[i][j] != '1' && m->map[i][j] != '0'
                && m->map[i][j] != 'N' && m->map[i][j] != 'S'
                && m->map[i][j] != 'W' && m->map[i][j] != 'E')
                quit_program (INVALID_MAP, m);
        }
    }
}

void    check_map (t_map *m)
{
    m->width = ft_strlen(m->map[0]);
    check_lines_width(m);
    check_walls(m);
    check_elements(m);
    printf("IT's a valid map\n");
}