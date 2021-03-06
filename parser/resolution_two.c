/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:20:31 by gmorra            #+#    #+#             */
/*   Updated: 2021/03/06 13:08:40 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	skip_digits(char *line)
{
	int i;

	i = 0;
	while (ft_isdigit(line[i]))
		i++;
	return (i);
}

void		big_screen_size(t_struct *global)
{
	int x;
	int y;

	mlx_get_screen_size(global->mlx, &x, &y);
	if (global->map.width > x)
		global->map.width = x;
	if (global->map.height > y)
		global->map.height = y;
}

int			while_first(t_struct *global, char *line, int res)
{
	int i;

	i = 0;
	if (line[i] != '\0')
	{
		while (line[i] >= '0' && line[i] <= '9')
		{
			res = res * 10 + line[i] - 48;
			i++;
			global->map.width = res;
			if (res > 6000)
				break ;
		}
		if (res > 6000)
		{
			i += skip_digits((char *)&line[i]);
			global->map.width = 6000;
		}
	}
	return (i);
}

void		while_second(t_struct *global, char *line, int i, int res)
{
	if (line[i] != '\0')
	{
		while (line[i] >= '0' && line[i] <= '9')
		{
			res = res * 10 + line[i] - '0';
			i++;
			global->map.height = res;
			if (res > 6000)
				break ;
		}
		if (res > 6000)
			global->map.height = 6000;
	}
}
