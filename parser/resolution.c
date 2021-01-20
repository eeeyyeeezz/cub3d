/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 16:16:29 by gmorra            #+#    #+#             */
/*   Updated: 2021/01/20 18:28:46 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int		skip_digits(char *line)
{
	int i;

	i = 0;
	while (ft_isdigit(line[i]))
		i++;
	return (i);
}

static int	 	skip_spaces(char *line)
{
	int i;

	i = 0;
	while (line[i] == ' ' && line[i] != 'R' && line[i])
		i++;
	if (line[i] != ' ' && line[i] != 'R')
			return (-1);
	else
		return (i);
}

static int		check_count(char *line)
{
	int count;

	count = 0;




	return (count);
}

static void		pars_resolution(char *line, t_struct *global)
{
	int count;
	int i;

	i = skip_spaces(line);
	count = check_count(line);
	// printf("skip_spaces [%d]\n", skip_spaces(line));
	if (skip_spaces(line) != -1 && ft_strchr(line, 'R') && count == 2)
	{
		while (!(ft_isdigit(line[i]) && line[i] != '\0'))
			i++;
		if (line[i] != '\0')
			global->map->width = ft_atoi((char *)&line[i]);
		i += skip_digits((char *)&line[i]) + 1;
		if (line[i] != '\0')
			global->map->height = ft_atoi((char *)&line[i]);
	}
	else if ((skip_spaces(line) == -1 && ft_strchr(line, 'R'))
	|| (ft_strchr(line, 'R') && count != 2))
	{
		write(1, "ERROR\n", 6);
		exit(0);
	}
}

void		pars(t_struct *global, char *line)
{
	int i;
	global->map->width = 0;
	global->map->height = 0;

	i = 0;
	pars_resolution(line, global);
}
