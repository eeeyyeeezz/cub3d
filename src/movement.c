/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 16:18:10 by gmorra            #+#    #+#             */
/*   Updated: 2021/02/15 17:23:12 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void			left_rotate(t_struct *global, int keycode)
{
	double speed = global->draw.rot_speed;
	double oldDirX = global->dir_x;
	if (keycode == 123)
	{
		global->dir_x = global->dir_x * cos(speed) - global->dir_y * sin(speed);
		global->dir_y = oldDirX * sin(speed) + global->dir_y * cos(speed);
		double oldPlaneX = global->plane_x;
		global->plane_x = global->plane_x * cos(speed) - global->plane_y * sin(speed);
		global->plane_y = oldPlaneX * sin(speed) + global->plane_y * cos(speed);
	}
}

void			right_rotate(t_struct *global, int keycode)
{
	double speed = global->draw.rot_speed;
	double oldDirX = global->dir_x;

	if (keycode == 124)
	{
		global->dir_x = global->dir_x * cos(-speed) - global->dir_y * sin(-speed);
		global->dir_y = oldDirX * sin(-speed) + global->dir_y * cos(-speed);
		double oldPlaneX = global->plane_x;
		global->plane_x = global->plane_x * cos(-speed) - global->plane_y * sin(-speed);
		global->plane_y = oldPlaneX * sin(-speed) + global->plane_y * cos(-speed);
	}
}

void			up_down(t_struct *global, int keycode)
{
	double moveSpeed = global->draw.move_speed;

	if (keycode == 13)		// up
	{
		if(global->cub_map[(int)(global->map->pos_x + global->dir_x * moveSpeed)][(int)(global->map->pos_y)] == 0)
			global->map->pos_x += global->dir_x * moveSpeed;
		if(global->cub_map[(int)(global->map->pos_x)][(int)(global->map->pos_x + global->dir_y * moveSpeed)] == 0)
			global->map->pos_y += global->dir_y * moveSpeed;
	}
	if (keycode == 1)		// down
	{
		if(global->cub_map[(int)(global->map->pos_x + global->dir_x * moveSpeed)][(int)(global->map->pos_y)] == 0)
			global->map->pos_x -= global->dir_x * moveSpeed;
		if(global->cub_map[(int)(global->map->pos_x)][(int)(global->map->pos_x + global->dir_y * moveSpeed)] == 0)
			global->map->pos_y -= global->dir_y * moveSpeed;
	}
}

void			right_left(t_struct *global, int keycode)
{
	double moveSpeed = global->draw.move_speed;

	if (keycode == 2)
	{
		if(global->cub_map[(int)(global->map->pos_x + global->dir_y * moveSpeed)][(int)(global->map->pos_y)] == 0)
			global->map->pos_x += global->dir_y * moveSpeed;
		if(global->cub_map[(int)(global->map->pos_x)][(int)(global->map->pos_y - global->dir_x * moveSpeed)] == 0)
			global->map->pos_y -= global->dir_x * moveSpeed;

	}
	if (keycode == 0)
	{
		if(global->cub_map[(int)(global->map->pos_x - global->dir_y * moveSpeed)][(int)(global->map->pos_y)] == 0)
			global->map->pos_x -= global->dir_y * moveSpeed;
		if(global->cub_map[(int)(global->map->pos_x)][(int)(global->map->pos_y + global->dir_x * moveSpeed)] == 0)
			global->map->pos_y += global->dir_x * moveSpeed;
	}
}

void			go_fast(t_struct *global, int keycode)
{
	if (keycode == 12)
		global->draw.move_speed += + 0.1;
	if (keycode == 14)
		global->draw.move_speed -= 0.1;
}
