/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 14:35:46 by gmorra            #+#    #+#             */
/*   Updated: 2021/02/28 14:35:52 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void		sprite_parser_count(t_struct *global)
{
	int x;
	int y;

	y = 0;
	while (global->cub_map[y])
	{
		x = 0;
		while(global->cub_map[y][x])
		{
			if (global->cub_map[y][x] == '2')
				global->map.num_sprites++;
			x++;
		}
		y++;
	}
}

int		sprite_parser(t_struct *global)
{
	int x;
	int y;
	int num_sprites;
	int count;

	y = 0;
	count = 0;
	num_sprites = global->map.num_sprites;
	if (!(global->sprites = malloc(sizeof(t_sprites) * num_sprites)))
		return (-1);
	while (global->cub_map[y])
	{
		x = 0;
		while (global->cub_map[y][x])
		{
			if (global->cub_map[y][x] == '2')
			{
				global->sprites[count].y = (float)x + 0.5f;
				global->sprites[count].x = (float)y + 0.5f;
				count++;
			}
			x++;
		}
		y++;
	}
	return (0);
}
