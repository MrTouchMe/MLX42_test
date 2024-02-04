/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 06:05:08 by dgiurgev          #+#    #+#             */
/*   Updated: 2024/02/04 05:24:14 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	write(fd, s, len);
	write(fd, "\n", 1);
}
