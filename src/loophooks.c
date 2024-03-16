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
// #include <cstdio>

//exec key: detect the key (WASD) and move player

// void keyhooks (mlx_t mlx, t_map *map, struct s_player *player) {
//     // Check for key press
//     if (action_t == MLX_PRESS) {
//         // Check for specific key and update player position
//         // For example, if 'w' is pressed, move player up
//     }
// }

// static mlx_image_t* image;

// void ft_hook(void* param) {
// 	mlx_t* mlx = param;

// 	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(mlx);
// 	if (mlx_is_key_down(mlx, MLX_KEY_UP))
// 		image->instances[0].y -= 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
// 		image->instances[0].y += 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
// 		image->instances[0].x -= 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
// 		image->instances[0].x += 5;
// }
//
// void ft_hook(mlx_key_data_t keydata, void* param) {
// 	t_map *map = (t_map*)param;

//  	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
// 		mlx_close_window(map->mlx);

// 	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS
// 		&& map->map[(int)map->player->instances[0].x / TILE][((int)map->player->instances[0].y / TILE) - 1] == '0')
// 		ft_move(map, 0, -1);


// 	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS
// 		&& map->map[((int)map->player->instances[0].x / TILE - 1)][(int)map->player->instances[0].y / TILE] == '0')
// 		ft_move(map, -1, 0);

// 	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS
// 		&& map->map[(int)map->player->instances[0].x / TILE][((int)map->player->instances[0].y / TILE) + 1] == '0')
// 		ft_move(map, 0, 1);

// 	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS
// 		&& map->map[((int)map->player->instances[0].x / TILE) + 1][(int)map->player->instances[0].y / TILE] == '0')
// 		ft_move(map, 1, 0);
// }

void ft_hook(mlx_key_data_t keydata, void* param) {
    t_map *map = (t_map*)param;


    if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
        mlx_close_window(map->mlx);

    int new_x, new_y;

    if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS) {
        new_x = map->player->instances[0].x / TILE;
        new_y = (map->player->instances[0].y - TILE) / TILE;
        if (map->map[new_y][new_x] != '1') {
            ft_move(map, 0, -1);
            map->movements++;
            printf("%d\n", map->movements);

        }
    }

    if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS) {
        new_x = (map->player->instances[0].x - TILE) / TILE;
        new_y = map->player->instances[0].y / TILE;
        if (map->map[new_y][new_x] != '1') {
            ft_move(map, -1, 0);
            map->movements++;
            printf("%d\n", map->movements);
        }
    }

    if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS) {
        new_x = map->player->instances[0].x / TILE;
        new_y = (map->player->instances[0].y + TILE) / TILE;
        if (map->map[new_y][new_x] != '1') {
            ft_move(map, 0, 1);
            map->movements++;
            printf("%d\n", map->movements);
        }
    }

    if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS) {
        new_x = (map->player->instances[0].x + TILE) / TILE;
        new_y = map->player->instances[0].y / TILE;
        if (map->map[new_y][new_x] != '1') {
            ft_move(map, 1, 0);
            map->movements++;
            printf("%d\n", map->movements);
        }
    }
}
