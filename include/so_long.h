/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 23:48:51 by dgiurgev          #+#    #+#             */
/*   Updated: 2024/03/23 00:10:43 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define TILE 16

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/ft_printf/include/ft_printf.h"
# include "../lib/get_next_line/include/get_next_line.h"
# include "../lib/libft/include/libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
	int			width;
	int			height;
	char		**map;
	mlx_t		*mlx;
	mlx_image_t	*player;
	mlx_image_t	*collectible;
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*exit;
	int			movements;
	int			collectible_count;
	int			collectible_saved;
}				t_map;

void			error(void);
void			parse_map(char *file, t_map *map);
void			draw_floor(mlx_t *mlx, t_map *map, mlx_texture_t *texture);
void			draw_wall(mlx_t *mlx, t_map *map, mlx_texture_t *texture);
void			draw_exit(mlx_t *mlx, t_map *map, mlx_texture_t *texture);
void			draw_collectible(mlx_t *mlx, t_map *map,
					mlx_texture_t *texture);
void			ft_hook(mlx_key_data_t keydata, void *param);
void			draw_player(mlx_t *mlx, t_map *map, mlx_texture_t *texture);
void			ft_move(t_map *map, int delta_x, int delta_y);
void			load_png(mlx_t mlx, t_map *map);
void			handle_escape_key(mlx_key_data_t keydata, t_map *map);
void			handle_w_key(mlx_key_data_t keydata, t_map *map);
void			handle_a_key(mlx_key_data_t keydata, t_map *map);
void			handle_s_key(mlx_key_data_t keydata, t_map *map);
void			handle_d_key(mlx_key_data_t keydata, t_map *map);

#endif
