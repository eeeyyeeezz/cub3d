/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_draw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 17:03:32 by gmorra            #+#    #+#             */
/*   Updated: 2021/03/06 13:08:40 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static	void	textures_draw_second(t_struct *global)
{
	int width;
	int height;

	if (!(global->textures_east.img = mlx_xpm_file_to_image(global->mlx,
	global->textures->east, &width, &height)))
		ft_error(9);
	global->textures_east.addr = mlx_get_data_addr(global->textures_east.img,
	&global->textures_east.bpp,
		&global->textures_east.length, &global->textures_east.end);
	if (!(global->textures_west.img = mlx_xpm_file_to_image(global->mlx,
	global->textures->west, &width, &height)))
		ft_error(10);
	global->textures_west.addr = mlx_get_data_addr(global->textures_west.img,
	&global->textures_west.bpp,
		&global->textures_west.length, &global->textures_west.end);
	if (!(global->sprite_draw.img = mlx_xpm_file_to_image(global->mlx,
	global->textures->sprite, &width, &height)))
		ft_error(11);
	global->sprite_draw.addr = mlx_get_data_addr(global->sprite_draw.img,
	&global->sprite_draw.bpp,
		&global->sprite_draw.length, &global->sprite_draw.end);
}

void			textures_draw(t_struct *global)
{
	int width;
	int height;

	if (!(global->textures_north.img = mlx_xpm_file_to_image(global->mlx,
	global->textures->north, &width, &height)))
		ft_error(7);
	global->textures_north.addr = mlx_get_data_addr(global->textures_north.img,
	&global->textures_north.bpp,
		&global->textures_north.length, &global->textures_north.end);
	if (!(global->textures_south.img = mlx_xpm_file_to_image(global->mlx,
	global->textures->south, &width, &height)))
		ft_error(8);
	global->textures_south.addr = mlx_get_data_addr(global->textures_south.img,
	&global->textures_south.bpp,
		&global->textures_south.length, &global->textures_south.end);
	textures_draw_second(global);
}
