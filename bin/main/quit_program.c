#include "../../include/parsing.h"

void    quit_program(int errid, t_map *m)
{
    if (errid == MISSING_IDENTIFIER)
        perror ("Error\n:Missing identifier please fix .cub file\n");
    exit (EXIT_FAILURE);
}