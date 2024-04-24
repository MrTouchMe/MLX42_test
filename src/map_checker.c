/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:50:02 by dgiurgev          #+#    #+#             */
/*   Updated: 2024/04/24 18:53:26 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	count_elements(t_map *map, int *playercount, int *collectibles,
int *exitcount)
{
	int	x;
	int	y;

	*playercount = 0;
	*collectibles = 0;
	*exitcount = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == 'P')
				(*playercount)++;
			if (map->map[y][x] == 'C')
				(*collectibles)++;
			if (map->map[y][x] == 'E')
				(*exitcount)++;
			x++;
		}
		y++;
	}
}

int	validate_counts(int playercount, int collectibles, int exitcount)
{
	if (playercount != 1)
	{
		ft_printf("Error: Map should have exactly one player, but has %d\n", \
playercount);
		return (1);
	}
	if (exitcount != 1)
	{
		ft_printf("Error: Map should have exactly one exit, but has %d\n", \
exitcount);
		return (1);
	}
	if (collectibles == 0)
	{
		ft_printf("Error: Map should have at least one collectible\n");
		return (1);
	}
	return (0);
}

int	validate_edges(t_map *map)
{
	if (check_edges(map) || check_top_bottom(map))
		return (1);
	if (ft_strchr(map->map[0], '0')
		||ft_strchr(map->map[map->height - 1], '0'))
	{
		ft_printf("Error: Map should be enclosed by walls on top and bottom\n");
		return (1);
	}
	return (0);
}

int	map_checker(t_map *map)
{
	t_check	check;
	int		playercount;
	int		collectibles;
	int		exitcount;

	if (check_rectangular(map))
		return (1);
	count_elements(map, &playercount, &collectibles, &exitcount);
	if (validate_counts(playercount, collectibles, exitcount) == 1)
		return (1);
	if (validate_edges(map))
		return (1);
	if (check_init(map, &check))
		return (1);
	floodfill(&check, check.x, check.y);
	if (check.collectible != 0 || check.exit != 0)
	{
		ft_printf("Error: Not all collectibles or the exit has not been \
reached\n");
		free(check.cpy);
		return (1);
	}
	return (0);
}
