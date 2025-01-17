/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 21:16:08 by gmorra            #+#    #+#             */
/*   Updated: 2021/03/13 16:14:45 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void			pars_textures(char *line, t_struct *global)
{
	int		i;

	i = 2;
	global->map.map_to_pars++;
	while (line[i] != '.')
	{
		if (line[i] != ' ')
			ft_error(22);
		i++;
	}
	if (ft_strnstr(line, "NO"))
		global->textures->north = (char *)&line[i];
	if (ft_strnstr(line, "SO"))
		global->textures->south = (char *)&line[i];
	if (ft_strnstr(line, "WE"))
		global->textures->west = (char *)&line[i];
	if (ft_strnstr(line, "EA"))
		global->textures->east = (char *)&line[i];
	if (ft_strnstr(line, "S"))
		global->textures->sprite = (char *)&line[i];
}
