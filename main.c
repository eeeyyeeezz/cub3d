/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 13:52:43 by gmorra            #+#    #+#             */
/*   Updated: 2021/01/19 20:17:43 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		pars(t_map *map, t_colors *colors)
{
	int i;
	int fd;
	char *line;
	// map = map_coord;
	map->width = 0;
	map->height = 0;
	colors->r_floor = 0;
	colors->g_floor = 0;
	colors->b_floor = 0;
	colors->r_cell = 0;
	colors->g_cell = 0;
	colors->b_cell = 0;


	i = 0;
	line = NULL;
	fd = open("map.cub", O_RDONLY);
	while(get_next_line(fd, &line))
	{
		if (line[0] == 'R')
		{
			while (!(ft_isdigit(line[i])))
				i++;
			map->width = ft_atoi((char *)&line[i]);
			i++;
			while (!(ft_isdigit(line[i])))
				i++;
			map->height = ft_atoi((char *)&line[i]);
			i = 0;
		}
		else if (line[0] == 'S')
		{
			while (!(ft_isdigit(line[i])))
				i++;
			colors->r_cell = ft_atoi((char *)&line[i]);
			while (ft_isdigit(line[i]))
				i++;
			i++;
			colors->g_cell = ft_atoi((char *)&line[i]);
			while (ft_isdigit(line[i]))
				i++;
			i++;
			colors->b_cell = ft_atoi((char *)&line[i]);
		}
	}

	// printf("line %s \n", line);
}

int			main(void)
{
	t_map 		map;
	t_colors	colors;

	pars(&map, &colors);
	printf("width %d height %d\nfloor colors %d %d %d\ncelling colors %d %d %d\n", map.width, map.height,
	colors.r_floor, colors.g_floor, colors.b_floor, colors.r_cell, colors.g_cell, colors.b_cell);
}
