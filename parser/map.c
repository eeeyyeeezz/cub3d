/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:59:40 by gmorra            #+#    #+#             */
/*   Updated: 2021/02/24 16:46:04 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	sprite_parser_count(t_struct *global);
void	sprite_parser(t_struct *global);


static	int		to_find_player(t_struct *global)
{
	int 		i;
	int 		a;
	static	int num_player = 0;

	i = 0;
	while (global->cub_map[i])
	{
		a = 0;
		while (global->cub_map[i][a] != '\0')
		{
			if (global->cub_map[i][a] == 'N' || global->cub_map[i][a] == 'S' ||
			global->cub_map[i][a] == 'W' || global->cub_map[i][a] == 'E')
			{
				global->map.pos_y = i;
				global->map.pos_x = a;
				num_player++;
				global->map.is_player = global->cub_map[i][a];
			}
			a++;
		}
		i++;
	}
	return(num_player);
}

void		pars_map(char *line, t_struct *global, int fd)
{
	char *new_line;
	int num_player;

	new_line = ft_strdup(line);
	new_line = ft_strjoin_new(new_line, "*");
	while (line[0] == '1' || line[0] == ' ')
	{
		free(line);
		get_next_line(fd, &line);
		new_line = ft_strjoin_new(new_line, line);
		new_line = ft_strjoin_new(new_line, "*");
	}
	free(line);
	global->cub_map = ft_split(new_line, '*');
	num_player = to_find_player(global);
	sprite_parser_count(global);
	sprite_parser(global);
	if (global->map.is_player == '!' || num_player != 1)
	{
		write(1, "No player is on map or too many\n", 32);
		exit(0);
	}
}

void		sprite_parser_count(t_struct *global)
{
	int x;
	int y;

	y = 0;
	while (global->cub_map[y])
	{
		x = 0;
		while(global->cub_map[y][x])
		{
			if (global->cub_map[y][x] == '2')
				global->map.num_sprites++;
			x++;
		}
		y++;
	}
}

void	sprite_parser(t_struct *global)
{
	int x;
	int y;
	int num_sprites;
	int count;

	y = 0;
	count = 0;
	num_sprites = global->map.num_sprites;
	global->sprites = malloc(sizeof(t_sprites) * num_sprites);
	while (global->cub_map[y])
	{
		x = 0;
		while (global->cub_map[y][x])
		{
			if (global->cub_map[y][x] == '2')
			{
				global->sprites[count].y = (float)x + 0.5f;
				global->sprites[count].x = (float)y + 0.5f;
				count++;
			}
			x++;
		}
		y++;
	}
	// printf("first y [%f] and x [%f]\n", global->sprites[0].y, global->sprites[0].x);

}
