/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 23:47:25 by dgiurgev          #+#    #+#             */
/*   Updated: 2024/04/01 13:53:15 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_move(t_map *map, int delta_x, int delta_y)
{
	map->player->instances[0].x += delta_x * TILE;
	map->player->instances[0].y += delta_y * TILE;
}
