#ifndef __ANIMATIONS_H__
# define __ANIMATIONS_H__

# include "so_long.h"

typedef struct s_animation
{
	t_list*		frames;
	int			frame_speed;		// The speed of the animation in miliseconds
	double		accum;				// The accumulator to controll the speed
	int			current_frame_num;	// Which frame is selected
	int			mirrored;
	long int	frame_count;		// The frame count
}				t_animation;

typedef struct sprite_slice
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	padding_x;
	int	padding_y;
}		sprite_slice;

typedef struct s_sprite
{
	mlx_image_t*	sprite_img;
	mlx_t*			mlx;
}					t_sprite;

/* SPRITES */
t_sprite		new_sprite(char* file_name, mlx_t* mlx);
t_animation*	slice_sprite(t_sprite* s, sprite_slice slice, int mirrored, int frames, int delay);
void			destroy_sprite(t_sprite* s);
static int		get_rgba(int r, int g, int b, int a);

#endif
