#include "../../include/parsing.h"

void draw(t_data *data) {

    int i = 0;
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
                    if (data->map->map[i][j] == 0)
                        color = 0x00FF00FF;
                    else
                        color = 0x0F00FFFF;

                    if (pixelX == tileX  ||pixelX == tileX + TILE_SIZE - 1 
                        ||pixelY == tileY  ||pixelY == tileY + TILE_SIZE - 1) {
                        if (data->map->map[i][j] == 1 ||data->map->map[i][j] == 0)
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

void    start_game_window(t_map *m, t_data *data)
{
    int w; // width
	(void)m;

    w = ft_strlen(m->map[0]);
    m->height = ft_2dlen(m->map);
	data->mlx = mlx_init(IW * w, IH * m->height, "CUB3D", 0);
	mlx_texture_t *no_texture = mlx_load_png(m->no);
	mlx_image_t *image = mlx_texture_to_image(data->mlx, no_texture);
	// data->img = mlx_new_image(data->mlx, IW, IH);
	// if (!m->mlx_ptr)
	// 	quit_program (WINDOW_ERROR, m);
	mlx_image_to_window(data->mlx, image, 1, 1);
	//draw_elements (m);
	//draw(data);
	mlx_loop(data->mlx);
}
