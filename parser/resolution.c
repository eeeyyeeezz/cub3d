/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 16:16:29 by gmorra            #+#    #+#             */
/*   Updated: 2021/02/28 13:16:22 by gmorra           ###   ########.fr       */
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

void		pars_resolution(char *line, t_struct *global)
{
	static	int		times = 0;
	int 			count;
	int 			i;

	i = 1;
	times++;
	count = check_count(line);
	global->map.map_to_pars++;
	if (count == 2 && times == 1 && line[0] == 'R')
	{
		while (ft_isspaces(line[i]) && line[i] != '\0')
			i++;
		if (line[i] != '\0')
			global->map.width = ft_atoi((char *)&line[i]);
		i += 1;
		i += skip_digits((char *)&line[i]);
		if (line[i] != '\0')
			global->map.height = ft_atoi((char *)&line[i]);
	}
	else
		ft_error(1);
	if (global->map.width <= 0 || global->map.height <= 0)
		ft_error(2);
}
