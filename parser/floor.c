/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 19:41:33 by gmorra            #+#    #+#             */
/*   Updated: 2021/01/22 20:09:19 by gmorra           ###   ########.fr       */
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
	while (line[i] == ' ' && line[i] != 'F' && line[i])
		i++;
	if (line[i] != ' ' && line[i] != 'F')
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
	// printf("eto count [%d]\n", count);
	return (count);
}

void		pars_floor(char *line, t_struct *global)
{
	int count;
	int i;

	i = skip_spaces(line);
	count = check_count(line);
	global->colors->r_floor = 0;
	global->colors->g_floor = 0;
	global->colors->b_floor = 0;
	if (skip_spaces(line) != -1 && count == 3)
	{
		while (!(ft_isdigit(line[i]) && line[i] != '\0'))
			i++;
		if (line[i] != '\0')
			global->colors->r_floor = ft_atoi((char *)&line[i]);
		i += skip_digits((char *)&line[i]) + 1;
		if (line[i] != '\0')
			global->colors->g_floor = ft_atoi((char *)&line[i]);
		i += skip_digits((char *)&line[i]) + 1;
		if (line[i] != '\0')
			global->colors->b_floor = ft_atoi((char *)&line[i]);
	}
	else
	{
		write(1, "ERROR\nVvedi normalno argumenty pops\n", 36);
		exit(0);
	}
}
