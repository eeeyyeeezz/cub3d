/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 16:18:10 by gmorra            #+#    #+#             */
/*   Updated: 2021/03/06 13:08:40 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void			up_down(t_struct *global)
{
	double movespeed;

	movespeed = global->draw.move_speed;
	if (global->key.w_key == 1)
	{
		if (global->cub_map[(int)(global->map.pos_x + global->draw.dir_x *
		movespeed)][(int)(global->map.pos_y)] == '0')
			global->map.pos_x += global->draw.dir_x * movespeed;
		if (global->cub_map[(int)(global->map.pos_x)][(int)
		(global->map.pos_y + global->draw.dir_y * movespeed)] == '0')
			global->map.pos_y += global->draw.dir_y * movespeed;
	}
	if (global->key.s_key == 1)
	{
		if (global->cub_map[(int)(global->map.pos_x - global->draw.dir_x
		* movespeed)][(int)(global->map.pos_y)] == '0')
			global->map.pos_x -= global->draw.dir_x * movespeed;
		if (global->cub_map[(int)(global->map.pos_x)]
		[(int)(global->map.pos_y - global->draw.dir_y * movespeed)] == '0')
			global->map.pos_y -= global->draw.dir_y * movespeed;
	}
}

void			right_left(t_struct *global)
{
	double movespeed;

	movespeed = global->draw.move_speed;
	if (global->key.d_key == 1)
	{
		if (global->cub_map[(int)(global->map.pos_x + global->draw.dir_y
		* movespeed)][(int)(global->map.pos_y)] == '0')
			global->map.pos_x += global->draw.dir_y * movespeed;
		if (global->cub_map[(int)(global->map.pos_x)]
		[(int)(global->map.pos_y - global->draw.dir_x * movespeed)] == '0')
			global->map.pos_y -= global->draw.dir_x * movespeed;
	}
	if (global->key.a_key == 1)
	{
		if (global->cub_map[(int)(global->map.pos_x - global->draw.dir_y
		* movespeed)][(int)(global->map.pos_y)] == '0')
			global->map.pos_x -= global->draw.dir_y * movespeed;
		if (global->cub_map[(int)(global->map.pos_x)]
		[(int)(global->map.pos_y + global->draw.dir_x * movespeed)] == '0')
			global->map.pos_y += global->draw.dir_x * movespeed;
	}
}
