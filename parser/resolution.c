/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 16:16:29 by gmorra            #+#    #+#             */
/*   Updated: 2021/01/25 14:40:51 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

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
	while (ft_isspaces(line[i]) && line[i] != 'R' && line[i])
		i++;
	if (!ft_isspaces(line[i]) && line[i] != 'R')	// && line[i] ?
			return (-1);
	else
		return (i);
}

static int		check_count(char *line)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (line[i] != '\0')
	{
		while (!ft_isdigit(line[i]) && line[i] != '\0')
			i++;
		if (line[i] != '\0')
			count++;
		while (ft_isdigit(line[i]))
			i++;
	}
	return (count);
}

void		pars_resolution(char *line, t_struct *global)
{
	static	int		times = 0;
	int 			count;
	int 			i;

	i = skip_spaces(line);
	count = check_count(line);
	times++;
	if (skip_spaces(line) != -1 && count == 2 && times == 1)
	{
		while (ft_isspaces(line[i + 1]) && line[i] != '\0')
			i++;
		if (line[i] != '\0')
			global->map->width = ft_atoi((char *)&line[i]);
		i += skip_digits((char *)&line[i]) + 1;
		if (line[i] != '\0')
			global->map->height = ft_atoi((char *)&line[i]);
	}
	else
	{
		ft_putstr("ERROR\nWrong resolution arguments\n");
		exit(0);
	}
}
