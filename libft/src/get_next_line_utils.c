/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 20:33:28 by dgiurgev          #+#    #+#             */
/*   Updated: 2024/03/23 06:31:42 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_bzero_gnl(void *s, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n > 0)
	{
		*p = 0;
		p++;
		n--;
	}
}

void	*ft_calloc_gnl(size_t count, size_t size)
{
	size_t	total_size;
	void	*ptr;

	total_size = count * size;
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero_gnl(ptr, total_size);
	return (ptr);
}

int	ft_strlen_gnl(const char *s)
{
	int	length;

	length = 0;
	while (s && s[length] != '\0')
		length++;
	return (length);
}

char	*ft_strjoin_gnl(char *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*result;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	result = ft_calloc_gnl(ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1, 1);
	if (result == NULL)
		return (free(s1), NULL);
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		result[i] = s2[j];
		i++;
		j++;
	}
	return (free(s1), result);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)(s + i));
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)(s + i));
	return (NULL);
}
