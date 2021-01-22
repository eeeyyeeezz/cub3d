/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   north.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 21:16:08 by gmorra            #+#    #+#             */
/*   Updated: 2021/01/22 22:17:56 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void		pars_north(char *line, t_struct *global)
{
	int i;

	i = 0;
	if (ft_ft_strnstr(line, "./"))
	{
		while (line[i] != '.')
			i++;
		global->textures->north = (char *)&line[i];
	}
	else
	{
		write(1, "ERROR", 5);
		exit(0);
	}
}
