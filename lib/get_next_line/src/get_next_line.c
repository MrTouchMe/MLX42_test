/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 20:32:43 by dgiurgev          #+#    #+#             */
/*   Updated: 2024/02/04 04:19:16 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

char	*ft_new(char *buffer)
{
	char	*new_buffer;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (free(buffer), NULL);
	new_buffer = ft_calloc_gnl(ft_strlen_gnl(buffer) - i + 1, sizeof(char));
	if (!new_buffer)
		return (free(buffer), NULL);
	i++;
	j = 0;
	while (buffer[i])
		new_buffer[j++] = buffer[i++];
	return (free(buffer), new_buffer);
}

char	*ft_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer[0])
		return (NULL);
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = ft_calloc_gnl(i + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*ft_read(int fd, char *buffer)
{
	char	tmp[BUFFER_SIZE + 1];
	int		bytes_read;

	bytes_read = 1;
	while (bytes_read)
	{
		bytes_read = read(fd, tmp, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		tmp[bytes_read] = '\0';
		buffer = ft_strjoin_gnl(buffer, tmp);
		if (!buffer)
			return (NULL);
		if (ft_strchr_gnl(buffer, '\n') || bytes_read < BUFFER_SIZE)
			break ;
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer[FD_SETSIZE];

	if (fd < 0 || fd >= FD_SETSIZE || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer[fd])
		buffer[fd] = ft_calloc_gnl(1, 1);
	if (!buffer[fd])
		return (NULL);
	if (read(fd, NULL, 0) < 0)
		return (free(buffer[fd]), buffer[fd] = NULL, NULL);
	buffer[fd] = ft_read(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_line(buffer[fd]);
	if (!line)
		return (free(buffer[fd]), buffer[fd] = NULL, NULL);
	buffer[fd] = ft_new(buffer[fd]);
	return (line);
}
