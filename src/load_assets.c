/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:03:39 by dgiurgev          #+#    #+#             */
/*   Updated: 2024/04/07 21:01:17 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	load_floor(mlx_t mlx, t_map *map)
{
	mlx_texture_t	*floor;

	floor = NULL;
	floor = mlx_load_png("./images/floor.png");
	if (!floor)
		error();
	draw_floor(&mlx, map, floor);
	mlx_delete_texture(floor);
}

void	load_wall(mlx_t mlx, t_map *map)
{
	mlx_texture_t	*wall;

	wall = NULL;
	wall = mlx_load_png("./images/wall.png");
	if (!wall)
		error();
	draw_wall(&mlx, map, wall);
	mlx_delete_texture(wall);
}

void	load_exit(mlx_t mlx, t_map *map)
{
	mlx_texture_t	*exit;

	exit = NULL;
	exit = mlx_load_png("./images/exit.png");
	if (!exit)
		error();
	draw_exit(&mlx, map, exit);
	mlx_delete_texture(exit);
}

void	load_collectible(mlx_t mlx, t_map *map)
{
	mlx_texture_t	*collectible;

	collectible = NULL;
	collectible = mlx_load_png("./images/key.png");
	if (!collectible)
		error();
	draw_collectible(&mlx, map, collectible);
	mlx_delete_texture(collectible);
}

void	load_player(mlx_t mlx, t_map *map)
{
	mlx_texture_t	*player;

	player = NULL;
	player = mlx_load_png("./images/player.png");
	if (!player)
		error();
	draw_player(&mlx, map, player);
	mlx_delete_texture(player);
}
