#include "../include/so_long.h"

void ft_move(t_map *map, int delta_x, int delta_y) {
int x = map->player->instances[0].x += delta_x * TILE;
int y = map->player->instances[0].y += delta_y * TILE;

// if (map->map[x / TILE][y / TILE] == '1') {
//         map->player->instances[0].x = x;
//         map->player->instances[0].y = y;
//     }

}

// void ft_move(t_map *map, int delta_x, int delta_y) {
//     int x = map->player->instances[0].x + delta_x * TILE;
//     int y = map->player->instances[0].y + delta_y * TILE;

//     if (x / TILE >= 0 && x / TILE < map->width && y / TILE >= 0 && y / TILE < map->height) {
//         // if (map->map[x / TILE][y / TILE] != '1') {
//         //     map->player->instances[0].x = x;
//         //     map->player->instances[0].y = y;
//         // }
//     }
// }

/*
calculate new x and y
count movements
*/
