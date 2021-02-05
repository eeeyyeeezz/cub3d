/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:17:10 by gmorra            #+#    #+#             */
/*   Updated: 2021/02/05 21:45:40 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#define SCALE 30

static	void		my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}


static	void		draw_all_pixels(int x, int y, t_struct *global)
{
	int	i;
	int j;
	int save;

	j = y * SCALE;
	save = j;

	// my_mlx_pixel_put(global->data, global->map->position_x * SCALE, global->map->position_y * SCALE, 0xFF0000);
	while (j < y * SCALE + SCALE)
	{
		i = x * SCALE;
		while (i < x * SCALE + SCALE)
		{
			my_mlx_pixel_put(global->data, i, j, 0xFFFFFF);
			i++;
		}
		j++;
	}
	// mlx_put_image_to_window(global->mlx, global->mlx_win, global->data->img, 0, 0);
}

static	void		draw(t_struct *global)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (global->cub_map[y] != NULL)
	{
		x = 0;
		while (global->cub_map[y][x] != '\0')
		{
			if (global->cub_map[y][x] == '1')
				draw_all_pixels(x, y, global);
			if (global->cub_map[y][x] == 'N')
				draw_all_pixels(global->map->position_x, global->map->position_y, global);
			x++;
		}
		y++;
	}
}

static void		ft_raycast(t_struct *global)
{
	int x;
	int y;

	x = global->map->position_x;
	y = global->map->position_y;

	while (global->cub_map[y][x] != '1')
	{
		my_mlx_pixel_put(global->data, x * SCALE, y * SCALE, 0xFF0000);
		y--;
	}
	// mlx_put_image_to_window(global->mlx, global->mlx_win, global->data->img, 0, 0);
}

int			key_hook(int keycode, t_struct *global)
{
	printf("%d!\n", keycode);
	if (keycode == 53) // esc
		exit(0);
	if (keycode == 125)				// почему так?
		global->map->position_y += 1;
	if (keycode == 126)
		global->map->position_y -= 1;
	if (keycode == 124)
		global->map->position_x += 1;
	if (keycode == 123)
		global->map->position_x -= 1;
	// mlx_clear_window(global->mlx, global->mlx_win);
	mlx_destroy_image(global->mlx, global->data->img);		// destroy_image segfault
	global->data->img = mlx_new_image(global->mlx, 1600, 900);
	global->data->addr = mlx_get_data_addr(global->data->img, &global->data->bpp, &global->data->length, &global->data->end);
	ft_raycast(global);
	draw(global);
	mlx_put_image_to_window(global->mlx, global->mlx_win, global->data->img, 0, 0);
	return (0);
}

void		ft_mlx(t_struct *global)
{
	int x;
	int y;

	y = 0;
	x = 0;
	if (!(global->mlx = mlx_init()))
		return ;
	global->mlx_win = mlx_new_window(global->mlx, 1600, 900, "cub3D");
	global->data->img = mlx_new_image(global->mlx, 1600, 900);
	global->data->addr = mlx_get_data_addr(global->data->img, &global->data->bpp, &global->data->length, &global->data->end);
	mlx_key_hook(global->mlx_win, key_hook, global);
	draw(global);
	ft_raycast(global);
	mlx_put_image_to_window(global->mlx, global->mlx_win, global->data->img, 0, 0);
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

