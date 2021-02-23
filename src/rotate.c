/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 15:40:50 by gmorra            #+#    #+#             */
/*   Updated: 2021/02/23 15:40:24 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void			left_rotate(t_struct *global)
{
	double speed = global->draw.rot_speed;
	double oldDirX = global->draw.dir_x;
	if (global->key.left == 1)
	{
		global->draw.dir_x = global->draw.dir_x * cos(speed) - global->draw.dir_y * sin(speed);
		global->draw.dir_y = oldDirX * sin(speed) + global->draw.dir_y * cos(speed);
		double oldPlaneX = global->draw.plane_x;
		global->draw.plane_x = global->draw.plane_x * cos(speed) - global->draw.plane_y * sin(speed);
		global->draw.plane_y = oldPlaneX * sin(speed) + global->draw.plane_y * cos(speed);
	}
}

void			right_rotate(t_struct *global)
{
	double speed = global->draw.rot_speed;
	double oldDirX = global->draw.dir_x;

	if (global->key.right == 1)
	{
		global->draw.dir_x = global->draw.dir_x * cos(-speed) - global->draw.dir_y * sin(-speed);
		global->draw.dir_y = oldDirX * sin(-speed) + global->draw.dir_y * cos(-speed);
		double oldPlaneX = global->draw.plane_x;
		global->draw.plane_x = global->draw.plane_x * cos(-speed) - global->draw.plane_y * sin(-speed);
		global->draw.plane_y = oldPlaneX * sin(-speed) + global->draw.plane_y * cos(-speed);
	}
}
