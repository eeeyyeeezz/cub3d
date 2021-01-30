/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:17:10 by gmorra            #+#    #+#             */
/*   Updated: 2021/01/30 18:59:12 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#define SCALE 20

typedef struct  s_vars {
	void		*mlx;
	void		*win;
}				t_vars;


static	void		my_mlx_pixel_put(t_struct *data, int x, int y, int color)
{
	char	*dst;

	dst = data->map->addr + (y * data->map->length + x * (data->map->bpp / 8));
	*(unsigned int*)dst = color;
}

static	void		draw_all_pixels(int x, int y, t_struct img, char **map, t_struct *global)
{
	int	i;
	int j;
	int save;

	j = y * SCALE;
	save = j;

	my_mlx_pixel_put(&img, global->map->position_x * SCALE, global->map->position_y * SCALE, 0xFF0000);
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

int			key_hook(t_vars *vars)
{
	printf("fuck me!\n");
	return (0);
}

int			ft_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (1);
}

void		ft_mlx(t_struct *global)
{
	int x;
	int y;
	char **map;
	void *mlx;
	void *mlx_win;
	t_struct img;
 	t_vars	vars;

	y = 0;
	x = 0;
	if (!(mlx = mlx_init()))
		return ;
	mlx_win = mlx_new_window(mlx, 2000, 900, "cub3D");
	img.map->img = mlx_new_image(mlx, 2000, 900);
	img.map->addr = mlx_get_data_addr(img.map->img, &img.map->bpp, &img.map->length, &img.map->end);
	// mlx_key_hook(vars.win, key_hook, &vars);
	while (global->cub_map[y] != NULL)
	{
		x = 0;
		while (global->cub_map[y][x] != '\0')
		{
			if (global->cub_map[y][x] == '1')
				draw_all_pixels(x, y, img, map, global);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.map->img, 600, 300);
	write(1, "1", 1);
	mlx_loop(mlx);
	write(1, "1", 1);
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

