/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybinds_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 00:29:31 by dgiurgev          #+#    #+#             */
/*   Updated: 2024/04/22 22:01:27 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	handle_collectible(t_map *map, int x, int y)
{
	int	i;

	i = 0;
	map->map[y][x] = '0';
	map->collectible_count--;
	while (i < map->collectible_saved)
	{
		if (map->collectible->instances[i].x == x * TILE
			&& map->collectible->instances[i].y == y * TILE)
			break ;
		i++;
	}
	map->collectible->instances[i].enabled = false;
	ft_printf("collectibles:" "%d\n", map->collectible_count);
}

int	check_edges(t_map *map)
{
	int	y;

	y = 0;
	while (y < map->height)
	{
		if (+map->map[y][0] != '1' || map->map[y][map->width -1] != '1')
		{
			ft_printf("Error: Map should be enclosed by walls on left and \
right\n");
			ft_printf("%c %c\n", map->map[y][0], map->map[y][map->width - 1]);
			return (1);
		}
		y++;
	}
	return (0);
}

void	load_player_helper(mlx_texture_t *player[])
{
	player[0] = mlx_load_png("./images/player0.png");
	if (!player[0])
		error();
	player[1] = mlx_load_png("./images/player1.png");
	if (!player[1])
		error();
	player[2] = mlx_load_png("./images/player2.png");
	if (!player[2])
		error();
	player[3] = mlx_load_png("./images/player3.png");
	if (!player[3])
		error();
	player[4] = mlx_load_png("./images/player4.png");
	if (!player[4])
		error();
	player[5] = mlx_load_png("./images/player5.png");
	if (!player[5])
		error();
}

void	player_helper(mlx_t *mlx, t_map *map, int i)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == 'P')
			{
				if (mlx_image_to_window(mlx, map->player[i], x * TILE, y
						* TILE) < 0)
					error();
			}
			x++;
		}
		y++;
	}
}

void	collectible_helper(mlx_t *mlx, t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == 'C')
			{
				map->collectible_count++;
				if (mlx_image_to_window(mlx, map->collectible, x * TILE, y
						* TILE) < 0)
					error();
			}
			x++;
		}
		y++;
	}
}
