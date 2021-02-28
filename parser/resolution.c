/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 16:16:29 by gmorra            #+#    #+#             */
/*   Updated: 2021/02/28 17:24:59 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static int			skip_digits(char *line)
{
	int i;

	i = 0;
	while (ft_isdigit(line[i]))
		i++;
	return (i);
}

static int			check_count(char *line)
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

static	void		big_screen_size(t_struct *global, int x, int y)
{
	if (global->map.width > x)
		global->map.width = x;
	if (global->map.height > y)
		global->map.height = y;
}

void				pars_resolution(char *line, t_struct *global)
{
	int 	count;
	int		size;
	int		x;
	int		y;
	int 	i;

	i = 1;
	count = check_count(line);
	mlx_get_screen_size(global->mlx, &x, &y);
	global->map.map_to_pars++;
	if (count == 2 && line[0] == 'R')
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
	big_screen_size(global, x, y);
}
