/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 15:35:28 by gmorra            #+#    #+#             */
/*   Updated: 2021/03/04 18:21:53 by gmorra           ###   ########.fr       */
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

static void		filling_file_screenshot(int fd, t_struct *global)
{
	int	i;
	int	j;
	int	color;

	i = global->map.height;
	while (--i >= 0)
	{
		j = -1;
		while (++j < global->map.width)
		{
			color = *(int*)(global->data.addr + (i * global->data.length
					+ j * (global->data.bpp / 8)));
			write(fd, &color, 4);
		}
	}
}

void			continue_screenshot(t_struct *global, int fd)
{
	int		size_screen;
	int		pos_pixel_data;
	int		zero;
	short	plane;

	plane = 1;
	zero = 0;
	pos_pixel_data = 54;
	size_screen = global->map.width
		* global->map.height * 4 + 54;
	write(fd, "BM", 2);
	write(fd, &size_screen, 4);
	write(fd, &zero, 4);			// \0 \0
	write(fd, &pos_pixel_data, 4);
	pos_pixel_data = 40;
	write(fd, &pos_pixel_data, 4);
	write(fd, &global->map.width, 4);
	write(fd, &global->map.height, 4);
	write(fd, &plane, 2);
	plane = 32;
	write(fd, &plane, 2);
}

void screenshot(t_struct global)
{
	int fd;
	int size_screen;
	int zero;
	int size;

	fd = open("screen.bmp", O_CREAT | O_RDWR, 0666);
	size_screen = global.map.width
		* global.map.height * 4 + 54;
	zero = 0;
	size = global.map.width
		* global.map.height;
	if (fd < 0)
		ft_putstr("Kavo\n");
	continue_screenshot(&global, fd);
	write(fd, &zero, 4);
	write(fd, &size, 4);
	size_screen = 1000;
	write(fd, &size_screen, 4);
	write(fd, &size_screen, 4);
	write(fd, &zero, 4);
	write(fd, &zero, 4);
	filling_file_screenshot(fd, &global);
	close(fd);
}

static	void		do_mlx_stuff(t_struct global, int argc)
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
		screenshot(global);
		exit(0);
	}
	else if (argc < 3)
	{
		mlx_hook(global.mlx_win, 17, 1L << 5, ft_close, &global);
		mlx_hook(global.mlx_win, 2, 1L << 0, &press_key, &global);
		mlx_key_hook(global.mlx_win, &release_key, &global);
		mlx_loop_hook(global.mlx, &key_hook, &global);
		mlx_put_image_to_window(global.mlx, global.mlx_win, global.data.img, 0, 0);
	}
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
	do_mlx_stuff(global, argc);
	write(1, "\033[0;32mcub3D open!\033[0m\n", 23);
	mlx_loop(global.mlx);
}

/*
1111) Цвета в шестнадцатиричную систему
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
