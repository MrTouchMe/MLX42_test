/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:01:27 by dgiurgev          #+#    #+#             */
/*   Updated: 2024/04/01 14:40:33 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int32_t	main(int argc, char **argv)
{
	t_map	map;
	mlx_t	*mlx;

	if (argc == 1)
	{
		write(1, "Usage so_long map\n", 18);
		exit(0);
	}
	parse_map(argv[1], &map);
	map_checker(&map);
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	mlx = mlx_init((map.width * TILE), (map.height * TILE), "so_long", true);
	mlx_set_window_size(mlx, mlx->width * 5, mlx->height * 5);
	map.mlx = mlx;
	if (!mlx)
		error();
	load_png(*mlx, &map);
	map.movements = 0;
	mlx_key_hook(mlx, ft_hook, &map);
	mlx_put_string(mlx, "so-long", 0, 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
