/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:00:57 by dgiurgev          #+#    #+#             */
/*   Updated: 2024/03/23 06:31:11 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_parse(char conversion_specifier, va_list args, int *len)
{
	if (conversion_specifier == 'c')
		ft_putchar_pf(va_arg(args, int), len);
	else if (conversion_specifier == 's')
		ft_putstr_pf(va_arg(args, char *), len);
	else if (conversion_specifier == 'd')
		ft_putnbr_pf((long long int)va_arg(args, int), 10, 'x', len);
	else if (conversion_specifier == 'i')
		ft_putnbr_pf((long long int)va_arg(args, int), 10, 'x', len);
	else if (conversion_specifier == 'u')
		ft_putnbr_pf((long long int)va_arg(args, unsigned int), 10, 'x', len);
	else if (conversion_specifier == 'p')
		ft_putptr((long long int)va_arg(args, size_t), 16, len);
	else if (conversion_specifier == 'x')
		ft_putnbr_pf((long long int)va_arg(args, unsigned int), 16, 'x', len);
	else if (conversion_specifier == 'X')
		ft_putnbr_pf((long long int)va_arg(args, unsigned int), 16, 'X', len);
	else if (conversion_specifier != 'c' || conversion_specifier != 's'
		|| conversion_specifier != 'd' || conversion_specifier != 'i'
		|| conversion_specifier != 'u' || conversion_specifier != 'p'
		|| conversion_specifier != 'x' || conversion_specifier != 'X')
		ft_putchar_pf(conversion_specifier, len);
}
