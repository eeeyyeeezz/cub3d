/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 15:35:28 by gmorra            #+#    #+#             */
/*   Updated: 2021/03/05 19:38:01 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


static	void		do_mlx_stuff(t_struct global, int argc, char **argv)
{
	global.mlx_win = mlx_new_window(global.mlx, global.map.width,
	global.map.height, "cub3D");
	global.data.img = mlx_new_image(global.mlx,
	global.map.width, global.map.height);
	global.data.addr = mlx_get_data_addr(global.data.img,
	&global.data.bpp, &global.data.length, &global.data.end);
	if (argc == 3)
	{
		textures_draw(&global);
		draw(&global);
		screenshot(global, argv[2]);
		exit(0);
	}
	else if (argc == 2)
	{
		mlx_hook(global.mlx_win, 17, 1L << 5, ft_close, &global);
		mlx_hook(global.mlx_win, 2, 1L << 0, &press_key, &global);
		mlx_key_hook(global.mlx_win, &release_key, &global);
		mlx_loop_hook(global.mlx, &key_hook, &global);
		mlx_put_image_to_window(global.mlx, global.mlx_win, global.data.img, 0, 0);
	}
	else
		ft_error(18);
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
	do_mlx_stuff(global, argc, argv);
	write(1, "\033[0;32mcub3D open!\033[0m\n", 23);
	mlx_loop(global.mlx);
}

/*
1111) Цвета в шестнадцатиричную систему	все гуд в общем
!!!!)) ЛИКИ!
@@@) поменять сортировку
1) xpm в названии текстуры
2) резолюшн максимальный инт ок
3) пробел в строке		ок
4) F и C если больше 3 числе сосать + лежать и скипнуть нули
5) 2 пустых строки
6) пустая строка и 1 в конце
7) Если одну текстуру вместо второй к примеру два NO и нет SO сегфолт
*/
