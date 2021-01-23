/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 19:41:33 by gmorra            #+#    #+#             */
/*   Updated: 2021/01/23 18:43:58 by gmorra           ###   ########.fr       */
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
	if (line[i] == 'C' && line[i + 1] == 'F')
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

static int		coma_and_space(char *line)
{
	int i;
	int coma;

	i = 1;
	coma = 0;
	while (line[i] == ' ' || line[i] == ',')
	{
		if (line[i] == ',')
			coma++;
		i++;
	}
	if (coma != 1)
	{
		ft_putstr("ERROR\nMore/less commas that required\n");
		exit(0);
	}
	return (i);
}

void			pars_floor(char *line, t_struct *global)
{
	static	int		times = 0;
	int				count;
	int				i;

	i = skip_spaces(line);
	count = check_count(line);
	times++;
	if (skip_spaces(line) != -1 && count == 3 && times == 1)
	{
		while (line[i + 1] == ' ' && line[i] != '\0')
			i++;
		if (line[i] != '\0')
			global->colors->r_floor = ft_atoi((char *)&line[i]);
		i += skip_digits((char *)&line[i + 1]);
		i += coma_and_space((char *)&line[i]);
		if (line[i] != '\0')
			global->colors->g_floor = ft_atoi((char *)&line[i]);
		i += skip_digits((char *)&line[i + 1]);
		i += coma_and_space((char *)&line[i]);
		if (line[i] != '\0')
			global->colors->b_floor = ft_atoi((char *)&line[i]);
	}
	else
	{
		ft_putstr("Error\nFloor arguments wrong\n");
		exit(0);
	}
}
