/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:50:02 by dgiurgev          #+#    #+#             */
/*   Updated: 2024/04/01 17:34:10 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdbool.h>

void	map_checker(t_map *map)
{
	t_check	check;
	int		playercount;
	int		rowlength;
	int		collectibles;
	int		exitcount;
	int		y;
	int		x;

	playercount = 0;
	rowlength = ft_strlen(map->map[0]);
	collectibles = 0;
	exitcount = 0;
	y = 0;
	while (y < map->height)
	{
		if (ft_strlen(map->map[y]) != rowlength)
		{
			ft_printf("Error: Map is not rectangular\n");
			exit(EXIT_FAILURE);
		}
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == 'P')
				playercount++;
			if (map->map[y][x] == 'C')
				collectibles++;
			if (map->map[y][x] == 'E')
				exitcount++;
			x++;
		}
		y++;
	}
	check_edges(map);
	check_top_bottom(map);
	if (playercount != 1)
	{
		ft_printf("Error: Map should have exactly one player, but \
		has %d\n", playercount);
		exit(EXIT_FAILURE);
	}
	if (exitcount != 1)
	{
		ft_printf("Error: Map should have exactly one exit, but \
		has %d\n", exitcount);
		exit(EXIT_FAILURE);
	}
	if (collectibles == 0)
	{
		ft_printf("Error: Map should have at least one collectible\n");
		exit(EXIT_FAILURE);
	}
	if (ft_strchr(map->map[0], '0')
		|| ft_strchr(map->map[map->height - 1], '0'))
	{
		ft_printf("Error: Map should be enclosed by walls on top and bottom\n");
		exit(EXIT_FAILURE);
	}
	check_init(map, &check);
	floodfill(&check, check.x, check.y);
	if (check.collectible != 0 || check.exit != 0)
	{
		ft_printf("Error: Not all collectibles have been found or the exit \
		has not been reached\n");
		exit(EXIT_FAILURE);
	}
}

void	check_edges(t_map *map)
{
	int	y;

	y = 0;
	while (y < map->height)
	{
		if (map->map[y][0] != '1' || map->map[y][map->width - 1] != '1')
		{
			ft_printf("Error: Map should be enclosed by walls on left and \
			right\n");
			ft_printf("%c %c\n", map->map[y][0], map->map[y][map->width - 1]);
			exit(EXIT_FAILURE);
		}
		y++;
	}
}

void	check_top_bottom(t_map *map)
{
	int	x;

	x = 0;
	while (x < map->width)
	{
		if (map->map[0][x] != '1' || map->map[map->height - 1][x] != '1')
		{
			ft_printf("Error: Map should be enclosed by walls on top and \
			bottom\n");
			ft_printf("%c %c\n", map->map[0][x], map->map[map->height - 1][x]);
			exit(EXIT_FAILURE);
		}
		x++;
	}
}

void	check_init(t_map *map, t_check *check)
{
	int	y;
	int	x;

	check->cpy = ft_calloc(map->height, sizeof(char *));
	check->collectible = 0;
	check->exit = 0;
	y = 0;
	while (y < map->height)
	{
		check->cpy[y] = ft_calloc(map->width + 1, sizeof(char));
		ft_strlcpy(check->cpy[y], map->map[y], map->width + 1);
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == 'P')
			{
				check->x = x;
				check->y = y;
			}
			else if (map->map[y][x] == 'C')
				check->collectible++;
			else if (map->map[y][x] == 'E')
				check->exit++;
			x++;
		}
		y++;
	}
}

void	floodfill(t_check *check, int x, int y)
{
	if (check->cpy[y][x] == '1' || check->cpy[y][x] == 'X')
		return ;
	if (check->cpy[y][x] == 'C')
	{
		check->collectible--;
	}
	if (check->cpy[y][x] == 'E')
	{
		check->exit = 0;
	}
	ft_printf("Collectibles remaining: %d\n", check->collectible);
	ft_printf("Exits remaining: %d\n", check->exit);
	check->cpy[y][x] = '1';
	floodfill(check, x + 1, y);
	floodfill(check, x - 1, y);
	floodfill(check, x, y + 1);
	floodfill(check, x, y - 1);
	return ;
}
