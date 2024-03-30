/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:50:02 by dgiurgev          #+#    #+#             */
/*   Updated: 2024/03/30 02:49:01 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdbool.h>

void map_checker(t_map *map) {
	int playerCount = 0;
	int rowLength = ft_strlen(map->map[0]);
	int collectibles = 0;
	int exit_count = 0;
	t_check check;

	for (int y = 0; y < map->height; y++) {
		if (ft_strlen(map->map[y]) != rowLength) {
			printf("Error: Map is not rectangular\n");
			exit(EXIT_FAILURE);
		}
		for (int x = 0; x < map->width; x++) {
			if (map->map[y][x] == 'P')
				playerCount++;
			if (map->map[y][x] == 'C')
				collectibles++;
			if (map->map[y][x] == 'E')
				exit_count++;
		}
	}
	check_edges(map);
	check_top_bottom(map);
	if (playerCount != 1) {
		printf("Error: Map should have exactly one player, but has %d\n", playerCount);
		exit(EXIT_FAILURE);
	}
	if (exit_count != 1) {
		printf("Error: Map should have exactly one exit, but has %d\n", exit_count);
		exit(EXIT_FAILURE);
	}
	if (collectibles == 0) {
		printf("Error: Map should have at least one collectible\n");
		exit(EXIT_FAILURE);
	}
	if (ft_strchr(map->map[0], '0') || ft_strchr(map->map[map->height - 1], '0')) {
		printf("Error: Map should be enclosed by walls on top and bottom\n");
		exit(EXIT_FAILURE);
	}
	check_init(map, &check);
	floodfill(&check, check.x, check.y);
	if (check.collectible != 0 || check.exit != 0) {
		printf("Error: Not all collectibles have been found or the exit has not been reached\n");
	exit(EXIT_FAILURE);
	}
}

void check_edges(t_map *map) {
	for (int y = 0; y < map->height; y++) {
		if (map->map[y][0] != '1' || map->map[y][map->width - 1] != '1') {
			printf("Error: Map should be enclosed by walls on left and right\n");
			printf("%c %c\n", map->map[y][0], map->map[y][map->width - 1]);
			exit(EXIT_FAILURE);
		}
	}
}

void check_top_bottom(t_map *map) {
	for (int x = 0; x < map->width; x++) {
		if (map->map[0][x] != '1' || map->map[map->height - 1][x] != '1') {
			printf("Error: Map should be enclosed by walls on top and bottom\n");
			printf("%c %c\n", map->map[0][x], map->map[map->height - 1][x]);
			exit(EXIT_FAILURE);
		}
	}
}

void check_init(t_map *map, t_check *check) {
    check->cpy = ft_calloc(map->height, sizeof(char *));
    check->collectible = 0;
    check->exit = 0;

    for (int y = 0; y < map->height; y++) {
        check->cpy[y] = ft_calloc(map->width + 1, sizeof(char));
        ft_strlcpy(check->cpy[y], map->map[y], map->width + 1);

        for (int x = 0; x < map->width; x++) {
            if (map->map[y][x] == 'P') {
                check->x = x;
                check->y = y;
            } else if (map->map[y][x] == 'C') {
                check->collectible++;
            } else if (map->map[y][x] == 'E') {
                check->exit++;
            }
        }
    }
}

void	floodfill(t_check *check, int x, int y)
{
    if (check->cpy[y][x] == '1' || check->cpy[y][x] == 'X')
        return ;
    if (check->cpy[y][x] == 'C') {
        check->collectible--;
    }
    if (check->cpy[y][x] == 'E') {
        check->exit = 0;
    }
    printf("Collectibles remaining: %d\n", check->collectible);
    printf("Exits remaining: %d\n", check->exit);
    check->cpy[y][x] = '1';
    floodfill(check, x + 1, y);
    floodfill(check, x - 1, y);
    floodfill(check, x, y + 1);
    floodfill(check, x, y - 1);
    return ;
}
