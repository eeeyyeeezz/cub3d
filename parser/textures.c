/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 21:16:08 by gmorra            #+#    #+#             */
/*   Updated: 2021/02/26 20:22:10 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void			pars_textures(char *line, t_struct *global)
{
	int 		i;

	i = 0;
	global->map.map_to_pars++;
	while (line[i] != '.')
		i++;
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
