/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 16:18:10 by gmorra            #+#    #+#             */
/*   Updated: 2021/02/17 16:09:00 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void			left_rotate(t_struct *global, int keycode)
{
	double speed = global->draw.rot_speed;
	double oldDirX = global->draw.dir_x;
	if (keycode == 123)
	{
		global->draw.dir_x = global->draw.dir_x * cos(speed) - global->draw.dir_y * sin(speed);
		global->draw.dir_y = oldDirX * sin(speed) + global->draw.dir_y * cos(speed);
		double oldPlaneX = global->draw.plane_x;
		global->draw.plane_x = global->draw.plane_x * cos(speed) - global->draw.plane_y * sin(speed);
		global->draw.plane_y = oldPlaneX * sin(speed) + global->draw.plane_y * cos(speed);
	}
}

void			right_rotate(t_struct *global, int keycode)
{
	double speed = global->draw.rot_speed;
	double oldDirX = global->draw.dir_x;

	if (keycode == 124)
	{
		global->draw.dir_x = global->draw.dir_x * cos(-speed) - global->draw.dir_y * sin(-speed);
		global->draw.dir_y = oldDirX * sin(-speed) + global->draw.dir_y * cos(-speed);
		double oldPlaneX = global->draw.plane_x;
		global->draw.plane_x = global->draw.plane_x * cos(-speed) - global->draw.plane_y * sin(-speed);
		global->draw.plane_y = oldPlaneX * sin(-speed) + global->draw.plane_y * cos(-speed);
	}
}

void			up_down(t_struct *global, int keycode)
{
	double moveSpeed = global->draw.move_speed;

	if (keycode == 13)
	{
		if(worldMap[(int)(global->map.pos_x + global->draw.dir_x * moveSpeed)][(int)(global->map.pos_y)] == 0)
			global->map.pos_x += global->draw.dir_x * moveSpeed;
		if(worldMap[(int)(global->map.pos_x)][(int)(global->map.pos_x + global->draw.dir_y * moveSpeed)] == 0)
			global->map.pos_y += global->draw.dir_y * moveSpeed;
	}
	if (keycode == 1)
	{
		if(worldMap[(int)(global->map.pos_x + global->draw.dir_x * moveSpeed)][(int)(global->map.pos_y)] == 0)
			global->map.pos_x -= global->draw.dir_x * moveSpeed;
		if(worldMap[(int)(global->map.pos_x)][(int)(global->map.pos_x + global->draw.dir_y * moveSpeed)] == 0)
			global->map.pos_y -= global->draw.dir_y * moveSpeed;
	}
}

void			right_left(t_struct *global, int keycode)
{
	double moveSpeed = global->draw.move_speed;

	if (keycode == 2)
	{
		if(worldMap[(int)(global->map.pos_x + global->draw.dir_y * moveSpeed)][(int)(global->map.pos_y)] == 0)
			global->map.pos_x += global->draw.dir_y * moveSpeed;
		if(worldMap[(int)(global->map.pos_x)][(int)(global->map.pos_y - global->draw.dir_x * moveSpeed)] == 0)
			global->map.pos_y -= global->draw.dir_x * moveSpeed;

	}
	if (keycode == 0)
	{
		if(worldMap[(int)(global->map.pos_x - global->draw.dir_y * moveSpeed)][(int)(global->map.pos_y)] == 0)
			global->map.pos_x -= global->draw.dir_y * moveSpeed;
		if(worldMap[(int)(global->map.pos_x)][(int)(global->map.pos_y + global->draw.dir_x * moveSpeed)] == 0)
			global->map.pos_y += global->draw.dir_x * moveSpeed;
	}
}
