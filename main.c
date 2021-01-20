/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 13:52:43 by gmorra            #+#    #+#             */
/*   Updated: 2021/01/20 17:02:04 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			main(void)
{
	int fd;
	char *line;
	t_struct	global;
	t_map_res 	map_res;
	t_colors	colors;

	global.map = &map_res;
	global.colors = &colors;
	fd = open("map.cub", O_RDONLY);
	get_next_line(fd, &line);
	pars(&global, line);
	// printf("line %s \n", line);
	printf("width %d height %d\n", global.map->width, global.map->height);
}
