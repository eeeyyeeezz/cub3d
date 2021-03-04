/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 15:35:28 by gmorra            #+#    #+#             */
/*   Updated: 2021/03/04 14:52:34 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static	void		direction_sight(t_struct *global)
{
	global->draw.move_speed = 0.1;
	global->draw.rot_speed = 0.1;
	if (global->map.is_player == 'N')
	{
		global->draw.dir_x = -1;
		global->draw.plane_y = 0.66;
	}
	if (global->map.is_player == 'S')
	{
		global->draw.dir_x = 1;
		global->draw.plane_y = -0.66;
	}
	if (global->map.is_player == 'W')
	{
		global->draw.dir_y = -1;
		global->draw.plane_x = -0.66;
	}
	if (global->map.is_player == 'E')
	{
		global->draw.dir_y = 1;
		global->draw.plane_x = 0.66;
	}
}

static	void		do_mlx_stuff(t_struct global)
{
	global.mlx_win = mlx_new_window(global.mlx, global.map.width,
	global.map.height, "cub3D");
	global.data.img = mlx_new_image(global.mlx,
	global.map.width, global.map.height);
	global.data.addr = mlx_get_data_addr(global.data.img,
	&global.data.bpp, &global.data.length, &global.data.end);
	textures_draw(&global);
	draw(&global);
	mlx_hook(global.mlx_win, 17, 1L << 5, ft_close, &global);
	mlx_hook(global.mlx_win, 2, 1L << 0, &press_key, &global);
	mlx_key_hook(global.mlx_win, &release_key, &global);
	mlx_loop_hook(global.mlx, &key_hook, &global);
	mlx_put_image_to_window(global.mlx, global.mlx_win, global.data.img, 0, 0);
}

int					main(int argc, char **argv)
{
	t_struct	global;
	t_map_res	map_res;
	t_colors	colors;
	t_textures	texures;
	t_sprites	sprites_pars;

	global.map = map_res;
	global.colors = &colors;
	global.textures = &texures;
	global.sprites = &sprites_pars;
	get_zero(&global);
	pars(&global, argv);
	direction_sight(&global);
	if (!(global.map.every_dist = malloc(sizeof(double) * global.map.width)))
		return (-1);
	if (!(global.mlx = mlx_init()))
		return (-1);
	do_mlx_stuff(global);
	write(1, "\033[0;32mcub3D open!\033[0m\n", 23);
	mlx_loop(global.mlx);
}

/*
1111) Цвета в шестнадцатиричную систему
!!!!)) ЛИКИ!
1) xpm в названии текстуры
2) резолюшн максимальный инт ок
3) пробел в строке		ок
4) F и C если больше 3 числе сосать + лежать и скипнуть нули
5) 2 пустых строки
6) пустая строка и 1 в конце
7) Если одну текстуру вместо второй к примеру два NO и нет SO сегфолт
*/
