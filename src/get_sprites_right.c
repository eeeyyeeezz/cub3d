/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprites_right.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:20:21 by gmorra            #+#    #+#             */
/*   Updated: 2021/03/06 13:08:40 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void			get_sprites_right(t_struct *global)
{
	int i;

	i = -1;
	while (++i < global->map.num_sprites)
	{
		global->sprites[i].distance =
		((global->map.pos_x - global->sprites[i].x) *
		(global->map.pos_x - global->sprites[i].x) +
			(global->map.pos_y - global->sprites[i].y) *
			(global->map.pos_y - global->sprites[i].y));
	}
	sort_sprites(global);
}
