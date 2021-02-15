/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 16:47:50 by gmorra            #+#    #+#             */
/*   Updated: 2021/02/15 17:04:58 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	map_without_pars(t_struct *global)
{
	int i;
	int a;

	i = 0;
	a = 0;
	global->cub_map = malloc((sizeof(char **) * 9) + 1);
	global->cub_map[0] = "111111111111111111111111111111";
	global->cub_map[1] = "100000000000011100000000000001";
	global->cub_map[2] = "10000W000000011100000000000001";
	global->cub_map[3] = "100000000000000000000000000001";
	global->cub_map[4] = "100110000000011110000011111001";
	global->cub_map[5] = "100110000000011110000011111001";
	global->cub_map[6] = "100000000000011110000011111001";
	global->cub_map[7] = "100000011111111111111111111111";
	global->cub_map[8] = "11111111                      ";
	global->cub_map[9] = NULL;
	for (int i = 0; global->cub_map[i] != NULL; i++)
		printf("eto TRUE mapa [%s]\n", global->cub_map[i]);
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

static	void	diff_pars(char *line, t_struct *global, int fd)
{
	if (ft_strnstr(line, "R"))
		pars_resolution(line, global);
	else if (ft_strnstr(line, "C"))
		pars_ceilling(line, global);
	else if (ft_strnstr(line, "F"))
		pars_floor(line, global);
	else if (ft_strnstr(line, "NO"))
		pars_north(line, global);
	else if (ft_strnstr(line, "SO"))
		pars_south(line, global);
	else if (ft_strnstr(line, "WE"))
		pars_west(line, global);
	else if (ft_strnstr(line, "EA"))
		pars_east(line, global);
	else if (ft_ft_strnstr(line, "1") || ft_ft_strnstr(line, "0"))
		pars_map(line, global, fd);
}

void		pars(t_struct *global, char **argv)
{
	int i;
	int fd;
	char *line;

	line = NULL;
	i = 0;
	fd = open(argv[1], O_RDONLY);
	map_without_pars(global);
	// while (get_next_line(fd, &line) == 1)
	// 	diff_pars(line, global, fd);
	printf("one [%f] two [%f]\n", global->map->position_x, global->map->position_y);
}
