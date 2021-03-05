/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 17:05:54 by gmorra            #+#    #+#             */
/*   Updated: 2021/03/05 16:18:22 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static	void	sprite_first_norme(t_struct *global, int i)
{
	global->d_spr.sprite_x = global->sprites[i].x - global->map.pos_x;
	global->d_spr.sprite_y = global->sprites[i].y - global->map.pos_y;
	global->d_spr.inv_det = 1.0 / (global->draw.plane_x * global->draw.dir_y -
	global->draw.dir_x * global->draw.plane_y);
	global->d_spr.transform_x = global->d_spr.inv_det * (global->draw.dir_y *
	global->d_spr.sprite_x - global->draw.dir_x * global->d_spr.sprite_y);
	global->d_spr.transform_y = global->d_spr.inv_det * (-global->draw.plane_y *
	global->d_spr.sprite_x + global->draw.plane_x * global->d_spr.sprite_y);
	global->d_spr.sprite_screen_x = (int)((global->map.width / 2) *
	(1 + global->d_spr.transform_x / global->d_spr.transform_y));
	global->d_spr.sprite_height = abs((int)(global->map.height /
	(global->d_spr.transform_y)));
	global->d_spr.draw_start_y = -global->d_spr.sprite_height /
	2 + global->map.height / 2;
}

static	void	sprite_second_norme(t_struct *global)
{
	if (global->d_spr.draw_start_y < 0)
		global->d_spr.draw_start_y = 0;
	global->d_spr.draw_end_y = global->d_spr.sprite_height
	/ 2 + global->map.height / 2;
	if (global->d_spr.draw_end_y >= global->map.height)
		global->d_spr.draw_end_y = global->map.height - 1;
	global->d_spr.sprite_width = abs((int)(global->map.height
	/ (global->d_spr.transform_y)));
	global->d_spr.draw_start_x = -global->d_spr.sprite_width
	/ 2 + global->d_spr.sprite_screen_x;
	if (global->d_spr.draw_start_x < 0)
		global->d_spr.draw_start_x = 0;
	global->d_spr.draw_end_x = global->d_spr.sprite_width
	/ 2 + global->d_spr.sprite_screen_x;
	if (global->d_spr.draw_end_x >= global->map.width)
		global->d_spr.draw_end_x = global->map.width - 1;
}

static	void	norme_while(t_struct *global, int depth, int color, int y)
{
	global->d_spr.s_tex_x = (int)(256 *
	(global->d_spr.stripe - (-global->d_spr.sprite_width / 2 +
	global->d_spr.sprite_screen_x)) * 64
	/ global->d_spr.sprite_width) / 256;
	if (global->d_spr.transform_y > 0 &&
	global->d_spr.stripe > 0 && global->d_spr.stripe <
	global->map.width && global->d_spr.transform_y <
	global->map.every_dist[global->d_spr.stripe])
	{
		y = global->d_spr.draw_start_y;
		while (y < global->d_spr.draw_end_y)
		{
			depth = (y) * 256 - global->map.height *
			128 + global->d_spr.sprite_height * 128;
			global->d_spr.s_tex_y = ((depth * 64) /
			global->d_spr.sprite_height) / 256;
			color = my_mlx_pixel_take(&global->sprite_draw,
			global->d_spr.s_tex_x, global->d_spr.s_tex_y);
			if (color)
				my_mlx_pixel_put(&global->data,
				global->d_spr.stripe, y, color);
			y++;
		}
	}
}

static	void	sprite_third_norme(t_struct *global)
{
	int	depth;
	int	color;
	int y;

	global->d_spr.stripe = global->d_spr.draw_start_x;
	while (global->d_spr.stripe < global->d_spr.draw_end_x)
	{
		norme_while(global, depth, color, y);
		global->d_spr.stripe++;
	}
}

void			draw(t_struct *global)
{
	int i;

	i = 0;
	first_draw_while(global);
	get_sprites_right(global);
	while (i < global->map.num_sprites)
	{
		sprite_first_norme(global, i);
		sprite_second_norme(global);
		sprite_third_norme(global);
		i++;
	}
}
