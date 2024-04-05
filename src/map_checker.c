/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:50:02 by dgiurgev          #+#    #+#             */
/*   Updated: 2024/04/05 02:36:55 by dgiurgev         ###   ########.fr       */
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

void	validate_counts(int playercount, int collectibles, int exitcount)
{
	if (playercount != 1)
	{
		ft_printf("Error: Map should have exactly one player, but has %d\n",
			playercount);
		exit(EXIT_FAILURE);
	}
	if (exitcount != 1)
	{
		ft_printf("Error: Map should have exactly one exit, but has %d\n",
			exitcount);
		exit(EXIT_FAILURE);
	}
	if (collectibles == 0)
	{
		ft_printf("Error: Map should have at least one collectible\n");
		exit(EXIT_FAILURE);
	}
}

void	validate_edges(t_map *map)
{
	check_edges(map);
	check_top_bottom(map);
	if (ft_strchr(map->map[0], '0')
		||ft_strchr(map->map[map->height - 1], '0'))
	{
		ft_printf("Error: Map should be enclosed by walls on top and bottom\n");
		exit(EXIT_FAILURE);
	}
}

void	map_checker(t_map *map)
{
	t_check	check;
	int		playercount;
	int		collectibles;
	int		exitcount;

	check_rectangular(map);
	count_elements(map, &playercount, &collectibles, &exitcount);
	validate_counts(playercount, collectibles, exitcount);
	validate_edges(map);
	check_init(map, &check);
	floodfill(&check, check.x, check.y);
	if (check.collectible != 0 || check.exit != 0)
	{
		ft_printf("Error: Not all collectibles have been found or the exit has not \
		been reached\n");
		exit(EXIT_FAILURE);
	}
}
