/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybinds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:22:29 by dgiurgev          #+#    #+#             */
/*   Updated: 2024/04/02 23:31:42 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	handle_escape_key(mlx_key_data_t keydata, t_map *map)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(map->mlx);
}

void	handle_w_key(mlx_key_data_t keydata, t_map *map)
{
	int	x;
	int	y;
	int	i;

	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
	{
		x = map->player->instances[0].x / TILE;
		y = (map->player->instances[0].y - TILE) / TILE;
		if (map->map[y][x] != '1')
		{
			if (map->map[y][x] == 'E' && map->collectible_count == 0)
				mlx_close_window(map->mlx);
			if (map->map[y][x] == 'C')
			{
				map->map[y][x] = '0';
				map->collectible_count--;
				i = 0;
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
			ft_move(map, 0, -1);
			map->movements++;
			ft_printf("%d\n", map->movements);
			mlx_image_to_window(map->mlx, map->wall, 0, 0);
			mlx_image_to_window(map->mlx, map->wall, 0, TILE);
			mlx_image_to_window(map->mlx, map->wall, TILE, 0);
			mlx_put_string(map->mlx, ft_itoa(map->movements), 0, 0);
		}
	}
}

void	handle_a_key(mlx_key_data_t keydata, t_map *map)
{
	int	x;
	int	y;
	int	i;

	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
	{
		x = (map->player->instances[0].x - TILE) / TILE;
		y = map->player->instances[0].y / TILE;
		if (map->map[y][x] != '1')
		{
			if (map->map[y][x] == 'E' && map->collectible_count == 0)
				mlx_close_window(map->mlx);
			if (map->map[y][x] == 'C')
			{
				map->map[y][x] = '0';
				map->collectible_count--;
				i = 0;
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
			ft_move(map, -1, 0);
			map->movements++;
			ft_printf("%d\n", map->movements);
			mlx_image_to_window(map->mlx, map->wall, 0, 0);
			mlx_image_to_window(map->mlx, map->wall, 0, TILE);
			mlx_image_to_window(map->mlx, map->wall, TILE, 0);
			mlx_put_string(map->mlx, ft_itoa(map->movements), 0, 0);
		}
	}
}

void	handle_s_key(mlx_key_data_t keydata, t_map *map)
{
	int	x;
	int	y;
	int	i;

	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
	{
		x = map->player->instances[0].x / TILE;
		y = (map->player->instances[0].y + TILE) / TILE;
		if (map->map[y][x] != '1')
		{
			if (map->map[y][x] == 'E' && map->collectible_count == 0)
				mlx_close_window(map->mlx);
			if (map->map[y][x] == 'C')
			{
				map->map[y][x] = '0';
				map->collectible_count--;
				i = 0;
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
			ft_move(map, 0, 1);
			map->movements++;
			ft_printf("%d\n", map->movements);
			mlx_image_to_window(map->mlx, map->wall, 0, 0);
			mlx_image_to_window(map->mlx, map->wall, 0, TILE);
			mlx_image_to_window(map->mlx, map->wall, TILE, 0);
			mlx_put_string(map->mlx, ft_itoa(map->movements), 0, 0);
		}
	}
}

void	handle_d_key(mlx_key_data_t keydata, t_map *map)
{
	int	x;
	int	y;
	int	i;

	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
	{
		x = (map->player->instances[0].x + TILE) / TILE;
		y = map->player->instances[0].y / TILE;
		if (map->map[y][x] != '1')
		{
			if (map->map[y][x] == 'E' && map->collectible_count == 0)
				mlx_close_window(map->mlx);
			if (map->map[y][x] == 'C')
			{
				map->map[y][x] = '0';
				map->collectible_count--;
				i = 0;
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
			ft_move(map, 1, 0);
			map->movements++;
			ft_printf("%d\n", map->movements);
			mlx_image_to_window(map->mlx, map->wall, 0, 0);
			mlx_image_to_window(map->mlx, map->wall, 0, TILE);
			mlx_image_to_window(map->mlx, map->wall, TILE, 0);
			mlx_put_string(map->mlx, ft_itoa(map->movements), 0, 0);
		}
	}
}
