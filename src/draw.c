/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 17:05:54 by gmorra            #+#    #+#             */
/*   Updated: 2021/03/03 17:28:25 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void			draw(t_struct *global)
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
				my_mlx_pixel_put(&global->data, x, y, 0xFFFFFF);
			if (y >= global->draw.draw_start && y <= global->draw.draw_end)
				fourth_ifs(global, x, y);
			if (y > global->draw.draw_end)
				my_mlx_pixel_put(&global->data, x, y, 0x12376d);
			y++;
		}
	x++;
	}
	for(int i = 0; i < global->map.num_sprites; i++)
	{
		global->sprites[i].distance = ((global->map.pos_x - global->sprites[i].x) * (global->map.pos_x - global->sprites[i].x) +
			(global->map.pos_y - global->sprites[i].y) * (global->map.pos_y - global->sprites[i].y));
	}
	sort_sprites(global);

	for(int i = 0; i < global->map.num_sprites; i++)
	{
		double spriteX = global->sprites[i].x - global->map.pos_x;
		double spriteY = global->sprites[i].y - global->map.pos_y;
		double invDet = 1.0 / (global->draw.plane_x * global->draw.dir_y - global->draw.dir_x * global->draw.plane_y);

		double transformX = invDet * (global->draw.dir_y * spriteX - global->draw.dir_x * spriteY);
		double transformY = invDet * (-global->draw.plane_y * spriteX + global->draw.plane_x * spriteY);

		int spriteScreenX = (int)((global->map.width / 2) * (1 + transformX / transformY));

		int spriteHeight = abs((int)(global->map.height / (transformY)));
		int drawStartY = -spriteHeight / 2 + global->map.height / 2;
		if(drawStartY < 0)
			drawStartY = 0;
		int drawEndY = spriteHeight / 2 + global->map.height / 2;
		if(drawEndY >= global->map.height)
			drawEndY = global->map.height - 1;

		int spriteWidth = abs((int) (global->map.height / (transformY)));
		int drawStartX = -spriteWidth / 2 + spriteScreenX;
		if(drawStartX < 0) drawStartX = 0;
		int drawEndX = spriteWidth / 2 + spriteScreenX;
		if(drawEndX >= global->map.width) drawEndX = global->map.width - 1;

			for(int stripe = drawStartX; stripe < drawEndX; stripe++)
			{
			int texX = (int)(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * 64 / spriteWidth) / 256;
				if(transformY > 0 && stripe > 0 && stripe < global->map.width && transformY < global->map.every_dist[stripe])
				{
					for(int y = drawStartY; y < drawEndY; y++)
					{
						int d = (y) * 256 - global->map.height * 128 + spriteHeight * 128;
						int texY = ((d * 64) / spriteHeight) / 256;
						int color = my_mlx_pixel_take(&global->sprite_draw, texX, texY);
						if (color)
							my_mlx_pixel_put(&global->data, stripe, y, color);
					}
				}
			}
	}
}
