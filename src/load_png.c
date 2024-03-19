#include "../include/so_long.h"

void load_png(mlx_t mlx, t_map *map) {
	mlx_texture_t *texture;
	mlx_texture_t *player;

	texture = NULL;
	player = NULL;
	texture = mlx_load_png("./images/floor.png");
	if (!texture)
		error();
	draw_floor(&mlx, map, texture);
	texture = mlx_load_png("./images/wall.png");
	if (!texture)
		error();
	draw_wall(&mlx, map, texture);
	texture = mlx_load_png("./images/exit.png");
	if (!texture)
		error();
	draw_exit(&mlx, map, texture);
	player = mlx_load_png("./images/player.png");
	if (!player)
		error();
	draw_player(&mlx, map, player);
	texture = mlx_load_png("./images/key.png");
	if (!texture)
		error();
	draw_collectible(&mlx, map, texture);
	mlx_delete_texture(texture);
}
