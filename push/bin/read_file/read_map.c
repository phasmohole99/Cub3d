#include "../../include/parsing.h"

void    set_directions (char **lines, t_map *m)
{
    int i;
    int j;

    i = 0;
    while (lines[i])
    {
        j = 0;
        if (lines[i][j] != '\n')
        {
            while (lines[i][j] == ' ' && lines[i][j])
                j++;
            if (lines[i][j] == 'N' && lines[i][j + 1] == 'O')
                m->no = ft_strdup_no_newlines(lines[i]);
            else if (lines[i][j] == 'S' && lines[i][j + 1] == 'O')
                m->so = ft_strdup_no_newlines(lines[i]);
            else if (lines[i][j] == 'W' && lines[i][j + 1] == 'E')
                m->we = ft_strdup_no_newlines(lines[i]);
            else if (lines[i][j] == 'E' && lines[i][j + 1] == 'A')
                m->ea = ft_strdup_no_newlines(lines[i]);
            else if (lines[i][j] == 'F' && lines[i][j + 1] == SPACE)
                m->f = ft_strdup_no_newlines(lines[i]);
            else if (lines[i][j] == 'C' && lines[i][j + 1] == SPACE)
                m->c = ft_strdup_no_newlines(lines[i]);
        }
        i++;
    }
}

void    filter_lines(char **lines, t_map *m)
{
    set_directions (lines, m);
    clean_directions (m);
    read_map_lines (lines, m);
}

void    read_file(int fd, t_map *m)
{
    char    **lines;
    char    *tmp;
    int     i;

    i = 0;
    tmp = NULL;
    lines = NULL;
    while (1)
    {
        tmp = get_next_line(fd);
        lines = realloc_2d(lines, tmp);
        if (!lines[i][0])
            break ;
        i++;
    }
    init_struct_pointers(m);
    filter_lines(lines, m);
    check_paths (m);
    check_rgbs (m);
    check_map (m);
    //convert_rgb_to_hex(m, m->f);
}
