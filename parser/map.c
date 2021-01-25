/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:59:40 by gmorra            #+#    #+#             */
/*   Updated: 2021/01/25 20:38:05 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void		pars_map(char *line, t_struct *global, int fd)
{
	char **whole_map;
	int i;

	i = 1;
	whole_map = malloc(sizeof(char *) * 20);
	(void)global;
	whole_map[0] = line;
	while (get_next_line(fd, &line))
	{
		whole_map[i] = line;
		i++;
	}
	i = 0;
	// global->cub_map = whole_map;
	while (whole_map[i])
	{
		printf("eto map [%s]\n", whole_map[i]);
		i++;
	}
}
