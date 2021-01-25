/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 21:16:08 by gmorra            #+#    #+#             */
/*   Updated: 2021/01/25 20:35:38 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static char			*get_path(char *line, t_struct *global)
{
	char *path;

	if (ft_ft_strnstr(line, "./") && ft_strnstr(line, "NO"))
		path = global->textures->north;
	if (ft_ft_strnstr(line, "./") && ft_strnstr(line, "SO"))
		path = global->textures->south;
	if (ft_ft_strnstr(line, "./") && ft_strnstr(line, "WE"))
		path = global->textures->west;
	if (ft_ft_strnstr(line, "./") && ft_strnstr(line, "EA"))
		path = global->textures->east;
	return (path);
}

static int			check_error(char *line, t_struct *global)
{
	char *path;
	int count;
	int fd;
	int i;

	i = 0;
	count = 0;
	path = get_path(line, global);
	fd = open(path, O_RDONLY);
	if (fd < 0)		// Error: Texture does not exist or more than 2 arguments
		return (0);
	return (1);
}

void			pars_north(char *line, t_struct *global)
{
	static int 	times = 0;
	int 		check;
	int 		i;

	i = 0;
	times++;
	check = 1;
	if (times == 1)
	{
		while (line[i] != '.')
			i++;
		global->textures->north = (char *)&line[i];
		check = check_error(line, global);
	}
	else if (ft_ft_strnstr(line, "./") && ft_strnstr(line, "NO") && (!check || times != 1))
	{
		ft_putstr("ERROR\nWrong north textures\n");
		exit(0);
	}
}

void			pars_south(char *line, t_struct *global)
{
	static int 	times = 0;
	int 		check;
	int 		i;

	i = 0;
	times++;
	check = 1;
	if (times == 1)
	{
		while (line[i] != '.')
			i++;
		global->textures->south = (char *)&line[i];
		check = check_error(line, global);
	}
	else if (!check || times != 1)
	{
		ft_putstr("ERROR\nWrong south textures\n");
		exit(0);
	}
}

void		pars_west(char *line, t_struct *global)
{
	static int 	times = 0;
	int 		check;
	int 		i;

	i = 0;
	times++;
	check = 1;
	if (times == 1)
	{
		while (line[i] != '.')
			i++;
		global->textures->west = (char *)&line[i];
		check = check_error(line, global);
	}
	if (!check || times != 1)
	{
		ft_putstr("ERROR\nWrong west textures\n");
		exit(0);
	}
}

void			pars_east(char *line, t_struct *global)
{
	static int 	times = 0;
	int 		check;
	int 		i;

	i = 0;
	times++;
	check = 1;
	if (check && times == 1)
	{
		while (line[i] != '.')
			i++;
		global->textures->east = (char *)&line[i];
		check = check_error(line, global);
	}
	else if (!check || times != 1)
	{
		ft_putstr("ERROR\nWrong east textures\n");
		exit(0);
	}
}
