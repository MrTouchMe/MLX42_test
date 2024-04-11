/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 20:38:56 by dgiurgev          #+#    #+#             */
/*   Updated: 2024/04/11 17:40:29 by dgiurgev         ###   ########.fr       */
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

int	file_extention(char *file)
{
	const char	*dot_pos = ft_strnstr(file, ".", ft_strlen(file));

	if (dot_pos == NULL || *(dot_pos +1) != 'b' || *(dot_pos +2) != 'e'
		|| *(dot_pos +3) != 'r' || *(dot_pos +4) != '\0')
	{
		ft_printf("map should be a '.ber' file!\n");
		exit(1);
	}
	else
		return (0);
}
