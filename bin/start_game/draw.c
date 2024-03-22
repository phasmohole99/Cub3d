#include "../../include/parsing.h"

// void	ft_draw(mlx_image_t *image)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	y = 0;
// 	while (y < IH)
// 	{
// 		x = 0;
// 		while (x < IW)
// 		{
// 			mlx_put_pixel(image, x, y, 0x00000000);
// 			x++;
// 		}
// 		y++;
// 	}
// }

int	ft_pxl(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	draw_sky_ground(t_data *data)
{
	int	color;
	int	i;

	i = 0;
	color = 0;
	while (color < (data->height * IH) / 2)
	{
		i = 0;
		while (i <= data->width * IW)
		{
			mlx_put_pixel(data->img, i++, color, ft_pxl(data->map->s_r, data->map->s_g, data->map->s_b,
					255));
		}
		color++;
	}
	while (color < (data->height * IH))
	{
		i = 0;
		while (i <= data->width * IW)
		{
			mlx_put_pixel(data->img, i++, color, ft_pxl(data->map->g_r, data->map->g_g,
					data->map->g_b, 255));
		}
		color++;
	}
}

// void	ft_draw(t_data *data)
// {
// 	return ;
// }

void    draw_game(t_data *data)
{
	// float	ray_nb;

// C 34, 112, 147
// F 255, 160, 22
	// ray_nb = 10;
	data->map->s_r = 34;
	data->map->s_g = 112;
	data->map->s_b = 147;
	data->map->g_r = 255;
	data->map->g_g = 160;
	data->map->g_b = 22;
	draw_sky_ground(data);
    //ft_draw_wall(data, ray_nb);
}