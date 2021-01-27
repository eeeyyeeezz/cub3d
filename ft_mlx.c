/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:17:10 by gmorra            #+#    #+#             */
/*   Updated: 2021/01/27 14:45:10 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#define SCALE 10

typedef struct	s_data {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

void		my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void		ft_mlx(t_struct *global)
{
	int x;
	int y;
	// int i;
	char **map;
	void *mlx;
	void *mlx_win;
	t_data img;
	(void)global;

	y = 0;
	x = 0;
	map = global->cub_map;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1200, 1200, "cub3D");
	img.img = mlx_new_image(mlx, 1200, 1200);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
							&img.endian);
	while (map[y] != '\0')
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == '1')
				my_mlx_pixel_put(&img, x, y, 0xFFFFFF);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}


