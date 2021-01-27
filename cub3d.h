/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 13:53:06 by gmorra            #+#    #+#             */
/*   Updated: 2021/01/27 17:26:31 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "src/get_next_line/get_next_line.h"
# include "src/libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include <mlx.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <math.h>

typedef		struct s_map
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
	int			position_x;
	int			position_y;
}
					t_map_res;

typedef		struct s_colors
{
	int		r_floor;
	int		g_floor;
	int		b_floor;
	int		r_cell;
	int		g_cell;
	int		b_cell;
}					t_colors;

typedef		struct s_textures
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
}					t_textures;

typedef		struct s_whole
{
	t_map_res	*map;
	t_colors	*colors;
	t_textures	*textures;
	char		**cub_map;
}					t_struct;

void		pars(t_struct *global, char **argv);
void		pars_resolution(char *line, t_struct *global);
void		pars_ceilling(char *line, t_struct *global);
void		pars_floor(char *line, t_struct *global);
void		pars_north(char *line, t_struct *global);
void		pars_south(char *line, t_struct *global);
void		pars_west(char *line, t_struct *global);
void		pars_east(char *line, t_struct *global);
void		pars_map(char *line, t_struct *global, int fd);
void        ft_mlx(t_struct *global);


#endif
