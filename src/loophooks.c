/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loophooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:22:29 by dgiurgev          #+#    #+#             */
/*   Updated: 2024/03/11 15:22:31 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdio.h>

void ft_hook(mlx_key_data_t keydata, void* param) {
	t_map *map = (t_map*)param;
		int new_x;
		int new_y;

	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(map->mlx);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS) {
		new_x = map->player->instances[0].x / TILE;
		new_y = (map->player->instances[0].y - TILE) / TILE;
		if (map->map[new_y][new_x] != '1') {
			if(map->map[new_y][new_x] == 'E' && map->collectible_count == 0) {
				mlx_close_window(map->mlx);
			}
			if (map->map[new_y][new_x] == 'C') {
				map->map[new_y][new_x] = '0';
				map->collectible_count--;
				printf("collectibles:""%d\n", map->collectible_count);
			}
			ft_move(map, 0, -1);
			map->movements++;
			printf("%d\n", map->movements);
		}
	}
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS) {
		new_x = (map->player->instances[0].x - TILE) / TILE;
		new_y = map->player->instances[0].y / TILE;
		if (map->map[new_y][new_x] != '1') {
			if(map->map[new_y][new_x] == 'E' && map->collectible_count == 0) {
				mlx_close_window(map->mlx);
			}
			if (map->map[new_y][new_x] == 'C') {
				map->map[new_y][new_x] = '0';
				map->collectible_count--;
				printf("collectibles:""%d\n", map->collectible_count);
			}
			ft_move(map, -1, 0);
			map->movements++;
			printf("%d\n", map->movements);
		}
	}
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS) {
		new_x = map->player->instances[0].x / TILE;
		new_y = (map->player->instances[0].y + TILE) / TILE;
		if (map->map[new_y][new_x] != '1') {
			if(map->map[new_y][new_x] == 'E' && map->collectible_count == 0) {
				mlx_close_window(map->mlx);
			}
			if (map->map[new_y][new_x] == 'C') {
				map->map[new_y][new_x] = '0';
				map->collectible_count--;
				printf("collectibles:""%d\n", map->collectible_count);
			}
			ft_move(map, 0, 1);
			map->movements++;
			printf("%d\n", map->movements);
		}
	}

	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS) {
		new_x = (map->player->instances[0].x + TILE) / TILE;
		new_y = map->player->instances[0].y / TILE;
		if (map->map[new_y][new_x] != '1') {
			if(map->map[new_y][new_x] == 'E' && map->collectible_count == 0) {
				mlx_close_window(map->mlx);
			}
			if (map->map[new_y][new_x] == 'C') {
				map->map[new_y][new_x] = '0';
				map->collectible_count--;
				printf("collectibles:""%d\n", map->collectible_count);
			}
			ft_move(map, 1, 0);
			map->movements++;
			printf("%d\n", map->movements);
		}
	}
}
