/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 18:18:25 by gmorra            #+#    #+#             */
/*   Updated: 2021/03/05 19:37:00 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static	void			norme_write(int fd, int size_screen, int zero)
{
	write(fd, &size_screen, 4);
	write(fd, &size_screen, 4);
	write(fd, &zero, 4);
	write(fd, &zero, 4);
}

static	int				check_argv(char *line, char *save)
{
	int i;

	i = 0;
	while (line[i] == save[i])
		i++;
	if (line[i - 1] != '\0')
		return (0);
	else
		return (1);
}

static void				screenshot_three(int fd, t_struct *global)
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

static	void			screenshot_two(t_struct *global, int fd)
{
	int		screen_size;
	int		pixel_data;
	int		null;
	short	plane;

	plane = 1;
	null = 0;
	pixel_data = 54;
	screen_size = global->map.width * global->map.height * 4 + 54;
	write(fd, "BM", 2);
	write(fd, &screen_size, 4);
	write(fd, "null", 4);
	write(fd, &pixel_data, 4);
	pixel_data = 40;
	write(fd, &pixel_data, 4);
	write(fd, &global->map.width, 4);
	write(fd, &global->map.height, 4);
	write(fd, &plane, 2);
	plane = 32;
	write(fd, &plane, 2);
}

void					screenshot(t_struct global, char *line)
{
	int fd;
	int size_screen;
	int zero;
	int size;

	if (!check_argv(line, "--save"))
	{
		write(1, "1", 1);
		ft_error(18);
	}
	fd = open("screen.bmp", O_CREAT | O_RDWR, 0666);
	size_screen = global.map.width * global.map.height * 4 + 54;
	zero = 0;
	size = global.map.width * global.map.height;
	if (fd < 0)
		ft_putstr("Error\nWrong fd\n");
	screenshot_two(&global, fd);
	write(fd, &zero, 4);
	write(fd, &size, 4);
	size_screen = 1000;
	norme_write(fd, size_screen, zero);
	screenshot_three(fd, &global);
	close(fd);
}
