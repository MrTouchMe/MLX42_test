/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 20:38:56 by dgiurgev          #+#    #+#             */
/*   Updated: 2024/04/09 13:26:59 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	skill_issue(t_map *map)
{
	ft_printf("skill issue\n");
	mlx_close_window(map->mlx);
}

void	ggez(t_map *map)
{
	ft_printf("you win!\n");
	mlx_close_window(map->mlx);
}

void	esc_exit(t_map *map)
{
	ft_printf("game closed by user\n");
	mlx_close_window(map->mlx);
}
