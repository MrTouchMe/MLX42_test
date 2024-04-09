/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 22:09:52 by dgiurgev          #+#    #+#             */
/*   Updated: 2024/04/09 16:29:35 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_check(t_check *check)
{
	int	i;

	i = 0;
	while (check->cpy[i] != NULL)
	{
		free(check->cpy[i]);
		i++;
	}
	free(check->cpy);
}
