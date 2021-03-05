/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_sight.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:53:55 by gmorra            #+#    #+#             */
/*   Updated: 2021/03/05 17:54:07 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void		direction_sight(t_struct *global)
{
	global->draw.move_speed = 0.1;
	global->draw.rot_speed = 0.1;
	if (global->map.is_player == 'N')
	{
		global->draw.dir_x = -1;
		global->draw.plane_y = 0.66;
	}
	if (global->map.is_player == 'S')
	{
		global->draw.dir_x = 1;
		global->draw.plane_y = -0.66;
	}
	if (global->map.is_player == 'W')
	{
		global->draw.dir_y = -1;
		global->draw.plane_x = -0.66;
	}
	if (global->map.is_player == 'E')
	{
		global->draw.dir_y = 1;
		global->draw.plane_x = 0.66;
	}
}
