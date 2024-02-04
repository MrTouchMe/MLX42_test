/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 20:33:12 by dgiurgev          #+#    #+#             */
/*   Updated: 2024/01/15 19:02:07 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# ifndef FD_SETSIZE
#  define FD_SETSIZE 1024
# endif
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
void	*ft_calloc_gnl(size_t count, size_t size);
char	*ft_strjoin_gnl(char *s1, char const *s2);
char	*ft_strchr_gnl(const char *s, int c);
int		ft_strlen_gnl(const char *s);
void	ft_bzero_gnl(void *s, size_t n);
#endif
