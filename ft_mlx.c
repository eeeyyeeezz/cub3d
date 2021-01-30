/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:17:10 by gmorra            #+#    #+#             */
/*   Updated: 2021/01/30 23:25:23 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#define SCALE 20

static	void		my_mlx_pixel_put(t_struct *data, int x, int y, int color)
{
	char	*dst;

	dst = data->data->addr + (y * data->data->length + x * (data->data->bpp / 8));
	*(unsigned int*)dst = color;
}

static	void		draw_all_pixels(int x, int y, char **map, t_struct *global)
{
	int	i;
	int j;
	int save;

	j = y * SCALE;
	save = j;

	my_mlx_pixel_put(global, global->map->position_x * SCALE, global->map->position_y * SCALE, 0xFF0000);
	while (j < y * SCALE + SCALE)
	{
		i = x * SCALE;
		while (i < x * SCALE + SCALE)
		{
			my_mlx_pixel_put(global, i, j, 0xFFFFFF);
			i++;
		}
		j++;
	}
}

int			key_hook(t_struct *global)
{
	printf("fuck me!\n");
	return (0);
}

int			ft_close(t_struct *global)
{
	mlx_destroy_window(global->mlx, global->mlx_win);
	return (1);
}

void		ft_mlx(t_struct *global)
{
	int x;
	int y;
	char **map;
	// t_struct data_s;

	y = 0;
	x = 0;
	if (!(global->mlx = mlx_init()))
		return ;
	global->mlx_win = mlx_new_window(global->mlx, 2000, 900, "cub3D");
	global->data->img = mlx_new_image(global->mlx, 2000, 900);
	global->data->addr = mlx_get_data_addr(global->data->img, &global->data->bpp, &global->data->length, &global->data->end);
	mlx_key_hook(global->mlx_win, key_hook, global);

	// mlx_hook(global->mlx_win, 2, 1L<<0, ft_close, global);
	while (global->cub_map[y] != NULL)
	{
		x = 0;
		while (global->cub_map[y][x] != '\0')
		{
			if (global->cub_map[y][x] == '1')
				draw_all_pixels(x, y, map, global);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(global->mlx, global->mlx_win, global->data->img, 600, 300);
	write(1, "open\n", 5);
	mlx_loop(global->mlx);
}

// while (j < y * SCALE + SCALE)
// 	{
// 		i = x * SCALE;
// 		while (i < x * SCALE + SCALE)
// 		{
// 			my_mlx_pixel_put(&img, img.map->position_x, img.map->position_y, 0xFF0000);
// 			i++;
// 		}
// 		j++;
// 	}

