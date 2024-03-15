#include "../include/so_long.h"

void ft_move(t_map *map, int delta_x, int delta_y) {
	map->player->instances[0].x += delta_x *TILE;
	map->player->instances[0].y += delta_y * TILE;
}
