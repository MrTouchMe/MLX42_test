/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:03:39 by dgiurgev          #+#    #+#             */
/*   Updated: 2024/04/10 18:47:35 by dgiurgev         ###   ########.fr       */
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
	mlx_texture_t	*player[6];
	int				i;

	i = 0;
	while (i < 5)
		player[i++] = NULL;
	i = 0;
	load_player_helper(player);
	draw_player(&mlx, map, player);
	while (i < 5)
		mlx_delete_texture(player[i++]);
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
