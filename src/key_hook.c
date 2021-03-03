/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 17:00:49 by gmorra            #+#    #+#             */
/*   Updated: 2021/03/03 17:14:38 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int			key_hook(t_struct *global)
{
	mlx_destroy_image(global->mlx, global->data.img);
	up_down(global);
	right_left(global);
	left_rotate(global);
	right_rotate(global);
	go_fast(global);
	global->data.img =
		mlx_new_image(global->mlx, global->map.width, global->map.height);
	global->data.addr = mlx_get_data_addr(global->data.img, &global->data.bpp,
		&global->data.length, &global->data.end);
	textures_draw(global);
	draw(global);
	mlx_put_image_to_window(global->mlx,
	global->mlx_win, global->data.img, 0, 0);
	return (1);
}

int			press_key(int keycode, t_struct *global)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 13)
		global->key.w_key = 1;
	if (keycode == 0)
		global->key.a_key = 1;
	if (keycode == 1)
		global->key.s_key = 1;
	if (keycode == 2)
		global->key.d_key = 1;
	if (keycode == 123)
		global->key.left = 1;
	if (keycode == 124)
		global->key.right = 1;
	if (keycode == 12)
		global->key.q_key = 1;
	if (keycode == 14)
		global->key.e_key = 1;
	return (1);
}

int			release_key(int keycode, t_struct *global)
{
	if (keycode == 13)
		global->key.w_key = 0;
	if (keycode == 0)
		global->key.a_key = 0;
	if (keycode == 1)
		global->key.s_key = 0;
	if (keycode == 2)
		global->key.d_key = 0;
	if (keycode == 123)
		global->key.left = 0;
	if (keycode == 124)
		global->key.right = 0;
	if (keycode == 12)
		global->key.q_key = 0;
	if (keycode == 14)
		global->key.e_key = 0;
	return (1);
}

void		go_fast(t_struct *global)
{
	if (global->key.q_key == 1 && global->draw.move_speed <= 1.0)
		global->draw.move_speed += 0.05;
	if (global->key.e_key == 1 && global->draw.move_speed >= 0.1)
		global->draw.move_speed -= 0.05;
}
