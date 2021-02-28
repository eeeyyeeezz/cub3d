/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 19:41:33 by gmorra            #+#    #+#             */
/*   Updated: 2021/02/28 13:20:05 by gmorra           ###   ########.fr       */
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
	while (line[i] == ',')
	{
		coma++;
		i++;
	}
	if (coma != 1 || (line[i] != ',' && !(ft_isdigit(line[i]))))
		ft_error(5);
	return (i);
}

void			pars_floor(char *line, t_struct *global)
{
	static	int		times = 0;
	int				count;
	int				i;

	i = 1;
	times++;
	global->map.map_to_pars++;
	count = check_count(line);
	if (count == 3 && times == 1 && line[0] == 'F')
	{
		while (ft_isspaces(line[i + 1]) && line[i] != '\0')
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
		ft_error(6);
	if (global->colors->r_floor < 0 || global->colors->r_floor > 255 ||
	global->colors->g_floor < 0 || global->colors->g_floor > 255 ||
	global->colors->b_floor < 0 || global->colors->b_floor > 255 )
		ft_error(3);
}
