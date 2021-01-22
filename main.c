/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 13:52:43 by gmorra            #+#    #+#             */
/*   Updated: 2021/01/22 22:04:28 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int			main(int argc, char **argv)
{
	int i;
	int fd;
	char *line;
	t_struct	global;
	t_map_res 	map_res;
	t_colors	colors;
	t_textures	texures;

	(void)argc;
	i = 0;
	global.map = &map_res;
	global.colors = &colors;
	global.textures = &texures;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		printf("line [%s] \n", line);
		pars(&global, line);
		i++;
		if (i == 4)
			break ;
	}
	// pars(&global, line_two);
	printf("\nwidth [%d] height [%d]\n", global.map->width, global.map->height);
	printf("r_cell [%d] g_cell [%d] b_cell [%d]\n", global.colors->r_cell, global.colors->g_cell, global.colors->b_cell);
	printf("r_floor [%d] g_floor [%d] b_floor [%d]\n", global.colors->r_floor, global.colors->g_floor, global.colors->b_floor);
	printf("North [%s]\n", global.textures->north);
	// printf("check C [%d]\n", ft_strchr("  C    255,150,75", 'C'));
	// printf("check F [%d]\n", ft_strchr("  F    350,250,100", 'F'));
}


/*
1)	Добавить фейл на "F  200,  100,  50" пробелы после запятых
2)	Фейл на < 0 && >255
3)	Strnstr возможен фейл с поднятием флага
*/
