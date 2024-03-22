#include "../../include/parsing.h"

void updatePlayerPosition(t_data *data,int deltaX, int deltaY) {
    // int deltaX = SPEED + cos(dir);
    // int deltaY = SPEED + sin(dir);
    data->x += deltaX;
    data->y += deltaY;
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
                        color = 0x0000FF;
                    else
                        color = 0x00FF00FF;

                    // if (pixelX == tileX || pixelX == tileX + TILE_SIZE - 1 ||
                    //     pixelY == tileY || pixelY == tileY + TILE_SIZE - 1) {
                    //     if (data->map_dub[i][j] == 1 || data->map_dub[i][j] == 0)
                    //         color = 0x000000FF;
                    // }

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

void hook(void *param)
{
    t_data *mlx = (t_data *)param;
    mlx_key_data_t data;
    int Color = 0x808080FF;

    mlx_delete_image(mlx->mlx,mlx->img);
    mlx->img = mlx_new_image(mlx->mlx,IW * mlx->width,mlx->height * IH);
    if(mlx_is_key_down(mlx->mlx,MLX_KEY_A))
        mlx->angle -= 0.1;
    else if (mlx_is_key_down(mlx->mlx,MLX_KEY_D))
    {
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
    // draw_map(mlx);
    // draw_player(mlx, 8, Color);
    // draw_line(mlx,mlx->x,mlx->y,50,mlx->angle,Color);
    mlx_image_to_window(mlx->mlx,mlx->img,0,0);
    draw_game(mlx);
}


void    duplicate_map(t_map *m, t_data *data, int w)
{
    int i;
    int j;

    i = 0;
    data->map_dub = (char**) malloc(sizeof(char *) * (data->height + 1));
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
}
