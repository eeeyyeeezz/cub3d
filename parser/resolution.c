/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 16:16:29 by gmorra            #+#    #+#             */
/*   Updated: 2021/03/04 14:24:59 by gmorra           ###   ########.fr       */
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

void				pars_resolution(char *line, t_struct *global)
{
	static int		times = 0;
	int				res;
	int				i;

	i = 1;
	res = 0;
	times++;
	global->map.map_to_pars++;
	if (check_count(line) == 2 && line[0] == 'R' && times == 1)
	{
		while (ft_isspaces(line[i]) && line[i] != '\0')
			i++;
		i += while_first(global, (char *)&line[i], res);
		i += ft_isspaces(line[i]);
		res = 0;
		while_second(global, line, i, res);
	}
	else
		ft_error(1);
	if (global->map.width <= 0 || global->map.height <= 0)
		ft_error(2);
	big_screen_size(global);
}
