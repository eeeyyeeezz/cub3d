/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:53:32 by gmorra            #+#    #+#             */
/*   Updated: 2021/03/13 15:05:58 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	line_error(char *line)
{
	if (line[0] == '\0')
	{
		free(line);
		return ;
	}
	else
		ft_error(16);
}

void	check_error_cub(char *line)
{
	int len;

	len = ft_strlen(line);
	if (!ft_ft_strnstr(line, ".cub") || ft_strlen(line) <= 4)
		ft_error(17);
	if (line[len - 1] != 'b' && line[len - 2] != 'u'
	&& line[len - 2] != 'c' && line[len - 3] != '.')
		ft_error(17);
}

void	check_map_trash(t_struct *global)
{
	int x;
	int y;

	y = 0;
	while (y < global->map.map_num_y)
	{
		x = 0;
		while (global->cub_map[y][x] != '\0')
		{
			if (global->cub_map[y][x] != ' ' &&
			global->cub_map[y][x] != '0' &&
			global->cub_map[y][x] != '1' &&
			global->cub_map[y][x] != '2' &&
			global->cub_map[y][x] != 'S' &&
			global->cub_map[y][x] != 'N' &&
			global->cub_map[y][x] != 'W' &&
			global->cub_map[y][x] != 'E')
				ft_error(23);
			x++;
		}
		y++;
	}
}

void	check_error_textures(t_struct *global)
{
	if (global->textures->north == NULL ||
		global->textures->south == NULL ||
		global->textures->west == NULL ||
		global->textures->east == NULL ||
		global->textures->sprite == NULL)
		ft_error(22);
	if (!ft_ft_strnstr(global->textures->north, ".xpm"))
		ft_error(20);
	else if (!ft_ft_strnstr(global->textures->south, ".xpm"))
		ft_error(20);
	else if (!ft_ft_strnstr(global->textures->west, ".xpm"))
		ft_error(20);
	else if (!ft_ft_strnstr(global->textures->east, ".xpm"))
		ft_error(20);
}
