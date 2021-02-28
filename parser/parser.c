/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 16:47:50 by gmorra            #+#    #+#             */
/*   Updated: 2021/02/27 20:55:29 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static	void	check_map(t_struct *global)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (global->cub_map[i][j] == '1')
		j++;
	if (global->cub_map[i][j] != '\0')
	{
		ft_putstr("Error\nMap is not closed\n");
		exit(0);
	}
	j = ft_strlen(global->cub_map[0]) - 1;
	printf("eto j [%d]\n", j);
	while (global->cub_map[i][j] == '1' && i != global->map.map_num_y - 1)
		i++;
	i = 0;
	j = 0;
	while (global->cub_map[i][j] == '1' && i != global->map.map_num_y - 1)
		i++;
	while (global->cub_map[i][j] == '1')
		j++;
}

static	void	diff_pars(char *line, t_struct *global, int fd)
{
	if (ft_strnstr(line, "R"))
		pars_resolution(line, global);
	else if (ft_strnstr(line, "C"))
		pars_ceilling(line, global);
	else if (ft_strnstr(line, "F"))
		pars_floor(line, global);
	else if (ft_strnstr(line, "NO") || ft_strnstr(line, "SO") ||
	ft_strnstr(line, "WE") || ft_strnstr(line, "EA") || ft_strnstr(line, "S"))
		pars_textures(line, global);
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
	while (get_next_line(fd, &line) == 1)
		diff_pars(line, global, fd);
	check_map(global);
}
