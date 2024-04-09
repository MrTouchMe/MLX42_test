/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:01:27 by dgiurgev          #+#    #+#             */
/*   Updated: 2024/04/09 16:30:46 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	error(void)
{
	ft_printf("%s\n", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	free_map(t_map *map)
{
	if (map->map != NULL)
		free(map->map);
}

void	init_vars(t_map *map)
{
	map->map = NULL;
	map->mlx = NULL;
	map->counter = NULL;
	map->movements = 0;
	map->player_frame = 0;
}

void	ft_animation(void *param)
{
	static int	slower = 0;
	int			i;
	t_map		*map;

	map = (t_map *)param;
	i = 0;
	if (++slower > 4)
	{
		slower = 0;
		while (i < 5)
		{
			if (map->player_frame == i)
				map->player[i]->enabled = true;
			else
				map->player[i]->enabled = false;
			i++;
		}
		map->player_frame++;
		if (map->player_frame >= 5)
			map->player_frame = 0;
	}
}

int32_t	main(int argc, char **argv)
{
	t_map	map;

	if (argc == 1)
	{
		write(1, "Usage so_long map\n", 18);
		return (1);
	}
	if (parse_map(argv[1], &map))
		return (free_map(&map), 1);
	if (map_checker(&map))
		return (free_map(&map), 1);
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	map.mlx = mlx_init((map.width * TILE), (map.height * TILE),
			"so_long", true);
	if (map.mlx == NULL)
		return (free_map(&map), 1);
	mlx_set_window_pos(map.mlx, 0, 0);
	mlx_set_window_size(map.mlx, map.mlx->width * 5, map.mlx->height * 5);
	load_png(*map.mlx, &map);
	mlx_key_hook(map.mlx, ft_hook, &map);
	mlx_loop_hook(map.mlx, ft_animation, &map);
	mlx_loop(map.mlx);
	mlx_terminate(map.mlx);
	return (EXIT_SUCCESS);
}
