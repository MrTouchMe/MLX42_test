/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:10:42 by dgiurgev          #+#    #+#             */
/*   Updated: 2024/03/12 16:47:33 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/so_long.h"

void draw_floor(mlx_t *mlx, t_map *map, mlx_texture_t *texture) {
	texture->width = TILE;
	texture->height = TILE;

	map->floor = mlx_texture_to_image(mlx, texture);
	if (!map->floor)
		error();
	for (int y = 0; y < map->height; y++) {
		for (int x = 0; x < map->width; x++) {
			if (mlx_image_to_window(mlx, map->floor, x * TILE, y * TILE) < 0)
				error();
		}
	}
}

void draw_wall(mlx_t *mlx, t_map *map, mlx_texture_t *texture) {
	texture->width = TILE;
	texture->height = TILE;

	map->wall = mlx_texture_to_image(mlx, texture);
	if (!map->wall)
		error();
	for (int y = 0; y < map->height; y++) {
		for (int x = 0; x < map->width; x++) {
			if(map->map[y][x] == '1') {
				if (mlx_image_to_window(mlx, map->wall, x * TILE, y * TILE) < 0)
					error();
			}
		}
	}
}

void draw_exit(mlx_t *mlx, t_map *map, mlx_texture_t *texture) {
	texture->width = TILE;
	texture->height = TILE;

	map->exit = mlx_texture_to_image(mlx, texture);
	if (!map->exit)
		error();
	for (int y = 0; y < map->height; y++) {
		for (int x = 0; x < map->width; x++) {
			if(map->map[y][x] == 'E') {
				if (mlx_image_to_window(mlx, map->exit, x * TILE, y * TILE) < 0)
					error();
			}
		}
	}
}

void draw_collectible(mlx_t *mlx, t_map *map, mlx_texture_t *texture) {
	texture->width = TILE;
	texture->height = TILE;
	map->collectible_count = 0;

	map->collectible = mlx_texture_to_image(mlx, texture);
	if (!map->collectible)
		error();
	for (int y = 0; y < map->height; y++) {
		for (int x = 0; x < map->width; x++) {
			if(map->map[y][x] == 'C') {
				map->collectible_count++;
				if (mlx_image_to_window(mlx, map->collectible, x * TILE, y * TILE) < 0)
					error();
			}
		}
	}
	printf("collectibles:""%d\n", map->collectible_count);
}

void draw_player(mlx_t *mlx, t_map *map, mlx_texture_t *texture) {
	texture->width = TILE;
	texture->height = TILE;

	map->player = mlx_texture_to_image(mlx, texture);
	if (!map->player)
		error();
	for (int y = 0; y < map->height; y++) {
		for (int x = 0; x < map->width; x++) {
			if(map->map[y][x] == 'P') {
				if (mlx_image_to_window(mlx, map->player, x * TILE, y * TILE) < 0)
					error();
			}
		}
	}
}

// if(map->map[y][x] == 'E') {
// mlx_close_window(map->mlx);
// }
