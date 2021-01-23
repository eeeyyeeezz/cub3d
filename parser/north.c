/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   north.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 21:16:08 by gmorra            #+#    #+#             */
/*   Updated: 2021/01/23 20:14:26 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static int	check_error(char *line, t_struct *global)
{
	char *path;
	int fd;
	int i;

	path = global->textures->north;
	i = 0;
	fd = open(path, O_RDONLY);
	while (line[i] != ' ' && line[i])
		i++;
	while (line[i] == ' ' && line[i])
		i++;
	if (fd < 0 || line[i] != '\0')		// Error: North texture does not exist or more than 2 arguments
		return (0);
	return (1);
}

void		pars_textures(char *line, t_struct *global)
{
	int check;
	int i;

	check = 1;
	i = 0;
	if (ft_ft_strnstr(line, "./") && ft_strnstr(line, "NO"))
	{
		while (line[i] != '.')
			i++;
		global->textures->north = (char *)&line[i];
		check = check_error((char *)&line[i], global);
	}
	if (ft_ft_strnstr(line, "./") && ft_strnstr(line, "NO")
	&& !check)
	{
		ft_putstr("ERROR\nWrong north textures\n");
		exit(0);
	}
}

// ft_ft_strnstr(line, "/") && ft_strnstr(line, "NO")
