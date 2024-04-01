/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:57:30 by dgiurgev          #+#    #+#             */
/*   Updated: 2024/04/01 17:26:21 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	parse_map(char *file, t_map *map)
{
	int		fd;
	char	*line;
	int		height;
	int		i;

	fd = open(file, O_RDONLY);
	height = 0;
	i = 0;
	if (fd < 0)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
	while ((line = get_next_line(fd)) > 0)
	{
		map->width = ft_strlen(line) - 1;
		height++;
	}
	map->height = height;
	map->map = malloc((height + 1) * sizeof(char *));
	if (!map->map)
	{
		perror("Error allocating memory for map rows");
		exit(EXIT_FAILURE);
	}
	lseek(fd, 0, SEEK_SET);
	while ((line = get_next_line(fd)) > 0)
	{
		map->map[i] = line;
		i++;
	}
	map->map[i] = line;
	close(fd);
}

	// lseek(fd, 0, SEEK_SET); // Go back to the start of the file
	// map->map[i] = line; // Don't forget the last line
	// map->map[i] = line; // Store the line in the map
