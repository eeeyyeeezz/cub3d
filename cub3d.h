/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 13:53:06 by gmorra            #+#    #+#             */
/*   Updated: 2021/02/15 18:17:07 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "src/get_next_line_cub/get_next_line.h"
# include "src/libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <math.h>
# include <unistd.h>

typedef		struct s_data
{
	void		*img;
	char		*addr;
	int			bpp;
	int			length;
	int			end;
}
					t_data;

typedef		struct s_map
{
	int			width;
	int			height;
	char		side;
	float		position_x;
	float		position_y;
	float		start_rays;
	float		end_rays;
	float		pos_x;
	float		pos_y;

}					t_map_res;

typedef		struct	s_draw
{
	double move_speed;
	double rotation_speed;
	double rot_speed;
}					t_draw;

typedef		struct s_whole
{
	t_data		data;
	t_data		textures_north;
	t_data		textures_south;
	t_data		textures_west;
	t_data		textures_east;
	t_map_res	map;
	t_draw		draw;
	void 		*mlx;
	void 		*mlx_win;
	int			step_x;
	int			step_y;
	float		dir_x;
	float		dir_y;
	float		plane_x;
	float		plane_y;
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
int			get_next_line(int fd, char **line);
void		up_down(t_struct *global, int keycode);
void		right_left(t_struct *global, int keycode);
void		left_rotate(t_struct *global, int keycode);
void		right_rotate(t_struct *global, int keycode);
void		go_fast(t_struct *global, int keycode);

#endif
