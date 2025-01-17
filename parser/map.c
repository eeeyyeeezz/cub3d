/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:59:40 by gmorra            #+#    #+#             */
/*   Updated: 2021/03/14 12:50:12 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static	int		to_find_player(t_struct *global)
{
	int			i;
	int			a;
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
				global->map.pos_y = (float)a + 0.5;
				global->map.pos_x = (float)i + 0.5;
				global->map.is_player = global->cub_map[i][a];
				global->cub_map[i][a] = '0';
				num_player++;
			}
			a++;
		}
		i++;
	}
	return (num_player);
}

static	void	init_norme(t_struct *global, int num_player)
{
	sprite_parser_count(global);
	sprite_parser(global);
	if (global->map.is_player == '!' || num_player != 1)
		ft_error(13);
	if (global->map.map_to_pars != 8)
		ft_error(14);
}

void			pars_map(char *line, t_struct *global, int fd)
{
	int		br;
	char	*new_line;
	int		num_player;

	global->flag_map = 1;
	new_line = ft_strdup(line);
	new_line = ft_strjoin_new(new_line, "*");
	while (line[0] == '1' || line[0] == ' ' || line[0] == '0')
	{
		free(line);
		br = get_next_line(fd, &line);
		global->map.map_num_y++;
		new_line = ft_strjoin_new(new_line, line);
		new_line = ft_strjoin_new(new_line, "*");
	}
	if (br != 0)
		ft_error(16);
	if ((line[0] != '1' || line[0] != '0' || line[0] != ' ') && line[0] != '\0')
		ft_error(16);
	free(line);
	global->cub_map = ft_split(new_line, '*');
	free(new_line);
	num_player = to_find_player(global);
	init_norme(global, num_player);
}
