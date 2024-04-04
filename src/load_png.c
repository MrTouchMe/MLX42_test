/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_png.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 23:47:37 by dgiurgev          #+#    #+#             */
/*   Updated: 2024/04/04 16:03:51 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	load_png(mlx_t mlx, t_map *map)
{
	load_floor(mlx, map);
	load_wall(mlx, map);
	load_exit(mlx, map);
	load_collectible(mlx, map);
	load_player(mlx, map);
}
