/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_zero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 18:26:16 by gmorra            #+#    #+#             */
/*   Updated: 2021/03/03 18:26:36 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static	void		get_zero_two(t_struct *global)
{
	global->colors->r_cell = 0;
	global->colors->g_cell = 0;
	global->colors->b_cell = 0;
	global->key.w_key = 0;
	global->key.s_key = 0;
	global->key.a_key = 0;
	global->key.d_key = 0;
	global->key.q_key = 0;
	global->key.e_key = 0;
	global->key.left = 0;
	global->key.right = 0;
	global->draw.dir_x = 0;
	global->draw.dir_y = 0;
	global->draw.plane_x = 0;
	global->draw.plane_y = 0;
}

void		get_zero(t_struct *global)
{
	global->map.map_num_y = 0;
	global->map.map_to_pars = 0;
	global->map.width = 0;
	global->map.height = 0;
	global->map.pos_x = 0;
	global->map.pos_y = 0;
	global->map.is_player = '!';
	global->map.num_sprites = 0;
	global->textures->east = 0;
	global->textures->west = 0;
	global->textures->south = 0;
	global->textures->north = 0;
	global->colors->r_floor = 0;
	global->colors->g_floor = 0;
	global->colors->b_floor = 0;
	get_zero_two(global);
}
