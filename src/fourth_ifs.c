/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fourth_ifs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:23:51 by gmorra            #+#    #+#             */
/*   Updated: 2021/03/05 17:10:45 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static	void	fifth_ifs(t_struct *global, int x, int y)
{
	int color;

	if (global->draw.side == 1)
	{
		if (global->draw.step_y > 0)
		{
			color = my_mlx_pixel_take(&global->textures_west,
			global->draw.tex_x, global->draw.tex_y);
			my_mlx_pixel_put(&global->data, x, y, color);
		}
		else if (global->draw.step_y < 0)
		{
			color = my_mlx_pixel_take(&global->textures_east,
			global->draw.tex_x, global->draw.tex_y);
			my_mlx_pixel_put(&global->data, x, y, color);
		}
	}
}

void			fourth_ifs(t_struct *global, int x, int y)
{
	int color;

	global->draw.tex_y = (int)global->draw.tex_pos & (64 - 1);
	global->draw.tex_pos += global->draw.step;
	if (global->draw.side == 0)
	{
		if (global->draw.step_x > 0)
		{
			color = my_mlx_pixel_take(&global->textures_north,
			global->draw.tex_x, global->draw.tex_y);
			my_mlx_pixel_put(&global->data, x, y, color);
		}
		else if (global->draw.step_x < 0)
		{
			color = my_mlx_pixel_take(&global->textures_south,
			global->draw.tex_x, global->draw.tex_y);
			my_mlx_pixel_put(&global->data, x, y, color);
		}
	}
	fifth_ifs(global, x, y);
}
