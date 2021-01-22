/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 13:52:43 by gmorra            #+#    #+#             */
/*   Updated: 2021/01/22 17:31:43 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			main(int argc, char **argv)
{
	int i;
	int fd;
	char *line;
	t_struct	global;
	t_map_res 	map_res;
	t_colors	colors;

	(void)argc;
	i = 0;
	global.map = &map_res;
	global.colors = &colors;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line))
	{
		printf("line [%s] \n", line);
		pars(&global, line);
		i++;
		if (i == 2)
			break ;
	}
	printf("\nwidth [%d] height [%d]\n", global.map->width, global.map->height);
	printf("r_cell [%d] g_cell [%d] b_cell [%d]\n", global.colors->r_cell, global.colors->g_cell, global.colors->b_cell);
}
