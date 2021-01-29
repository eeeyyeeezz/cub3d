/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:17:10 by gmorra            #+#    #+#             */
/*   Updated: 2021/01/27 20:27:55 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#define SCALE 20

static	void		my_mlx_pixel_put(t_struct *data, int x, int y, int color)
{
	char	*dst;

	dst = data->map->addr + (y * data->map->line_length + x * (data->map->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

static	void		draw_all_pixels(int x, int y, t_struct img, char **map)
{
	int	i;
	int j;

	j = y * SCALE;
	while (j < y * SCALE + SCALE)
	{
		i = x * SCALE;
		while (i < x * SCALE + SCALE)
		{
			my_mlx_pixel_put(&img, i, j, 0xFFFFFF);
			i++;
		}
		j++;
	}

}

void		ft_mlx(t_struct *global)
{
	int x;
	int y;
	char **map;
	void *mlx;
	void *mlx_win;
	t_struct img;
	(void)global;

	y = 0;
	x = 0;
	map = global->cub_map;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 2000, 1000, "cub3D");
	img.map->img = mlx_new_image(mlx, 2000, 1000);
	img.map->addr = mlx_get_data_addr(img.map->img, &img.map->bits_per_pixel,
			&img.map->line_length, &img.map->endian);
	while (map[y] != '\0')
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == '1')
				draw_all_pixels(x + 20, y + 20, img, map);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.map->img, 0, 0);
	mlx_loop(mlx);
}



// while (j < y * SCALE + SCALE)
	// {
	// 	i = x * SCALE;
	// 	while (i < x * SCALE + SCALE)
	// 	{
	// 		my_mlx_pixel_put(&img, img.map->position_x, img.map->position_y, 0xFF0000);
	// 		i++;
	// 	}
	// 	j++;
	// }

