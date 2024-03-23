/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions_printf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:37:39 by dgiurgev          #+#    #+#             */
/*   Updated: 2024/03/23 06:30:48 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_putchar_pf(char c, int *len)
{
	int	temp;

	temp = write(1, &c, 1);
	if (temp == -1)
		*len = -1;
	else
		*len += temp;
}

void	ft_putstr_pf(char *str, int *len)
{
	if (!str)
		str = "(null)";
	while (*str)
	{
		ft_putchar_pf(*str++, len);
		if (*len == -1)
			return ;
	}
}

void	ft_putptr(size_t nbr, int base, int *len)
{
	ft_putstr_pf("0x", len);
	if (*len == -1)
		return ;
	ft_putnbr_ptr(nbr, base, len);
}

void	ft_putnbr_pf(long long int nbr, int base, char x, int *len)
{
	const char	*hex = {"0123456789abcdef"};
	const char	*hex_b = {"0123456789ABCDEF"};

	if (nbr < 0)
	{
		ft_putchar_pf('-', len);
		if (*len == -1)
			return ;
		nbr = -nbr;
	}
	if (nbr >= base)
		ft_putnbr_pf(nbr / base, base, x, len);
	if (*len == -1)
		return ;
	if (x == 'X')
		ft_putchar_pf(hex_b[nbr % base], len);
	else
		ft_putchar_pf(hex[nbr % base], len);
}

void	ft_putnbr_ptr(size_t nbr, int base, int *len)
{
	const char	*hex = {"0123456789abcdef"};

	if (nbr >= (size_t)base)
		ft_putnbr_ptr(nbr / base, base, len);
	ft_putchar_pf(hex[nbr % base], len);
}
