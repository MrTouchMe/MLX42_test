#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/ft_printf/include/ft_printf.h"
# include "../lib/get_next_line/include/get_next_line.h"
# include "../lib/libft/include/libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// # define WIDTH 640
// # define HEIGHT 360
# define TILE 16

typedef struct s_map
{
	int width;
	int height;
	char **map;
} t_map;

typedef struct s_player {
	int x;
	int y;
	char **player;
} t_player;

typedef struct s_animation
{
	t_list *frames;
	int frame_speed;       // The speed of the animation in miliseconds
	double accum;          // The accumulator to controll the speed
	int current_frame_num; // Which frame is selected
	int mirrored;
	long int frame_count; // The frame count
} t_animation;

typedef struct sprite_slice
{
	int x;
	int y;
	int width;
	int height;
	int padding_x;
	int padding_y;
} sprite_slice;

typedef struct s_sprite
{
	mlx_image_t *sprite_img;
	mlx_t *mlx;
} t_sprite;

void error(void);
t_sprite new_sprite(char *file_name, mlx_t *mlx);
t_animation *slice_sprite(t_sprite *s, sprite_slice slice, int mirrored, int frames, int delay);
void destroy_sprite(t_sprite *s);
// static int get_rgba(int r, int g, int b, int a);
void parse_map(char *file, t_map *map);
void draw_floor(mlx_t *mlx, t_map *map, mlx_texture_t *texture);
void draw_wall(mlx_t *mlx, t_map *map, mlx_texture_t *texture);
void draw_exit(mlx_t *mlx, t_map *map, mlx_texture_t *texture);
void draw_collectible(mlx_t *mlx, t_map *map, mlx_texture_t *texture);
void ft_hook(void* param);
void draw_player(mlx_t *mlx, t_map *map,/*t_player *player,*/ mlx_texture_t *texture);
#endif
