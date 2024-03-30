/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 23:48:51 by dgiurgev          #+#    #+#             */
/*   Updated: 2024/03/30 00:58:24 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define TILE 16

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/include/libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdbool.h>

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

typedef struct s_check
{
	char	**cpy;
	int		x;
	int		y;
	int		collectible;
	int		exit;
	bool	**visited;
}	t_check;

void			error(void);
void			parse_map(char *file, t_map *map);
void			map_checker(t_map *map);
void			check_edges(t_map *map);
void			check_top_bottom(t_map *map);
void			check_init(t_map *map, t_check *check);
void			floodfill(t_check *check, int x, int y);
void			draw_floor(mlx_t *mlx, t_map *map, mlx_texture_t *texture);
void			draw_wall(mlx_t *mlx, t_map *map, mlx_texture_t *texture);
void			draw_exit(mlx_t *mlx, t_map *map, mlx_texture_t *texture);
void			draw_collectible(mlx_t *mlx, t_map *map,
					mlx_texture_t *texture);
void			draw_player(mlx_t *mlx, t_map *map, mlx_texture_t *texture);
void			load_png(mlx_t mlx, t_map *map);
void			ft_move(t_map *map, int delta_x, int delta_y);
void			ft_hook(mlx_key_data_t keydata, void *param);
void			handle_escape_key(mlx_key_data_t keydata, t_map *map);
void			handle_w_key(mlx_key_data_t keydata, t_map *map);
void			handle_a_key(mlx_key_data_t keydata, t_map *map);
void			handle_s_key(mlx_key_data_t keydata, t_map *map);
void			handle_d_key(mlx_key_data_t keydata, t_map *map);

#endif
