/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceilling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 16:46:29 by gmorra            #+#    #+#             */
/*   Updated: 2021/01/25 14:41:49 by gmorra           ###   ########.fr       */
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
	while (ft_isspaces(line[i]) && line[i] != 'C' && line[i])
		i++;
	if (!ft_isspaces(line[i]) && line[i] != 'C')
			return (-1);
	if (line[i] == 'C' && line[i + 1] == 'C')
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
	// printf("here [%s]\n", line);
	while (ft_isspaces(line[i]) || line[i] == ',')
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

void			pars_ceilling(char *line, t_struct *global)
{
	static	int		times = 0;
	int				count;
	int				i;

	i = skip_spaces(line);
	count = check_count(line);
	times++;
	if (skip_spaces(line) != -1 && count == 3 && times == 1)
	{
		while (ft_isspaces(line[i + 1]) && line[i] != '\0')
			i++;
		if (line[i] != '\0')
			global->colors->r_cell = ft_atoi((char *)&line[i]);
		i += skip_digits((char *)&line[i + 1]);
		i += coma_and_space((char *)&line[i]);
		if (line[i] != '\0')
			global->colors->g_cell = ft_atoi((char *)&line[i]);
		i += skip_digits((char *)&line[i + 1]);
		i += coma_and_space((char *)&line[i]);
		if (line[i] != '\0')
			global->colors->b_cell = ft_atoi((char *)&line[i]);
	}
	else
	{
		ft_putstr("Error\nCeilling arguments wrong\n");
		exit(0);
	}
}
