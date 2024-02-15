#include "../../include/parsing.h"

void    quit_program(int errid, t_map *m)
{
    if (errid == MISSING_IDENTIFIER)
        perror ("Error\n:Missing identifier please fix .cub file\n");
    if (errid == MISSING_MAP)
        perror ("Error\n:Missing Map elements please fix .cub file\n");
    if (errid == INVALID_MAP)
        perror ("Error\n:Invalid Map please fix .cub file\n");
    exit (EXIT_FAILURE);
}