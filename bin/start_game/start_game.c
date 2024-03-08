#include "../../include/parsing.h"

void updatePlayerPosition(t_data *data,int deltaX, int deltaY) {
    // int deltaX = SPEED + cos(dir);
    // int deltaY = SPEED + sin(dir);
    data->x += deltaX;
    data->y += deltaY;
}

void draw_map(t_data *data) {
    int i = 0;
    // printf("WW---_>----------------QQ");
    // exit(1);
    while (i < data->map->height) {
        int j = 0;
        while (j < data->map->width) {
            int tileX = j * TILE_SIZE;
            int tileY = i * TILE_SIZE;
            int row = 0;
            while (row < TILE_SIZE) {
                int col = 0;
                while (col < TILE_SIZE) {
                    int pixelX = tileX + col;
                    int pixelY = tileY + row;

                    int color;
                    if (data->map->map[i][j] == 1)
                        color = 0x00FF00FF;
                    else
                        color = 0x0F00FFFF;

                    if (pixelX == tileX || pixelX == tileX + TILE_SIZE - 1 ||
                        pixelY == tileY || pixelY == tileY + TILE_SIZE - 1) {
                        if (data->map->map[i][j] == 1 || data->map->map[i][j] == 0)
                            color = 0x000000FF;
                    }
                    if(pixelY >= 0 && pixelY < IH && pixelX >= 0 && pixelX <  IW)
                        mlx_put_pixel(data->img, pixelX, pixelY, color);
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

void hook(void *param)
{
    t_data *mlx = (t_data *)param;
    mlx_key_data_t data;
    int Color = 0x808080FF; 
    mlx_delete_image(mlx->mlx,mlx->img);
    mlx->img = mlx_new_image(mlx->mlx,IW,IH);

    if(mlx_is_key_down(mlx->mlx,MLX_KEY_A))
        mlx->angle -= 0.1;
    else if (mlx_is_key_down(mlx->mlx,MLX_KEY_D))
    {
        // printf("here\n");
        mlx->angle += 0.1;
    }

    if (mlx_is_key_down(mlx->mlx, MLX_KEY_ESCAPE))
        exit(1);
    else if (mlx_is_key_down(mlx->mlx, MLX_KEY_UP))
        updatePlayerPosition(mlx, 0,1); 
    else if (mlx_is_key_down(mlx->mlx, MLX_KEY_DOWN))
        updatePlayerPosition(mlx, 0,-1);
    else if (mlx_is_key_down(mlx->mlx, MLX_KEY_RIGHT))
        updatePlayerPosition(mlx, 1,0); 
    else if (mlx_is_key_down(mlx->mlx, MLX_KEY_LEFT))
        updatePlayerPosition(mlx, -1,0); 

    draw_map(mlx);
    draw_player(mlx, 8, Color);
    draw_line(mlx,mlx->x,mlx->y,50,mlx->angle,Color);
    mlx_image_to_window(mlx->mlx,mlx->img,0,0);
}


void    start_game_window(t_map *m, t_data *data)
{
    int w; // IW
	(void)m;

    w = ft_strlen(m->map[0]);
    m->width = w;
    m->height = ft_2dlen(m->map);
	data->mlx = mlx_init(IW * w, IH * m->height, "CUB3D", 0);
    printf("--_---> %d\n", m->height);
        printf("WW---_>----------------QQ");
    exit(1);
	// mlx_texture_t *no_texture = mlx_load_png(m->no);
	// data->img = mlx_texture_to_image(data->mlx, no_texture);
	data->img = mlx_new_image(data->mlx, IW, IH);
	// // if (!m->mlx_ptr)
	// // 	quit_program (WINDOW_ERROR, m);
	// //mlx_image_to_window(data->mlx, image, 1, 1);
	// draw_elements (m);
	mlx_loop_hook(data->mlx, &hook, data);
	// mlx_image_to_window(data->mlx, data->img, 0, 0);
	mlx_loop(data->mlx);
}
