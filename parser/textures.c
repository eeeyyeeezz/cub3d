/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 21:16:08 by gmorra            #+#    #+#             */
/*   Updated: 2021/01/25 16:53:32 by gmorra           ###   ########.fr       */
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
	// printf("eto path [%s] a eto fd [%d]\n", path, fd);
	// while (line[i])
	// {
	// 	while (ft_isspaces(line[i]) && line[i] )
	// 		i++;
	// 	if (count == 0)
	// 		i += ft_isalpha(line[i]) + 1;
	// 	while (ft_isspaces(line[i]) && line[i])
	// 		i++;
	// 	while (ft_isalpha(line[i]) || line[i] == '.' || line[i] == '/')
	// 		i++;
	// 	if (line[i] != '\0')
	// 		count++;
	// }
	// printf("eto count [%d]\n", count);
	if (fd < 0)		// Error: Texture does not exist or more than 2 arguments
		return (0);
	return (1);
}

void			pars_north_south(char *line, t_struct *global)
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
		check = check_error(line, global);
	}
	if (ft_ft_strnstr(line, "./") && ft_strnstr(line, "SO"))
	{
		while (line[i] != '.')
			i++;
		global->textures->south = (char *)&line[i];
		check = check_error(line, global);
	}
	if (ft_ft_strnstr(line, "./") && (ft_strnstr(line, "NO") || ft_strnstr(line, "SO")) && !check)
	{
		// printf("a eto check [%d]\n", check);
		ft_putstr("ERROR\nWrong north or south textures\n");
		exit(0);
	}
}

void		pars_west_east(char *line, t_struct *global)
{
	int check;
	int i;

	check = 1;
	i = 0;
	if (ft_ft_strnstr(line, "./") && ft_strnstr(line, "WE"))
	{
		while (line[i] != '.')
			i++;
		global->textures->west = (char *)&line[i];
		check = check_error(line, global);
	}
	if (ft_ft_strnstr(line, "./") && ft_strnstr(line, "EA"))
	{
		while (line[i] != '.')
			i++;
		global->textures->east = (char *)&line[i];
		check = check_error(line, global);
	}
	else if (ft_ft_strnstr(line, "./") && (ft_strnstr(line, "WE") || ft_strnstr(line, "EA"))
	&& !check)
	{
		ft_putstr("ERROR\nWrong west or east textures\n");
		exit(0);
	}

}
