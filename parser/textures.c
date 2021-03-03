/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 21:16:08 by gmorra            #+#    #+#             */
/*   Updated: 2021/03/03 20:13:06 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static	void	fuck_me(t_struct *global)
{
	global->crutch.no_times = 0;
	global->crutch.so_times = 0;
	global->crutch.we_times = 0;
	global->crutch.ea_times = 0;
	global->crutch.sp_times = 0;
}

static	void	pars_second_texture(char *line, t_struct *global, int i)
{
	if (ft_strnstr(line, "WE"))
	{
		global->textures->west = (char *)&line[i];
		global->crutch.we_times++;
	}
	else if (ft_strnstr(line, "EA"))
	{
		global->textures->east = (char *)&line[i];
		global->crutch.ea_times++;
	}
	else if (ft_strnstr(line, "S"))
	{
		global->textures->sprite = (char *)&line[i];
		global->crutch.sp_times++;
	}
}

void			pars_textures(char *line, t_struct *global)
{
	int 		i;

	i = 0;
	global->map.map_to_pars++;
	while (line[i] != '.')
		i++;
	if (ft_strnstr(line, "NO"))
	{
		global->textures->north = (char *)&line[i];
		global->crutch.no_times++;
	}
	else if (ft_strnstr(line, "SO"))
	{
		global->textures->south = (char *)&line[i];
		global->crutch.so_times++;
	}
	pars_second_texture(line, global, i);
}
