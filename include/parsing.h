# ifndef PARSING_H
# define PARSING_H
# define MISSING_IDENTIFIER 404
# define SPACE 32
# define MISSING_MAP 405
# define INVALID_MAP 400
# define WALL 49
# define IW 75
# define IH 75
# define WINDOW_ERROR 401
# define SUCCESS 1

# include "../src/get_next_line/get_next_line.h"
# include "../src/libft/libft.h"
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include "MLX42/MLX42.h"

typedef struct s_map
{
    char    **map;
    int     width;
    int     height;
    int     x;
    int     y;
    char    *no;
    char    *so;
    char    *we;
    char    *ea;
    char    *f;
    char    *c;
    void    *mlx_ptr;
    void    *mlx_win;
} t_map;

typedef struct data_s
{
    struct mlx mlx;
    mlx_image_t img;
    t_map *map;
}t_data;

void        quit_program(int errid, t_map *m);
char		**realloc_2d(char **tab, char *str);
void        read_file(int fd, t_map *m);
char        *ft_strdup_no_newlines(const char *s1);
void        clean_directions(t_map *m);
char        *remove_spaces_id(char *str, t_map *m);
size_t      ft_strlen_from(const char *str, int i);
size_t      ft_strlen_without(const char *str, int pos, char exc);
void        read_map_lines (char **lines, t_map *m);
int         get_map_start_line(char **lines);
char        *remove_char(char *str, char c);
void        check_map (t_map *m);
void        check_lines_width(t_map *m);
size_t	    ft_2dlen(char **tab);
int         is_wall(char c);
void        start_game_window(t_map *m);
void        free_2darr(char **tab);
void        init_struct_pointers(t_map *m);

#endif
