/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 23:47:09 by dgiurgev          #+#    #+#             */
/*   Updated: 2024/03/23 00:09:14 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_hook(mlx_key_data_t keydata, void *param)
{
	t_map	*map;

	map = (t_map *)param;
	handle_escape_key(keydata, map);
	handle_w_key(keydata, map);
	handle_a_key(keydata, map);
	handle_s_key(keydata, map);
	handle_d_key(keydata, map);
}
