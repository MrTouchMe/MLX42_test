/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 07:53:56 by dgiurgev          #+#    #+#             */
/*   Updated: 2024/02/04 05:24:51 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*dup;

	len = ft_strlen(s1);
	dup = malloc(len + 1);
	if (dup == NULL)
		return (NULL);
	ft_memcpy(dup, s1, len);
	dup[len] = '\0';
	return ((char *)dup);
}
