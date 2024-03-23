/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 05:34:21 by dgiurgev          #+#    #+#             */
/*   Updated: 2024/02/04 05:25:45 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

// char	*ft_strtrim(char const *s1, char const *set)
// {
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	j = ft_strlen(s1);
// 	while (s1[i] && ft_strchr(set, s1[i]))
// 		i++;
// 	while (j > i && ft_strchr(set, s1[j]))
// 		j--;
// 	return (ft_substr(s1, i, j));
// }

static int	is_in_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_strlen(s1);
	while (is_in_set(s1[i], set))
		i++;
	if (i == j)
		return (ft_strdup(""));
	while (is_in_set(s1[j - 1], set))
		j--;
	return (ft_substr(s1, i, j - i));
}
