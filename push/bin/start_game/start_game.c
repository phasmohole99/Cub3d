#include "../../include/parsing.h"

static int	check_wall(t_data *data, float xtmp, float ytmp)
{
	int	tile_s;

	tile_s = data->map_info.square_s;
	if (data->map_info.map_wt[(int)data->player._y / tile_s][(int)xtmp / tile_s] == '1'
		|| data->map_info.map_wt[(int)ytmp / tile_s][(int)data->player._x / tile_s] == '1'
		|| data->map_info.map_wt[(int)ytmp / tile_s]
		[(int)xtmp / tile_s] == '1' )
		return (0);
	return (1);
}

void	ft_move_up(t_data *data)
{
	data->x += cos(data->angle) * SPEED;
	data->y += sin(data->angle) * SPEED;
}

void	ft_move_down(t_data *data)
{
	data->x += cos(data->angle) * (SPEED * -1);
	data->y += sin(data->angle) * (SPEED * -1);
}

void	ft_move_left(t_data *data)
{
	data->x += cos(data->angle - M_PI / 2) * SPEED;
	data->y += sin(data->angle - M_PI / 2) * SPEED;
}

void	ft_move_right(t_data *data)
{
	data->x += cos(data->angle + M_PI / 2) * SPEED;
	data->y += sin(data->angle + M_PI / 2) * SPEED;
}


void draw_map(t_data *data) {
    int i = 0;
    while (i < data->height) {
        int j = 0;
        while (j < data->width) {
            int tileX = j * TILE_SIZE;
            int tileY = i * TILE_SIZE;
            int row = 0;
            while (row < TILE_SIZE) {
                int col = 0;
                while (col < TILE_SIZE) {
                    int pixelX = tileX + col;
                    int pixelY = tileY + row;

                    int color;
                    // printf("%c\n",data->map_dub[i][j]);
                    if (data->map_dub[i][j] == '1')
                        color = 0x88000FF;
                    else
                        color = 0x0000FF;

                    if (pixelX == tileX || pixelX == tileX + TILE_SIZE - 1 ||
                        pixelY == tileY || pixelY == tileY + TILE_SIZE - 1) {
                            color = 0x00000FF;
                    }

                    if(pixelY >= 0 && pixelY < IH && pixelX >= 0 && pixelX <  IW)
                    {
                        // printf("here [%d]\n",i);
                        mlx_put_pixel(data->img, pixelX, pixelY, color);
                    }

                    col++;
                }
                row++;
            }
            j++;
        }
        i++;
    }
}


void draw_player(t_data *data, int radius, int color) {
    int y = data->y - radius;
    while (y <= data->y + radius) {
        int x = data->x - radius;
        while (x <= data->x + radius) {
            if ((x - data->x) * (x - data->x) + (y - data->y) * (y - data->y) <= radius * radius) {
                if (x >= 0 && y >= 0 && x < IW && y < IH) {
                    mlx_put_pixel(data->img, x, y, color);
                }
            }
            x++;
        }
        y++;
    }
}

void draw_line(t_data *data, int playerX, int playerY, int length, double angle, int color) {
    int i = 0;
    while (i < length) {
        int x = playerX + i * cos(angle);
        int y = playerY + i * sin(angle);

        if (x >= 0 && y >= 0 && x < IW && y < IH) {
            mlx_put_pixel(data->img, x, y, color);
        }

        i++;
    }

    int endX = playerX + length * cos(angle);
    int endY = playerY + length * sin(angle);

    if (endX >= 0 && endY >= 0 && endX < IW && endY < IH) {
        mlx_put_pixel(data->img, endX, endY, color);
    }
}

double	angle_adjast(double angle, char sign)
{
	if (angle <= 0)
		angle += M_PI * 2;
	if (sign == '-')
		angle -= M_PI / 180;
	if (sign == '+')
		angle += M_PI / 180;
	if (angle > M_PI * 2)
		angle -= M_PI * 2;
	return (angle);
}

void	setup_angle(float *angle)
{
	*angle = remainder(*angle, 2 * M_PI);
	if (*angle < 0)
		*angle = (2 * M_PI) + *angle;
}

void hook(void *param)
{
    t_data *mlx = (t_data *)param;
    mlx_key_data_t data;
    int Color = 0x808080FF;
    
    mlx_delete_image(mlx->mlx,mlx->img);
    mlx->img = mlx_new_image(mlx->mlx,IW,IH);
    if(mlx_is_key_down(mlx->mlx,MLX_KEY_A))
        mlx->angle += 0.1;
    else if (mlx_is_key_down(mlx->mlx,MLX_KEY_D))
        mlx->angle -= 0.1;
    setup_angle(&mlx->angle);
    printf("%f\n ",mlx->angle);

    if (mlx_is_key_down(mlx->mlx, MLX_KEY_ESCAPE))
        exit(1);
    else if (mlx_is_key_down(mlx->mlx, MLX_KEY_UP))
        ft_move_up(mlx);
    else if (mlx_is_key_down(mlx->mlx, MLX_KEY_DOWN))
        ft_move_down(mlx);
    else if (mlx_is_key_down(mlx->mlx, MLX_KEY_RIGHT))
        ft_move_right(mlx);
    else if (mlx_is_key_down(mlx->mlx, MLX_KEY_LEFT))
        ft_move_left(mlx);
    draw_map(mlx);
    draw_player(mlx, 8, Color);
    draw_line(mlx,mlx->x,mlx->y,50,mlx->angle,Color);
    mlx_image_to_window(mlx->mlx,mlx->img,0,0);
}

double	init_angle(t_map *map)
{   
    // printf("am here\n");
    // exit(1);
	if (map->no[0] == 'N')
		return (3 * M_PI / 2);
	else if (map->so[0] == 'S')
		return (M_PI_2);
	else if (map->we[0] == 'W')
		return (M_PI);
	else if (map->ea[0] == 'E')
		return (0);
	return (0);
}

void    start_game_window(t_map *m, t_data *data)
{
    int w; // IW
    data->x = IW / 2;
    data->y = IH / 2;
    w = ft_strlen(m->map[0]);
        data->map_dub = (char**) malloc(sizeof(char *) * (data->height + 1));
    int i = 0;
    int j = 0; 
	data->mlx = mlx_init(IW , IH, "CUB3D", false);
    while (m->map[i])
    {
        j = 0;
        data->map_dub[i] = malloc(sizeof(char) * w + 1);
        while (m->map[i][j])
        {
            data->map_dub[i][j] = m->map[i][j];
            j++;
        }
        data->map_dub[i][j] = 0;
        i++;
    }
    data->map_dub[i] = 0;
    data->width = w;
    data->height = ft_2dlen(m->map);
    // i = 0;
    // while (data->map_dub[i])
    // {
    //     printf("%s\n", data->map_dub[i]);
    //     i++;
    // }
	// mlx_texture_t *no_texture = mlx_load_png(m->no);
	// data->img = mlx_texture_to_image(data->mlx, no_texture);
	data->img = mlx_new_image(data->mlx, IW, IH);
	// // if (!m->mlx_ptr)
	// // 	quit_program (WINDOW_ERROR, m);
	// //mlx_image_to_window(data->mlx, image, 1, 1);
	// draw_elements (m);

    data->angle = init_angle(m);
	mlx_loop_hook(data->mlx, &hook, data);
	mlx_image_to_window(data->mlx, data->img, 0, 0);
	mlx_loop(data->mlx);
}
