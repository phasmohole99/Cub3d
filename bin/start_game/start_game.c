#include "../../include/parsing.h"

void    init_textures(t_data *data)
{
    char	*str;

	data->no = NULL;
	data->so = NULL;
	data->we = NULL;
	data->ea = NULL;
	str = ft_strtrim(data->map->no, "\n");
	data->no = mlx_load_png(str);
	free(str);
	str = ft_strtrim(data->map->so, "\n");
	data->so = mlx_load_png(str);
	free(str);
	str = ft_strtrim(data->map->ea, "\n");
	data->ea = mlx_load_png(str);
	free(str);
	str = ft_strtrim(data->map->we, "\n");
	data->we = mlx_load_png(str);
	free(str);
}

void    start_game_window(t_map *m, t_data *data)
{
    data->x = IW / 2;
    data->y = IH / 2;
    data->width = ft_strlen(m->map[0]);
    data->height = ft_2dlen(m->map);
    data->map = m;
    data->map_dub = m->map;
    //duplicate_map(m, data, data->width);
    init_textures(data);
    data->mlx = mlx_init(IH * data->height, IW * data->width, "CUB3D", 0);
	data->img = mlx_new_image(data->mlx, IW, IH); 
    mlx_loop_hook(data->mlx, &hook, data);
	// mlx_image_to_window(data->mlx, data->img, 0, 0);
	mlx_loop(data->mlx);
}
