/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:10:42 by dgiurgev          #+#    #+#             */
/*   Updated: 2024/04/19 13:13:59 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_floor(mlx_t *mlx, t_map *map, mlx_texture_t *texture)
{
	int	y;
	int	x;

	texture->width = TILE;
	texture->height = TILE;
	map->floor = mlx_texture_to_image(mlx, texture);
	if (!map->floor)
		error();
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (mlx_image_to_window(mlx, map->floor, x * TILE, y * TILE) < 0)
				error();
			x++;
		}
		y++;
	}
}

void	draw_wall(mlx_t *mlx, t_map *map, mlx_texture_t *texture)
{
	int	y;
	int	x;

	texture->width = TILE;
	texture->height = TILE;
	map->wall = mlx_texture_to_image(mlx, texture);
	if (!map->wall)
		error();
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == '1')
			{
				if (mlx_image_to_window(mlx, map->wall, x * TILE, y * TILE) < 0)
					error();
			}
			x++;
		}
		y++;
	}
}

void	draw_exit(mlx_t *mlx, t_map *map, mlx_texture_t *texture)
{
	int	y;
	int	x;

	texture->width = TILE;
	texture->height = TILE;
	map->exit = mlx_texture_to_image(mlx, texture);
	if (!map->exit)
		error();
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == 'E')
			{
				if (mlx_image_to_window(mlx, map->exit, x * TILE, y * TILE) < 0)
					error();
			}
			x++;
		}
		y++;
	}
}

void	draw_collectible(mlx_t *mlx, t_map *map, mlx_texture_t *texture)
{
	texture->width = TILE;
	texture->height = TILE;
	map->collectible_count = 0;
	map->collectible = mlx_texture_to_image(mlx, texture);
	if (!map->collectible)
		error();
	collectible_helper(mlx, map);
	map->collectible_saved = map->collectible_count;
}

void	draw_player(mlx_t *mlx, t_map *map, mlx_texture_t *texture[6])
{
	int	i;

	texture[0]->width = TILE;
	texture[0]->height = TILE;
	i = 0;
	while (i < 6)
	{
		map->player[i] = mlx_texture_to_image(mlx, texture[i]);
		if (!map->player[i])
			error();
		player_helper(mlx, map, i);
		i++;
	}
}
