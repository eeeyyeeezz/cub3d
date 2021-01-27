/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:59:40 by gmorra            #+#    #+#             */
/*   Updated: 2021/01/27 20:26:41 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void		pars_map(char *line, t_struct *global, int fd)
{
	char *new_line;
	int i;
	int a;

	a = 0;
	i = -1;
	new_line = line;
	new_line = ft_strjoin(new_line, "*");
	while (get_next_line(fd, &line))
	{
		new_line = ft_strjoin(new_line, line);
		new_line = ft_strjoin(new_line, "*");
	}
	// printf("eto line\n %s \n", new_line);
	global->cub_map = ft_split(new_line, '*');
	// while (global->cub_map[++i] != '\0')
		// printf("eto mapa [%s]\n", global->cub_map[i]);
	i = 0;
	while (global->cub_map[i])
	{
		a = 0;
		while (global->cub_map[i][a] != '\0')
		{
			if (global->cub_map[i][a] == 'N' || global->cub_map[i][a] == 'S' ||
			global->cub_map[i][a] == 'W' || global->cub_map[i][a] == 'E')
			{
				global->map->position_y = i;
				global->map->position_x = a;
			}
			a++;
		}
		i++;
	}
}
