/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 20:38:56 by dgiurgev          #+#    #+#             */
/*   Updated: 2024/04/07 21:57:55 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	skill_issue(t_map *map)
{
	ft_printf("skill issue\n");
	mlx_terminate(map->mlx);
	mlx_close_window(map->mlx);
}

void	ggez(t_map *map)
{
	ft_printf("you win!\n");
	mlx_terminate(map->mlx);
	mlx_close_window(map->mlx);
}

void	esc_exit(t_map *map)
{
	ft_printf("game closed by user\n");
	mlx_terminate(map->mlx);
	mlx_close_window(map->mlx);
}
