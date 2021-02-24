/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_ifs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:50:24 by gmorra            #+#    #+#             */
/*   Updated: 2021/02/24 17:18:00 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"
#define texWidth 64
#define texHeight 64


void			first_ifs(t_struct *global)
{
	if(global->draw.ray_dir_x < 0)
	{
		global->draw.step_x = -1;
		global->draw.side_dist_x = (global->map.pos_x - global->draw.map_x) * global->draw.delta_dist_x;
	}
	else
	{
		global->draw.step_x = 1;
		global->draw.side_dist_x = (global->draw.map_x + 1.0 - global->map.pos_x) * global->draw.delta_dist_x;
	}
	if(global->draw.ray_dir_y < 0)
	{
		global->draw.step_y = -1;
		global->draw.side_dist_y = (global->map.pos_y - global->draw.map_y) * global->draw.delta_dist_y;
	}
	else
	{
		global->draw.step_y = 1;
		global->draw.side_dist_y = (global->draw.map_y + 1.0 - global->map.pos_y) * global->draw.delta_dist_y;
	}
}

void			second_ifs(t_struct *global, int x)
{
	while (global->draw.hit == 0)
	{
		if(global->draw.side_dist_x < global->draw.side_dist_y)
		{
			global->draw.side_dist_x += global->draw.delta_dist_x;
			global->draw.map_x += global->draw.step_x;
			global->draw.side = 0;
		}
	else
	{
		global->draw.side_dist_y += global->draw.delta_dist_y;
		global->draw.map_y += global->draw.step_y;
		global->draw.side = 1;
	}
	if(global->cub_map[global->draw.map_x][global->draw.map_y] == '1')
		global->draw.hit = 1;
	}
	if(global->draw.side == 0)
		global->draw.perp_wall_dist = (global->draw.map_x - global->map.pos_x + (1 - global->draw.step_x) / 2) / global->draw.ray_dir_x;
	else
		global->draw.perp_wall_dist = (global->draw.map_y - global->map.pos_y + (1 - global->draw.step_y) / 2) / global->draw.ray_dir_y;
	global->map.every_dist[x] = global->draw.perp_wall_dist;
	global->draw.line_height = (int)(global->map.height / global->draw.perp_wall_dist);
	global->draw.draw_start = -global->draw.line_height / 2 + global->map.height / 2;
}

void			third_ifs(t_struct *global)
{
	if(global->draw.draw_start < 0)
		global->draw.draw_start = 0;
	global->draw.draw_end = global->draw.line_height / 2 + global->map.height / 2;
	if(global->draw.draw_end >= global->map.height)
		global->draw.draw_end = global->map.height - 1;
	if(global->draw.side == 0)
		global->draw.wall_x = global->map.pos_y + global->draw.perp_wall_dist * global->draw.ray_dir_y;
	else
		global->draw.wall_x = global->map.pos_x + global->draw.perp_wall_dist * global->draw.ray_dir_x;
	global->draw.wall_x -= floor((global->draw.wall_x));
	global->draw.tex_x = (int)(global->draw.wall_x * (double)(texWidth));
	if(global->draw.side == 0 && global->draw.ray_dir_x > 0)
		global->draw.tex_x = texWidth - global->draw.tex_x - 1;
	if(global->draw.side == 1 && global->draw.ray_dir_y < 0)
		global->draw.tex_x = texWidth - global->draw.tex_x - 1;
	global->draw.step = 1.0 * texHeight / global->draw.line_height;
	global->draw.tex_pos = (global->draw.draw_start - global->map.height / 2 + global->draw.line_height / 2) * global->draw.step;
}
