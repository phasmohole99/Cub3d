/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrital- <mrital-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 06:16:36 by mrital-           #+#    #+#             */
/*   Updated: 2024/03/08 12:46:13 by mrital-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h> 
#include "mlx42/MLX42/MLX42.h"
#include <stdlib.h>
#include <math.h>


#define TILE_SIZE 48
#define MAP_NUM_ROWS 13
#define MAP_NUM_COLS 20
#define WIDTH (MAP_NUM_COLS * TILE_SIZE)
#define HEIGHT (MAP_NUM_ROWS * TILE_SIZE)
#define PI 3.14159265
#define SPEED 1.5

struct Player {
        float   y;
        float   x;
        float   width;
        float   height;
        int     turnDirection; // -1 for left, +1 for right
        int     walkDirection; // -1 for back, +1 for front
        float   rotationAngle;
        float   walkSpeed;
        float   turnSpeed;
} t_player;


typedef struct data_s
{
    int x;
    int y;
    int angle;
    struct mlx *mlx;
    t_player player;
    mlx_image_t *img;
    
}t_data;



const int map[MAP_NUM_ROWS][MAP_NUM_COLS] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1},
    {1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1},
    {1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1},
    {1, 0, 1, 0, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1},
    {1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

void draw_map(t_data *data) {
    int i = 0;
    while (i < MAP_NUM_ROWS) {
        int j = 0;
        while (j < MAP_NUM_COLS) {
            int tileX = j * TILE_SIZE;
            int tileY = i * TILE_SIZE;
            int row = 0;
            while (row < TILE_SIZE) {
                int col = 0;
                while (col < TILE_SIZE) {
                    int pixelX = tileX + col;
                    int pixelY = tileY + row;

                    int color;
                    if (map[i][j] == 1)
                        color = 0x00FF00FF;
                    else
                        color = 0x0F00FFFF;

                    if (pixelX == tileX || pixelX == tileX + TILE_SIZE - 1 ||
                        pixelY == tileY || pixelY == tileY + TILE_SIZE - 1) {
                        if (map[i][j] == 1 || map[i][j] == 0)
                            color = 0x000000FF;
                    }
                    if(pixelY >= 0 && pixelY < HEIGHT && pixelX >= 0 && pixelX <  WIDTH)
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
                if (x >= 0 && y >= 0 && x < WIDTH && y < HEIGHT) {
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

        if (x >= 0 && y >= 0 && x < WIDTH && y < HEIGHT) {
            mlx_put_pixel(data->img, x, y, color);
        }

        i++;
    }

    int endX = playerX + length * cos(angle);
    int endY = playerY + length * sin(angle);

    if (endX >= 0 && endY >= 0 && endX < WIDTH && endY < HEIGHT) {
        mlx_put_pixel(data->img, endX, endY, color);
    }
}


void updatePlayerPosition(t_data *data,int deltaX, int deltaY) {
    // int deltaX = SPEED + cos(dir);
    // int deltaY = SPEED + sin(dir);
    data->x += deltaX;
    data->y += deltaY;
}

void hook(void *param)
{

    t_data *mlx = (t_data *)param;
    mlx_key_data_t data;
    int Color = 0x808080FF; 
    mlx_delete_image(mlx->mlx,mlx->img);
    mlx->img = mlx_new_image(mlx->mlx,WIDTH,HEIGHT);

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


int main() {
    t_data *data = malloc(sizeof(*data));
    int radius = 8;
    // int lineLength = 40;
    // double lineAngle = 45 * PI;
    int Color = 0x808080FF; 
    data->x = WIDTH / 2;
    data->y = HEIGHT / 2;
    
    if(!data)
        return 0;
    data->mlx = mlx_init(WIDTH,HEIGHT,"mrital",false);
    if (data->mlx == NULL) {
        fprintf(stderr, "Error: Could not initialize MiniLibX\n");
        free(data);
        return -1;
    }
    data->img = mlx_new_image(data->mlx, WIDTH,HEIGHT);
    // draw_map(data);
    // draw_player(data, WIDTH / 2, HEIGHT / 2, radius, Color);
    data->angle = M_PI / 2;
    mlx_loop_hook(data->mlx, &hook, data);
    mlx_image_to_window(data->mlx,data->img,0,0);
    mlx_loop(data->mlx);
    mlx_terminate(data->mlx);
    free(data);
    return 0;
}