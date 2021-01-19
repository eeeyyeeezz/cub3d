/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 13:53:06 by gmorra            #+#    #+#             */
/*   Updated: 2021/01/19 20:10:51 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "src/get_next_line/get_next_line.h"
# include "libft/libft.h"
// # include "src/get_next_line/get_next_line_bonus.h"
# include <stdio.h>
# include <mlx.h>
# include <mlx.h>
# include <fcntl.h>
# include <math.h>

typedef		struct s_map
{
	int		width;
	int		height;
}
					t_map;

typedef		struct s_colors
{
	int		r_floor;
	int		g_floor;
	int		b_floor;
	int		r_cell;
	int		g_cell;
	int		b_cell;
}					t_colors;

typedef		struct s_whole
{
	t_map map;
	t_colors colors;
}					t_struct;


#endif
