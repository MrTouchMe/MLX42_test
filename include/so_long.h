/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 23:48:51 by dgiurgev          #+#    #+#             */
/*   Updated: 2024/04/10 18:53:56 by dgiurgev         ###   ########.fr       */
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
	mlx_image_t	*player[6];
	mlx_image_t	*enemy;
	mlx_image_t	*collectible;
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*exit;
	mlx_image_t	*counter;
	int			player_frame;
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
}			t_check;

void	free_check(t_check *check);
void	error(void);
void	skill_issue(t_map *map);
void	ggez(t_map *map);
void	esc_exit(t_map *map);
void	open_file(char *file, int *fd);
void	calculate_map_dimensions(int fd, t_map *map);
void	allocate_map_memory(t_map *map);
void	read_map_into_memory(int fd, t_map *map);
int		parse_map(char *file, t_map *map);
void	count_elements(t_map *map, int *playercount, int *collectibles,
			int *exitcount);
int		validate_counts(int playercount, int collectibles, int exitcount);
int		validate_edges(t_map *map);
int		map_checker(t_map *map);
int		check_rectangular(t_map *map);
int		check_edges(t_map *map);
int		check_top_bottom(t_map *map);
int		check_init(t_map *map, t_check *check);
void	check_init_helper(t_map *map, t_check *check, int x, int y);
void	floodfill(t_check *check, int x, int y);
void	draw_floor(mlx_t *mlx, t_map *map, mlx_texture_t *texture);
void	draw_wall(mlx_t *mlx, t_map *map, mlx_texture_t *texture);
void	draw_exit(mlx_t *mlx, t_map *map, mlx_texture_t *texture);
void	draw_collectible(mlx_t *mlx, t_map *map,
			mlx_texture_t *texture);
void	collectible_helper(mlx_t *mlx, t_map *map);
void	draw_enemy(mlx_t *mlx, t_map *map, mlx_texture_t *texture);
void	draw_player(mlx_t *mlx, t_map *map, mlx_texture_t *texture[6]);
void	player_helper(mlx_t *mlx, t_map *map, int i);
void	load_png(mlx_t mlx, t_map *map);
void	load_floor(mlx_t mlx, t_map *map);
void	load_wall(mlx_t mlx, t_map *map);
void	load_exit(mlx_t mlx, t_map *map);
void	load_collectible(mlx_t mlx, t_map *map);
void	load_enemy(mlx_t mlx, t_map *map);
void	load_player(mlx_t mlx, t_map *map);
void	load_player_helper(mlx_texture_t *player[]);
void	ft_move(t_map *map, int delta_x, int delta_y);
void	ft_hook(mlx_key_data_t keydata, void *param);
void	handle_escape_key(mlx_key_data_t keydata, t_map *map);
void	handle_w_key(mlx_key_data_t keydata, t_map *map);
void	handle_a_key(mlx_key_data_t keydata, t_map *map);
void	handle_s_key(mlx_key_data_t keydata, t_map *map);
void	handle_d_key(mlx_key_data_t keydata, t_map *map);
void	handle_collectible(t_map *map, int x, int y);

#endif
