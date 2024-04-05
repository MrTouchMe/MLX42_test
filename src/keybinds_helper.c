/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybinds_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 00:29:31 by dgiurgev          #+#    #+#             */
/*   Updated: 2024/04/05 00:32:53 by dgiurgev         ###   ########.fr       */
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
