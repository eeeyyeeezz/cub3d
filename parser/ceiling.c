/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceiling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 16:46:29 by gmorra            #+#    #+#             */
/*   Updated: 2021/03/14 11:57:03 by gmorra           ###   ########.fr       */
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

static int		check_count(char *line)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (line[++i] != '\0')
	{
		if (line[i] != ' ' && line[i] != ','
		&& line[i] != '\0' && !ft_isdigit(line[i]))
			ft_error(6);
	}
	i = 1;
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
	int	ret;
	int coma;

	i = 0;
	coma = 0;
	while (line[++i] == ',')
		coma++;
	if (coma != 1 || (line[i] != ',' && !(ft_isdigit(line[i]))))
		ft_error(5);
	ret = i;
	i = -1;
	while (line[++i] != '\0')
	{
		if (line[i] == ',' && line[i + 1] == ',')
			ft_error(5);
	}
	return (ret);
}

static	void	while_ceiling(t_struct *global, char *line, int i)
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

void			pars_ceilling(char *line, t_struct *global)
{
	static int		times = 0;
	int				count;
	int				i;

	i = 1;
	times++;
	global->map.map_to_pars++;
	count = check_count(line);
	if (count == 3 && line[0] == 'C' && times == 1)
		while_ceiling(global, line, i);
	else
		ft_error(3);
	if (global->colors->r_cell < 0 || global->colors->r_cell > 255 ||
	global->colors->g_cell < 0 || global->colors->g_cell > 255 ||
	global->colors->b_cell < 0 || global->colors->b_cell > 255)
		ft_error(4);
	global->colors->cell_hex = (global->colors->r_cell * 65536) +
	(global->colors->g_cell * 256) + global->colors->b_cell;
	free(line);
}
