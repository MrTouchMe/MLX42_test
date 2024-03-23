/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 05:35:20 by dgiurgev          #+#    #+#             */
/*   Updated: 2024/02/04 05:20:49 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_itoa(int n)
{
	int		sign;
	int		numdigits;
	long	lin;
	char	*result;

	sign = -1 * (n < 0);
	numdigits = (n < 0) * 1;
	lin = (-2 * ((long)n < 0) * (long)n) + (long)n;
	while (numdigits++, lin >= 10)
		lin /= 10;
	result = (char *)malloc((numdigits + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	lin = (-2 * ((long)n < 0) * (long)n) + (long)n;
	result[numdigits] = '\0';
	while (lin >= 10)
	{
		result[--numdigits] = (lin % 10) + '0';
		lin /= 10;
	}
	result[--numdigits] = lin + '0';
	if (sign == -1)
		result[0] = '-';
	return (result);
}
