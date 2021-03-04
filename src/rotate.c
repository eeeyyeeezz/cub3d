/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 15:40:50 by gmorra            #+#    #+#             */
/*   Updated: 2021/03/04 15:29:27 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void			left_rotate(t_struct *global)
{
	double speed;
	double olddirx;
	double oldplanex;

	speed = global->draw.rot_speed;
	olddirx = global->draw.dir_x;
	if (global->key.left == 1)
	{
		global->draw.dir_x = global->draw.dir_x *
		cos(speed) - global->draw.dir_y * sin(speed);
		global->draw.dir_y = olddirx * sin(speed)
		+ global->draw.dir_y * cos(speed);
		oldplanex = global->draw.plane_x;
		global->draw.plane_x = global->draw.plane_x
		* cos(speed) - global->draw.plane_y * sin(speed);
		global->draw.plane_y = oldplanex * sin(speed)
		+ global->draw.plane_y * cos(speed);
	}
}

void			right_rotate(t_struct *global)
{
	double speed;
	double olddirx;
	double oldplanex;

	speed = global->draw.rot_speed;
	olddirx = global->draw.dir_x;
	if (global->key.right == 1)
	{
		global->draw.dir_x = global->draw.dir_x
		* cos(-speed) - global->draw.dir_y * sin(-speed);
		global->draw.dir_y = olddirx * sin(-speed)
		+ global->draw.dir_y * cos(-speed);
		oldplanex = global->draw.plane_x;
		global->draw.plane_x = global->draw.plane_x
		* cos(-speed) - global->draw.plane_y * sin(-speed);
		global->draw.plane_y = oldplanex * sin(-speed)
		+ global->draw.plane_y * cos(-speed);
	}
}
