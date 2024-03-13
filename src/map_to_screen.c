/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:10:42 by dgiurgev          #+#    #+#             */
/*   Updated: 2024/03/12 16:47:33 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/so_long.h"

// void map_to_screen (t_map *map)
// {
// 	//paint floor
// 	//paint wall
// 	//player
// 	//colectible
// 	//exit
// }

void draw_floor(mlx_t *mlx, t_map *map, mlx_texture_t *texture) {
	texture->width = TILE;
	texture->height = TILE;
	// Convert texture to a displayable image
	mlx_image_t *img = mlx_texture_to_image(mlx, texture);
	if (!img)
		error();
	for (int y = 0; y < map->height; y++) {
		for (int x = 0; x < map->width; x++) {

			// Display the image at the tile's position
			if (mlx_image_to_window(mlx, img, x * TILE, y * TILE) < 0)
				error();
			// Delete the image after it has been drawn
			// mlx_delete_image(mlx, img);
		}
	}
}

void draw_wall(mlx_t *mlx, t_map *map, mlx_texture_t *texture) {
	texture->width = TILE;
	texture->height = TILE;
	// Convert texture to a displayable image
	mlx_image_t *img = mlx_texture_to_image(mlx, texture);
	if (!img)
		error();
	for (int y = 0; y < map->height; y++) {
		for (int x = 0; x < map->width; x++) {
			if(map->map[y][x] == '1') {
				// Display the image at the tile's position
				if (mlx_image_to_window(mlx, img, x * TILE, y * TILE) < 0)
					error();
			}
			// Delete the image after it has been drawn
			// mlx_delete_image(mlx, img);
		}
	}
}

void draw_exit(mlx_t *mlx, t_map *map, mlx_texture_t *texture) {
	texture->width = TILE;
	texture->height = TILE;
	// Convert texture to a displayable image
	mlx_image_t *img = mlx_texture_to_image(mlx, texture);
	if (!img)
		error();
	for (int y = 0; y < map->height; y++) {
		for (int x = 0; x < map->width; x++) {
			if(map->map[y][x] == 'E') {
				// Display the image at the tile's position
				if (mlx_image_to_window(mlx, img, x * TILE, y * TILE) < 0)
					error();
			}
			// Delete the image after it has been drawn
			// mlx_delete_image(mlx, img);
		}
	}
}

void draw_collectible(mlx_t *mlx, t_map *map, mlx_texture_t *texture) {
	texture->width = TILE;
	texture->height = TILE;
	// Convert texture to a displayable image
	mlx_image_t *img = mlx_texture_to_image(mlx, texture);
	if (!img)
		error();
	for (int y = 0; y < map->height; y++) {
		for (int x = 0; x < map->width; x++) {
			if(map->map[y][x] == 'C') {
				// Display the image at the tile's position
				if (mlx_image_to_window(mlx, img, x * TILE, y * TILE) < 0)
					error();
			}
			// Delete the image after it has been drawn
			// mlx_delete_image(mlx, img);
		}
	}
}

void draw_player(mlx_t *mlx, t_map *map, mlx_texture_t *texture) {
	texture->width = TILE;
	texture->height = TILE;
	// Convert texture to a displayable image
	mlx_image_t *img = mlx_texture_to_image(mlx, texture);
	if (!img)
		error();
	for (int y = 0; y < map->height; y++) {
		for (int x = 0; x < map->width; x++) {
			if(map->map[y][x] == 'P') {
				// Display the image at the tile's position
				if (mlx_image_to_window(mlx, img, x * TILE, y * TILE) < 0)
					error();
			}
			// Delete the image after it has been drawn
			// mlx_delete_image(mlx, img);
		}
	}
}
