#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

# include "../lib/libft/include/libft.h"
# include "../lib/ft_printf/include/ft_printf.h"
# include "../lib/get_next_line/include/get_next_line.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"

# define WIDTH 640
# define HEIGHT 360

static int	get_rgba(int r, int g, int b, int a);
int32_t	mlx_get_pixel(mlx_image_t *image, uint32_t x, uint32_t y);

void	error(void);

#endif
