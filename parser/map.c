/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:59:40 by gmorra            #+#    #+#             */
/*   Updated: 2021/02/15 17:08:15 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void		pars_map(char *line, t_struct *global, int fd)
{
	char *new_line;
	int i;
	int a;

	a = 0;
	i = 0;
	new_line = ft_strdup(line);
	new_line = ft_strjoin_new(new_line, "*");
	while (line[0] == '1' || line[0] == ' ')
	{
		free(line);
		get_next_line(fd, &line);
		new_line = ft_strjoin_new(new_line, line);
		new_line = ft_strjoin_new(new_line, "*");
	}
	free(line);
	global->cub_map = ft_split(new_line, '*');

	i = 0;
	while (global->cub_map[i])
	{
		a = 0;
		while (global->cub_map[i][a] != '\0')
		{
			if (global->cub_map[i][a] == 'N' || global->cub_map[i][a] == 'S' ||
			global->cub_map[i][a] == 'W' || global->cub_map[i][a] == 'E')
			{
				global->map->pos_y = i;
				global->map->pos_x = a;
			}
			a++;
		}
		i++;
	}
}


	// global->cub_map = malloc(sizeof(char **) * 9 + 1);
	// global->cub_map[0] = "111111111111111111111111111111";
	// global->cub_map[1] = "100000000000011100000000000001";
	// global->cub_map[2] = "10000W000000011100000000000001";
	// global->cub_map[3] = "100000000000000000000000000001";
	// global->cub_map[4] = "100110000000011110000011111001";
	// global->cub_map[5] = "100110000000011110000011111001";
	// global->cub_map[6] = "100000000000011110000011111001";
	// global->cub_map[7] = "100000011111111111111111111111";
	// global->cub_map[8] = "11111111                      ";
	// global->cub_map[9] = '\0';
	// for (int a = 0; i < 9; i++)
	// 	printf("eto TRUE mapa [%s]\n", global->cub_map[i]);
