/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 21:00:47 by dgiurgev          #+#    #+#             */
/*   Updated: 2024/04/07 22:00:06 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	load_enemy(mlx_t mlx, t_map *map)
{
	mlx_texture_t	*enemy;

	enemy = NULL;
	enemy = mlx_load_png("./images/enemy.png");
	if (!enemy)
		error();
	draw_enemy(&mlx, map, enemy);
	mlx_delete_texture(enemy);
}

void	draw_enemy(mlx_t *mlx, t_map *map, mlx_texture_t *texture)
{
	int	y;
	int	x;

	texture->width = TILE;
	texture->height = TILE;
	map->enemy = mlx_texture_to_image(mlx, texture);
	if (!map->enemy)
		error();
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == 'X')
			{
				if (mlx_image_to_window(mlx, map->enemy,
						x * TILE, y * TILE) < 0)
					error();
			}
			x++;
		}
		y++;
	}
}
