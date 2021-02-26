/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 16:47:50 by gmorra            #+#    #+#             */
/*   Updated: 2021/02/26 20:21:31 by gmorra           ###   ########.fr       */
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
	{
		// printf("line [%s] \n", line);
		diff_pars(line, global, fd);
	}
	// if (get_next_line(fd, &line) == 1)			// no
	// {
	// 	write(1, "\nMore than one empty line at the end\n", 37);
	// 	exit(0);
	// }
}
