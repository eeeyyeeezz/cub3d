/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:17:10 by gmorra            #+#    #+#             */
/*   Updated: 2021/02/07 18:28:48 by gmorra           ###   ########.fr       */
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

	my_mlx_pixel_put(global->data, global->map->position_x * SCALE, global->map->position_y * SCALE, 0xFF0000);
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
			// if (global->cub_map[y][x] == 'N')
				// draw_all_pixels(global->map->position_x, global->map->position_y, global);
			x++;
		}
		y++;
	}
}

// void	ft_cast_rays(t_all *all)
// {
// 	t_plr	ray = *all->plr; // задаем координаты и направление луча равные координатам игрока
// 	float start = ray.dir - [половина угла обзора]; // начало веера лучей
// 	float end = ray.dir + [половина угла обзора]; // край веера лучей

//   while (ray.start <= ray.end)
// 	{
// 		ray.x = all->plr->x; // каждый раз возвращаемся в точку начала
// 		ray.y = all->plr->y;
// 		while (all->map[(int)(ray.y / SCALE)][(int)(ray.x / SCALE)] != '1')
// 		{
// 			ray.x += cos(ray.start);
// 			ray.y += sin(ray.start);
// 			mlx_pixel_put(all->mlx, all->win, ray.x, ray.y, 0x990099);
// 		}
// 		ray.start += [угол обзора] / [количество лучей];
// 	}
// }


static void		ft_raycast(t_struct *global)
{
	float x;
	float y;
	t_map_res ray = *global->map;

	x = ray.position_x;
	y = ray.position_y;
	// global->start_rays = global->angle_player - (global->angle_player / 2);
	// global->end_rays = global->angle_player + (global->angle_player / 2);
	while (global->cub_map[(int)ray.position_y][(int)ray.position_x] != '1')
	{
		ray.position_x += cos(90);
		ray.position_y += sin(0);
		my_mlx_pixel_put(global->data, ray.position_x * SCALE, ray.position_y * SCALE, 0xFFF000);
		// y -= 0.01;
	}
	// mlx_put_image_to_window(global->mlx, global->mlx_win, global->data->img, 0, 0);
}

int			key_hook(int keycode, t_struct *global)
{
	printf("%d!\n", keycode);
	if (keycode == 53) // esc
		exit(0);
	if (keycode == 125)				// почему так?
		global->map->position_y += 0.5;
	if (keycode == 126)
		global->map->position_y -= 0.5;
	if (keycode == 124)
		global->map->position_x += 0.5;
	if (keycode == 123)
		global->map->position_x -= 0.5;
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

