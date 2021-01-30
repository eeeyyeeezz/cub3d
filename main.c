/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 13:52:43 by gmorra            #+#    #+#             */
/*   Updated: 2021/01/30 18:58:38 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void		get_zero(t_struct *global)
{
	global->map->width = 0;
	global->map->height = 0;
	global->map->position_x = 0;
	global->map->position_y = 0;
	global->textures->east = 0;
	global->textures->west = 0;
	global->textures->south = 0;
	global->textures->north = 0;
	global->colors->r_floor = 0;
	global->colors->g_floor = 0;
	global->colors->b_floor = 0;
	global->colors->r_cell = 0;
	global->colors->g_cell = 0;
	global->colors->b_cell = 0;
}

static	void	func_func_baby(t_struct global)
{
	printf("eto y [%d]\n", global.map->position_y);
	printf("eto x [%d]\n", global.map->position_x);
	printf("\nwidth [%d] height [%d]\n", global.map->width, global.map->height);
	printf("r_cell [%d] g_cell [%d] b_cell [%d]\n", global.colors->r_cell, global.colors->g_cell, global.colors->b_cell);
	printf("r_floor [%d] g_floor [%d] b_floor [%d]\n", global.colors->r_floor, global.colors->g_floor, global.colors->b_floor);
	printf("North [%s]\n", global.textures->north);
	printf("South [%s]\n", global.textures->south);
	printf("West  [%s]\n", global.textures->west);
	printf("East  [%s]\n", global.textures->east);
	for (int i = 0; global.cub_map[i] != '\0'; i++)
		printf("eto map [%s]\n", global.cub_map[i]);
}

int			main(int argc, char **argv)
{
	int i;
	// int fd;
	// char *line;
	t_struct	global;
	t_map_res 	map_res;
	t_colors	colors;
	t_textures	texures;

	(void)argc;
	i = 0;
	global.map = &map_res;
	global.colors = &colors;
	global.textures = &texures;
	get_zero(&global);
	pars(&global, argv);
	ft_mlx(&global);
	// func_func_baby(global);
	// printf("check C [%d]\n", ft_strchr("  C    255,150,75", 'C'));
	// printf("check F [%d]\n", ft_strchr("  F    350,250,100", 'F'));
}


/* Problems
1)	Добавить фейл на "F  200,  100,  50" пробелы после запятых || фейла не должно быть
2)	Фейл на < 0 && >255
3)	Strnstr возможен фейл с поднятием флага
4)	Текстуры работают только с "./" просто с "/" не работает
5)	На конце текстур если стоят isspaces то бан (фикс потом)
*/


/* ToDo List
1) С запятыми штуку фикс
2) Проверку на лишнее/недостающее в мапе
3) Проверить на правильно введенные аргументы (RGB >= 0 && RGB <= 255)
4) Проверить что мапа точно в конце

*/
