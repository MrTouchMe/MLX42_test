/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:50:02 by dgiurgev          #+#    #+#             */
/*   Updated: 2024/03/25 11:50:02 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void map_checker(t_map *map) {
	int playerCount = 0;
	int rowLength = ft_strlen(map->map[0]);
	int collectibles = 0;
	int exit_count = 0;

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

// void floodfill(t_map *map, int x, int y, char target, char replacement) {
// 	if (x < 0 || x >= map->width || y < 0 || y >= map->height)
// 		return;
// 	if (map->map[y][x] != target)
// 		return;
// 	map->map[y][x] = replacement;
// 	floodfill(map, x + 1, y, target, replacement);
// 	floodfill(map, x - 1, y, target, replacement);
// 	floodfill(map, x, y + 1, target, replacement);
// 	floodfill(map, x, y - 1, target, replacement);
// }

bool floodfill(t_map *map, int x, int y, char target, char exit, char collectible, int *collectibles_found) {
	if (x < 0 || x >= map->width || y < 0 || y >= map->height)
		return false;
	if (map->map[y][x] == exit)
		return true;
	if (map->map[y][x] == collectible)
		(*collectibles_found)++;
	if (map->map[y][x] != target && map->map[y][x] != collectible)
		return false;
	return floodfill(map, x + 1, y, target, exit, collectible, collectibles_found) ||
		floodfill(map, x - 1, y, target, exit, collectible, collectibles_found) ||
		floodfill(map, x, y + 1, target, exit, collectible, collectibles_found) ||
		floodfill(map, x, y - 1, target, exit, collectible, collectibles_found);
}
