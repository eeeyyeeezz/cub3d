/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 16:47:50 by gmorra            #+#    #+#             */
/*   Updated: 2021/03/11 15:34:47 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void			spaces_zero(t_struct *global, int i, int j)
{
	if ((global->cub_map[i][j] == '0' ||
	global->cub_map[i][j] == '2' ||
	global->cub_map[i][j] == 'S' ||
	global->cub_map[i][j] == 'W' ||
	global->cub_map[i][j] == 'N' ||
	global->cub_map[i][j] == 'E') &&
	i != global->map.map_num_y - 1)
	{
		if (ft_strlen(global->cub_map[i - 1]) < j)
			ft_error(12);
		if (ft_strlen(global->cub_map[i + 1]) < j)
			ft_error(12);
		if (global->cub_map[i][j + 1] == ' ' ||
		global->cub_map[i][j - 1] == ' ' ||
		global->cub_map[i + 1][j] == ' ' ||
		global->cub_map[i - 1][j] == ' ' ||
		global->cub_map[i + 1][j - 1] == ' ' ||
		global->cub_map[i + 1][j + 1] == ' ' ||
		global->cub_map[i - 1][j - 1] == ' ' ||
		global->cub_map[i - 1][j + 1] == ' ')
			ft_error(15);
	}
}

static	void		norme_check(t_struct *global)
{
	int i;
	int j;

	j = 0;
	i = global->map.map_num_y - 1;
	while (global->cub_map[i][j] == '1' || global->cub_map[i][j] == ' ')
		j++;
	if (j != ft_strlen(global->cub_map[i]))
		ft_error(12);
}

static	void		check_map(t_struct *global)
{
	int len;
	int i;
	int j;

	i = 0;
	j = 0;
	while (global->cub_map[0][j] == '1' || global->cub_map[0][j] == ' ')
		j++;
	if (global->cub_map[0][j] != '\0')
		ft_error(12);
	while (++i < global->map.map_num_y - 1)
	{
		j = -1;
		len = ft_strlen(global->cub_map[i]) - 1;
		if (!(global->cub_map[i][0] == '1' || global->cub_map[i][0] == ' ') ||
			!(global->cub_map[i][len] == '1' || global->cub_map[i][len] == ' '))
			ft_error(12);
		while (global->cub_map[i][++j] != '\0')
			spaces_zero(global, i, j);
	}
	norme_check(global);
}

static	void		diff_pars(char *line, t_struct *global, int fd)
{
	if (ft_strnstr(line, "R"))
		pars_resolution(line, global);
	else if (ft_strnstr(line, "C"))
		pars_ceilling(line, global);
	else if (ft_strnstr(line, "F"))
		pars_floor(line, global);
	else if (ft_strnstr(line, "NO") || ft_strnstr(line, "SO") ||
	ft_strnstr(line, "WE") || ft_strnstr(line, "EA") || ft_strnstr(line, "S"))
		pars_textures(line, global);
	else if (ft_ft_strnstr(line, "1") || ft_ft_strnstr(line, "0") ||
		ft_ft_strnstr(line, " "))
		pars_map(line, global, fd);
	else if (line)
		line_error(line);
}

void				pars(t_struct *global, char **argv)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	line = NULL;
	fd = open(argv[1], O_RDONLY);
	check_error_cub(argv[1]);
	while (get_next_line(fd, &line) == 1)
		diff_pars(line, global, fd);
	check_error_textures(global);
	check_map(global);
	check_map_trash(global);
	free(line);
}
