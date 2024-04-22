/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:57:30 by dgiurgev          #+#    #+#             */
/*   Updated: 2024/04/22 22:04:36 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	open_file(char *file, int *fd)
{
	*fd = open(file, O_RDONLY);
	if (*fd < 0)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
}

void	calculate_map_dimensions(int fd, t_map *map)
{
	char	*line;
	int		height;

	height = 0;
	line = get_next_line(fd);
	while (line > 0)
	{
		map->width = ft_strlen(line) - 1;
		height++;
		line = get_next_line(fd);
	}
	map->height = height;
}

void	allocate_map_memory(t_map *map)
{
	map->map = malloc((map->height + 1) * sizeof(char *));
	if (!map->map)
	{
		perror("Error allocating memory for map rows");
		exit(EXIT_FAILURE);
	}
}

void	read_map_into_memory(int fd, t_map *map)
{
	char	*line;
	int		i;

	i = 0;
	lseek(fd, 0, SEEK_SET);
	line = get_next_line(fd);
	while (line != NULL)
	{
		map->map[i] = line;
		i++;
		line = get_next_line(fd);
	}
	map->map[i] = line;
}

int	parse_map(char *file, t_map *map)
{
	int	fd;

	file_extention(file);
	open_file(file, &fd);
	calculate_map_dimensions(fd, map);
	allocate_map_memory(map);
	read_map_into_memory(fd, map);
	close(fd);
	if (map->map[0] == NULL)
		return (1);
	return (0);
}
