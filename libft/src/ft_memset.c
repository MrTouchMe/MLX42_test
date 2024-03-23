/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:44:43 by dgiurgev          #+#    #+#             */
/*   Updated: 2024/02/04 05:22:29 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;
	unsigned char	value;

	p = (unsigned char *)b;
	value = (unsigned char)c;
	while (len > 0)
	{
		*p = value;
		p++;
		len--;
	}
	return (b);
}
