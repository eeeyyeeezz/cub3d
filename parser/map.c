/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:59:40 by gmorra            #+#    #+#             */
/*   Updated: 2021/02/19 19:03:24 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static	int		to_find_player(t_struct *global)
{
	int 		i;
	int 		a;
	static	int num_player = 0;

	i = 0;
	while (global->cub_map[i])
	{
		a = 0;
		while (global->cub_map[i][a] != '\0')
		{
			if (global->cub_map[i][a] == 'N' || global->cub_map[i][a] == 'S' ||
			global->cub_map[i][a] == 'W' || global->cub_map[i][a] == 'E')
			{
				global->map.pos_y = i;
				global->map.pos_x = a;
				num_player++;
				global->map.is_player = global->cub_map[i][a];
			}
			a++;
		}
		i++;
	}
	return(num_player);
}


void		pars_map(char *line, t_struct *global, int fd)
{
	char *new_line;
	int num_player;

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
	num_player = to_find_player(global);
	if (global->map.is_player == '!' || num_player != 1)
	{
		write(1, "No player is on map or too many\n", 32);
		exit(0);
	}
}
