/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_draw_while.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 16:17:38 by gmorra            #+#    #+#             */
/*   Updated: 2021/03/06 13:08:40 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void			first_draw_while(t_struct *global)
{
	int x;
	int y;

	x = 0;
	while (x < global->map.width)
	{
		y = 0;
		init_all(global, x);
		first_ifs(global);
		second_ifs(global, x);
		third_ifs(global);
		while (y < global->map.height)
		{
			if (y < global->draw.draw_start)
				my_mlx_pixel_put(&global->data, x, y, global->colors->cell_hex);
			if (y >= global->draw.draw_start && y <= global->draw.draw_end)
				fourth_ifs(global, x, y);
			if (y > global->draw.draw_end)
				my_mlx_pixel_put(&global->data, x, y,
				global->colors->floor_hex);
			y++;
		}
		x++;
	}
}
