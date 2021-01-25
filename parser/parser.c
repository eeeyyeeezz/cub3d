/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 16:47:50 by gmorra            #+#    #+#             */
/*   Updated: 2021/01/25 20:37:27 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

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
	while (get_next_line(fd, &line) == 1)
	{
		printf("line [%s] \n", line);
		diff_pars(line, global, fd);
	}

}
