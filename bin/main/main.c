#include "../../include/parsing.h"

int check_cub_file(char *file)
{
    int i;

    i = ft_strlen(file);
    if (file[i - 1] != 'b' || file[i - 2] != 'u'
    || file[i - 3] != 'c' || file[i - 4] != '.')
    {
        perror ("Error\nInvalid map file\n");
        exit (EXIT_FAILURE);
        return (0);
    }
    return (1);
}

int main(int ac, char **av)
{
    t_map   m;
    t_data  data;

    if (ac == 2)
    {
        check_cub_file(av[1]);
        read_file (open(av[1], 2), &m);
        //start_game_window (&m);
        data.mlx = mlx_init(IW, IH, "CUB3D", 0);
        data.img= mlx_new_image(data.mlx, IW, IH);
        mlx_loop(data.mlx);
    }
    init_struct_pointers(&m);
    quit_program (SUCCESS, &m);
}