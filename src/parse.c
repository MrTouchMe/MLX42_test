/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:57:30 by dgiurgev          #+#    #+#             */
/*   Updated: 2024/03/11 19:53:03 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void parse_map(char *file, t_map *map)
{
	// read in lenght and widh (map)
	// malloc map
	// map->map = malloc(map->width * map-height)
	// read map->map

	int fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}

	char *line;
	int height = 0;
	while ((line = get_next_line(fd /*, &line */)) > 0)
	{
		map->widh = ft_strlen(line);
		height++;
	}
	// free(line); // Don't forget the last line

	map->height = height;
	map->map = malloc((height + 1) * sizeof(char *));
	if (!map->map)
	{
		perror("Error allocating memory for map rows");
		exit(EXIT_FAILURE);
	}

	lseek(fd, 0, SEEK_SET); // Go back to the start of the file
	int i = 0;
	while ((line = get_next_line(fd /*, &line*/)) > 0)
	{
		map->map[i] = line; // Store the line in the map
		i++;
	}
	map->map[i] = line; // Don't forget the last line

	close(fd);
}
