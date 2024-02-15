#include "../../include/parsing.h"

int     get_map_start_line(char **lines)
{
    int i;
    int j;

    i = 0;
    while (lines[i])
    {
        j = 0;
        while (lines[i][j] == SPACE && lines[i][j])
            j++;
        if (lines[i][j] == '0' || lines[i][j] == '1')
            return (i);
        i++;
    }
    return (-1);
}

void    set_lines_to_map(int s, char **lines, t_map *m)
{
    int     i;
    char    *tmp;

    i = 0;
    tmp = 0;
    while (lines[s])
    {
        if (lines[s][0] == '0' || lines[s][0] == '1')
        {
            tmp = remove_char(lines[s], SPACE);
            m->map = realloc_2d(m->map, tmp);
        }
        s++;
    }
}

void    read_map_lines(char **lines, t_map *m)
{
    int     s; // start map position

    s = get_map_start_line(lines);
    if (s == -1)
        quit_program (MISSING_MAP, m);
    set_lines_to_map (s, lines, m);
    /*    here we finished from lines variable do not forget to free it */
    check_map (m);
    // int i = 0;
    // while (m->map[i])
    // {
    //     printf("%s\n", m->map[i]);
    //     i++;
    // }
}