#include "../../include/parsing.h"

void	ft_draw(mlx_image_t *image)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < IH)
	{
		x = 0;
		while (x < IW)
		{
			mlx_put_pixel(image, x, y, 0x00000000);
			x++;
		}
		y++;
	}
}

void    ft_draw_map(t_data *data)
{
    int x;
    int y;

    y = 0;
    while (data->map_dub[y] != NULL)
    {
        x = 0;
        while (data->map_dub[y][x] != NULL)
        {
            
        }
    }
}

void    draw_game(t_data *data)
{
    ft_draw_map(data);
}