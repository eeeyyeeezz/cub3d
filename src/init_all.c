/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 17:06:27 by gmorra            #+#    #+#             */
/*   Updated: 2021/03/06 13:08:40 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void			init_all(t_struct *global, int x)
{
	global->draw.camera_x = 2 * x / (double)global->map.width - 1;
	global->draw.ray_dir_x = global->draw.dir_x +
	global->draw.plane_x * global->draw.camera_x;
	global->draw.ray_dir_y = global->draw.dir_y +
	global->draw.plane_y * global->draw.camera_x;
	global->draw.map_x = (int)global->map.pos_x;
	global->draw.map_y = (int)global->map.pos_y;
	global->draw.delta_dist_x =
	sqrt(1 + (global->draw.ray_dir_y * global->draw.ray_dir_y) /
	(global->draw.ray_dir_x * global->draw.ray_dir_x));
	global->draw.delta_dist_y =
	sqrt(1 + (global->draw.ray_dir_x * global->draw.ray_dir_x) /
	(global->draw.ray_dir_y * global->draw.ray_dir_y));
	global->draw.hit = 0;
}
