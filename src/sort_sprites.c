/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 17:07:27 by gmorra            #+#    #+#             */
/*   Updated: 2021/03/11 15:48:37 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void			bubble_position_sprite(t_struct *global, int i, int j)
{
	float tmp;
	float position;

	tmp = 0;
	position = 0;
	tmp = global->sprites[j].distance;
	global->sprites[j].distance = global->sprites[i].distance;
	global->sprites[i].distance = tmp;
	position = global->sprites[i].x;
	global->sprites[i].x = global->sprites[j].x;
	global->sprites[j].x = position;
	position = global->sprites[i].y;
	global->sprites[i].y = global->sprites[j].y;
	global->sprites[j].y = position;
}

void			sort_sprites(t_struct *global)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while (++i < global->map.num_sprites)
	{
		while (j < global->map.num_sprites)
		{
			if (global->sprites[i].distance > global->sprites[j].distance)
				bubble_position_sprite(global, i, j);
			j++;
		}
		j = 0;
	}
}
