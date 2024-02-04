/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:24:52 by dgiurgev          #+#    #+#             */
/*   Updated: 2024/01/16 23:38:03 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
void	ft_parse(char conversion_specifier, va_list args, int *len);
void	ft_putchar_pf(char c, int *len);
void	ft_putstr_pf(char *str, int *len);
void	ft_putnbr_pf(long long int nbr, int base, char x, int *len);
void	ft_putnbr_ptr(size_t nbr, int base, int *len);
void	ft_putptr(size_t nbr, int base, int *len);
#endif
