#include "../../include/parsing.h"

void    init_struct_pointers(t_map *m)
{
    m->ea = NULL;
    m->we = NULL;
    m->no = NULL;
    m->so = NULL;
    m->map = NULL;
    m->mlx_ptr = NULL;
    m->mlx_win = NULL;
}

void	free_2darr(char **tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return ;
	while (tab[i])
	{
		if (tab[i])
			free (tab[i]);
		tab[i] = NULL;
		i++;
	}
	if (tab)
		free (tab);
	tab = NULL;
}

void    free_struct_pointers (t_map *m)
{
    if (m->no)
        free (m->no);
    if (m->so)
        free (m->so);
    if (m->we)
        free (m->we);
    if (m->ea)
        free (m->ea);
    if (m->map)
        free_2darr(m->map);
}

void    quit_program(int errid, t_map *m)
{
    free_struct_pointers(m);
    if (errid == MISSING_IDENTIFIER)
        perror ("Error\n:Missing identifier please fix .cub file\n");
    if (errid == MISSING_MAP)
        perror ("Error\n:Missing Map elements please fix .cub file\n");
    if (errid == INVALID_MAP)
        perror ("Error\n:Invalid Map please fix .cub file\n");
    if (errid == WINDOW_ERROR)
        perror ("Error\n:Unable to intialze window\n");
    if (errid == SUCCESS)
    {
            printf("PP\n");
            pause();
            exit (EXIT_SUCCESS);
    }
    pause ();
    exit (EXIT_FAILURE);
}
