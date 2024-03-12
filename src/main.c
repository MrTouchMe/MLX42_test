/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:01:27 by dgiurgev          #+#    #+#             */
/*   Updated: 2024/03/11 19:51:40 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void error(void) {
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int32_t main(int argc, char **argv) {
	t_map map;
	mlx_t *mlx;
	mlx_texture_t *texture;
	// mlx_image_t *img;

	if (argc == 1) {
		write(1, "Usage so_long map\n", 18);
		exit(0);
	}
	parse_map(argv[1], &map);
	// Start mlx
	int window_width = map.width * TILE;
	int window_height = map.height * TILE;
	mlx = mlx_init(window_width, window_height, "so_long", true);
	// map to screen
	if (!mlx)
		error();
	// Try to load the file
	// texture = mlx_load_png("./images/menu_bg.png");
	texture = mlx_load_png("./images/floor.png");
	if (!texture)
		error();
	draw_floor(mlx, &map, texture);
	texture = mlx_load_png("./images/wall.png");
	if (!texture)
		error();
	draw_wall(mlx, &map, texture);
	texture = mlx_load_png("./images/exit.png");
	if (!texture)
		error();
	draw_exit(mlx, &map, texture);
	// Convert texture to a displayable image
	// img = mlx_texture_to_image(mlx, texture);
	// if (!img)
		// error();
	// Display the image
	// if (mlx_image_to_window(mlx, img, 0, 0) < 0)
		// error();
	// register loophooks
	mlx_loop(mlx);
	// mlx_delete_image(mlx, img);
	mlx_delete_texture(texture);
	// Optional, terminate will clean up any leftover images (not textures!)
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
