/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 13:53:06 by gmorra            #+#    #+#             */
/*   Updated: 2021/03/13 16:17:18 by gmorra           ###   ########.fr       */
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

typedef	struct		s_data
{
	void			*img;
	char			*addr;
	int				bpp;
	int				length;
	int				end;
}					t_data;

typedef	struct		s_sprites
{
	float			x;
	float			y;
	float			distance;
}					t_sprites;

typedef	struct		s_map_res
{
	int				map_num_y;
	int				map_to_pars;
	int				width;
	int				height;
	int				num_sprites;
	char			side;
	double			*every_dist;
	float			start_rays;
	float			end_rays;
	float			pos_x;
	float			pos_y;
	char			is_player;
}					t_map_res;

typedef	struct		s_colors
{
	int				r_floor;
	int				g_floor;
	int				b_floor;
	int				r_cell;
	int				g_cell;
	int				b_cell;
	int				floor_hex;
	int				cell_hex;
}					t_colors;

typedef struct		s_textures
{
	char			*sprite;
	char			*north;
	char			*south;
	char			*west;
	char			*east;
}					t_textures;

typedef	struct		s_key
{
	int				w_key;
	int				s_key;
	int				a_key;
	int				d_key;
	int				q_key;
	int				e_key;
	int				left;
	int				right;
}					t_key;

typedef	struct		s_draw
{
	int				hit;
	int				side;
	int				tex_x;
	int				tex_y;
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	int				draw_start;
	int				draw_end;
	int				line_height;
	int				screen_height;
	double			step;
	double			tex_pos;
	double			wall_x;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			move_speed;
	double			rotation_speed;
	double			rot_speed;
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
}					t_draw;

typedef	struct		s_sprites_draw
{
	int				s_tex_x;
	int				s_tex_y;
	int				stripe;
	int				sprite_width;
	int				sprite_sreeen_x;
	int				draw_start_x;
	int				draw_end_x;
	int				draw_start_y;
	int				draw_end_y;
	int				sprite_height;
	int				sprite_screen_x;
	double			sprite_x;
	double			sprite_y;
	double			inv_det;
	double			transform_x;
	double			transform_y;

}					t_sprites_draw;

typedef	struct		s_whole
{
	t_data			data;
	t_data			textures_north;
	t_data			textures_south;
	t_data			textures_west;
	t_data			textures_east;
	t_data			sprite_draw;
	t_key			key;
	t_colors		*colors;
	t_textures		*textures;
	t_sprites		*sprites;
	t_map_res		map;
	t_draw			draw;
	t_sprites_draw	d_spr;
	void			*mlx;
	void			*mlx_win;
	char			**cub_map;
	float			*x_pos_sprite;
	float			*y_pos_sprite;
}					t_struct;

int					mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);
void				screenshot(t_struct global, char *line);
void				direction_sight(t_struct *global);
void				line_error(char *line);
void				check_error_cub(char *line);
void				check_map_trash(t_struct *global);
void				check_error_textures(t_struct *global);
int					ft_close(void);
void				get_zero(t_struct *global);
void				pars(t_struct *global, char **argv);
void				big_screen_size(t_struct *global);
void				pars_resolution(char *line, t_struct *global);
void				first_draw_while(t_struct *global);
int					while_first(t_struct *global, char *line, int res);
void				while_second(t_struct *global, char *line, int i, int res);
void				pars_ceilling(char *line, t_struct *global);
void				pars_floor(char *line, t_struct *global);
void				pars_textures(char *line, t_struct *global);
void				get_sprites_right(t_struct *global);
void				sprite_parser_count(t_struct *global);
int					sprite_parser(t_struct *global);
void				ft_error(int error);
void				pars_map(char *line, t_struct *global, int fd);
int					get_next_line(int fd, char **line);
int					key_hook(t_struct *global);
int					press_key(int keycode, t_struct *global);
int					release_key(int keycode, t_struct *global);
void				go_fast(t_struct *global);
void				up_down(t_struct *global);
void				right_left(t_struct *global);
void				left_rotate(t_struct *global);
void				right_rotate(t_struct *global);
void				first_ifs(t_struct *global);
void				second_ifs(t_struct *global, int x);
void				third_ifs(t_struct *global);
void				fourth_ifs(t_struct *global, int x, int y);
void				init_all(t_struct *global, int x);
void				sort_sprites(t_struct *global);
void				bubble_position_sprite(t_struct *global, int i, int j);
void				draw(t_struct *global);
void				textures_draw(t_struct *global);
unsigned int		my_mlx_pixel_take(t_data *img, int x, int y);
void				my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif
