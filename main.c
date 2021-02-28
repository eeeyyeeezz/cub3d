/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 15:35:28 by gmorra            #+#    #+#             */
/*   Updated: 2021/02/27 20:48:39 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

#define texWidth 64
#define texHeight 64
#define mapWidth  24
#define mapHeight  24

static void		get_zero(t_struct *global)
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

static	void	direction_sight(t_struct *global)
{
	global->draw.move_speed = 0.1;
	global->draw.rot_speed = 0.1;
	if (global->map.is_player == 'N')
	{
		global->draw.dir_x = -1;
		global->draw.plane_y = 0.66;
	}
	if (global->map.is_player == 'S')
	{
		global->draw.dir_x = 1;
		global->draw.plane_y = -0.66;
	}
	if (global->map.is_player == 'W')
	{
		global->draw.dir_y = -1;
		global->draw.plane_x = -0.66;
	}
	if (global->map.is_player == 'E')
	{
		global->draw.dir_y = 1;
		global->draw.plane_x = 0.66;
	}
}

static	void	func_func_baby(t_struct *global)
{
	printf("eto y [%f]\n", global->map.pos_y);
	printf("eto x [%f]\n", global->map.pos_x);
	printf("is player [%c]\n", global->map.is_player);
	printf("\nwidth [%d] height [%d]\n", global->map.width, global->map.height);
	printf("r_cell [%d] g_cell [%d] b_cell [%d]\n", global->colors->r_cell, global->colors->g_cell, global->colors->b_cell);
	printf("r_floor [%d] g_floor [%d] b_floor [%d]\n", global->colors->r_floor, global->colors->g_floor, global->colors->b_floor);
	printf("North [%s]\n", global->textures->north);
	printf("South [%s]\n", global->textures->south);
	printf("West  [%s]\n", global->textures->west);
	printf("East  [%s]\n", global->textures->east);
	printf("Sprite[%s]\n", global->textures->sprite);
	for (int i = 0; global->cub_map[i] != '\0'; i++)
		printf("eto map [%s]\n", global->cub_map[i]);
}

unsigned int	my_mlx_pixel_take(t_data *img, int x, int y)
{
	char			*addr;
	unsigned int	color;

	addr = img->addr + (y * img->length + x * (img->bpp / 8));
	color = *(unsigned int*)addr;
	return (color);
}

static	void		my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

static	void			textures_draw(t_struct *global)
{
	int width;
	int height;

	if (!(global->textures_north.img = mlx_xpm_file_to_image(global->mlx, global->textures->north, &width, &height)))
	{
		ft_putstr("\nError\nWrong north texture\n");
		exit(0);
	}
	global->textures_north.addr = mlx_get_data_addr(global->textures_north.img, &global->textures_north.bpp,
		&global->textures_north.length, &global->textures_north.end);

	if (!(global->textures_south.img = mlx_xpm_file_to_image(global->mlx, global->textures->south, &width, &height)))
	{
		ft_putstr("\nError\nWrong south texture\n");
		exit(0);
	}
	global->textures_south.addr = mlx_get_data_addr(global->textures_south.img, &global->textures_south.bpp,
		&global->textures_south.length, &global->textures_south.end);

	if (!(global->textures_east.img = mlx_xpm_file_to_image(global->mlx, global->textures->east, &width, &height)))
	{
		ft_putstr("\nError\nWrong east texture\n");
		exit(0);
	}
	global->textures_east.addr = mlx_get_data_addr(global->textures_east.img, &global->textures_east.bpp,
		&global->textures_east.length, &global->textures_east.end);

	if (!(global->textures_west.img = mlx_xpm_file_to_image(global->mlx, global->textures->west, &width, &height)))
	{
		ft_putstr("\nError\nWrong west texture\n");
		exit(0);
	}
	global->textures_west.addr = mlx_get_data_addr(global->textures_west.img, &global->textures_west.bpp,
		&global->textures_west.length, &global->textures_west.end);

	if (!(global->sprite_draw.img = mlx_xpm_file_to_image(global->mlx, global->textures->sprite, &width, &height)))
	{
		ft_putstr("\nError\nWrong sprite texture\n");
		exit(0);
	}
	global->sprite_draw.addr = mlx_get_data_addr(global->sprite_draw.img, &global->sprite_draw.bpp,
		&global->sprite_draw.length, &global->sprite_draw.end);
}


void			go_fast(t_struct *global)
{
	if (global->key.q_key == 1 && global->draw.move_speed <= 1.0)
		global->draw.move_speed += + 0.05;
	if (global->key.e_key == 1 && global->draw.move_speed >= 0.1)
		global->draw.move_speed -= 0.05;
}

static	void			init_all(t_struct *global, int x)
{
	global->draw.camera_x = 2 * x / (double)global->map.width - 1;
	global->draw.ray_dir_x = global->draw.dir_x + global->draw.plane_x * global->draw.camera_x;
	global->draw.ray_dir_y = global->draw.dir_y + global->draw.plane_y * global->draw.camera_x;
	global->draw.map_x = (int)global->map.pos_x;
	global->draw.map_y = (int)global->map.pos_y;
	global->draw.delta_dist_x = sqrt(1 + (global->draw.ray_dir_y * global->draw.ray_dir_y) / (global->draw.ray_dir_x * global->draw.ray_dir_x));
	global->draw.delta_dist_y = sqrt(1 + (global->draw.ray_dir_x * global->draw.ray_dir_x) / (global->draw.ray_dir_y * global->draw.ray_dir_y));
	global->draw.hit = 0;
}

static	void			bubble_position_sprite(t_struct *global, int i, int j)
{
	float tmp;
	float position;

	tmp = 0;
	position = 0;
	tmp = global->sprites[j].distance;
	global->sprites[j].distance = global->sprites[i].distance;
	global->sprites[i].distance = tmp;
	position = global->sprites[i].x;
	global->sprites[i].x = global->sprites[j].x;
	global->sprites[j].x = position;
	position = global->sprites[i].y;
	global->sprites[i].y = global->sprites[j].y;
	global->sprites[j].y = position;

}

static	void			sort_sprites(t_struct *global)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < global->map.num_sprites)
	{
		while (j < global->map.num_sprites)
		{
			if (global->sprites[i].distance
					> global->sprites[j].distance)
			{
				bubble_position_sprite(global, i, j);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

static	void			draw(t_struct *global)
{
	int x;
	int y;

	x = 0;
	while (x < global->map.width)
	{
		y = 0;
		init_all(global, x);
		first_ifs(global);
		second_ifs(global, x);
		third_ifs(global);
		while (y < global->map.height)
		{
			if (y < global->draw.draw_start)
				my_mlx_pixel_put(&global->data, x, y, 0xFFFFFF);
			if (y >= global->draw.draw_start && y <= global->draw.draw_end)
			{
				global->draw.tex_y = (int)global->draw.tex_pos & (texHeight - 1);
				global->draw.tex_pos += global->draw.step;
				if (global->draw.side == 0)
				{
					if (global->draw.step_x > 0)
					{
						int color = my_mlx_pixel_take(&global->textures_north, global->draw.tex_x, global->draw.tex_y);
						my_mlx_pixel_put(&global->data, x, y, color);
					}
					else if (global->draw.step_x < 0)
					{
						int color = my_mlx_pixel_take(&global->textures_south, global->draw.tex_x, global->draw.tex_y);
						my_mlx_pixel_put(&global->data, x, y, color);
					}
				}
				if (global->draw.side == 1)
				{
					if (global->draw.step_y > 0)
					{
						int color = my_mlx_pixel_take(&global->textures_west, global->draw.tex_x, global->draw.tex_y);
						my_mlx_pixel_put(&global->data, x, y, color);
					}
					else if (global->draw.step_y < 0)
					{
						int color = my_mlx_pixel_take(&global->textures_east, global->draw.tex_x, global->draw.tex_y);
						my_mlx_pixel_put(&global->data, x, y, color);
					}
				}
			}
			if (y > global->draw.draw_end)
				my_mlx_pixel_put(&global->data, x, y, 0x12376d);
			y++;
		}
	x++;
	}
	for(int i = 0; i < global->map.num_sprites; i++)
	{
		global->sprites[i].distance = ((global->map.pos_x - global->sprites[i].x) * (global->map.pos_x - global->sprites[i].x) +
			(global->map.pos_y - global->sprites[i].y) * (global->map.pos_y - global->sprites[i].y));
	}
	sort_sprites(global);

	#pragma region Comment_Sprite
	for(int i = 0; i < global->map.num_sprites; i++)
	{
	double spriteX = global->sprites[i].x - global->map.pos_x;
	double spriteY = global->sprites[i].y - global->map.pos_y;
	double invDet = 1.0 / (global->draw.plane_x * global->draw.dir_y - global->draw.dir_x * global->draw.plane_y);

	double transformX = invDet * (global->draw.dir_y * spriteX - global->draw.dir_x * spriteY);
	double transformY = invDet * (-global->draw.plane_y * spriteX + global->draw.plane_x * spriteY);

	int spriteScreenX = (int)((global->map.width / 2) * (1 + transformX / transformY));

	int spriteHeight = abs((int)(global->map.height / (transformY)));
	int drawStartY = -spriteHeight / 2 + global->map.height / 2;
	if(drawStartY < 0)
		drawStartY = 0;
	int drawEndY = spriteHeight / 2 + global->map.height / 2;
	if(drawEndY >= global->map.height)
		drawEndY = global->map.height - 1;

	int spriteWidth = abs((int) (global->map.height / (transformY)));
	int drawStartX = -spriteWidth / 2 + spriteScreenX;
	if(drawStartX < 0) drawStartX = 0;
	int drawEndX = spriteWidth / 2 + spriteScreenX;
	if(drawEndX >= global->map.width) drawEndX = global->map.width - 1;

		for(int stripe = drawStartX; stripe < drawEndX; stripe++)
		{
		int texX = (int)(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * texWidth / spriteWidth) / 256;
			if(transformY > 0 && stripe > 0 && stripe < global->map.width && transformY < global->map.every_dist[stripe])
			{
				for(int y = drawStartY; y < drawEndY; y++)
				{
					int d = (y) * 256 - global->map.height * 128 + spriteHeight * 128;
					int texY = ((d * texHeight) / spriteHeight) / 256;
					int color = my_mlx_pixel_take(&global->sprite_draw, texX, texY);
					if (color)
						my_mlx_pixel_put(&global->data, stripe, y, color);
				}
			}
		}
	}

	#pragma endregion Comment_Sprite
}

int		press_key(int keycode, t_struct *global)
{
	if (keycode == 53) // esc
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

int		release_key(int keycode, t_struct *global)
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


int			key_hook(t_struct *global)
{
	mlx_destroy_image(global->mlx, global->data.img);
	up_down(global);
	right_left(global);
	left_rotate(global);
	right_rotate(global);
	go_fast(global);
	global->data.img = mlx_new_image(global->mlx, global->map.width, global->map.height);
	global->data.addr = mlx_get_data_addr(global->data.img, &global->data.bpp, &global->data.length, &global->data.end);
	textures_draw(global);
	draw(global);
	mlx_put_image_to_window(global->mlx, global->mlx_win, global->data.img, 0, 0);
	return (1);
}


int		main(int argc, char **argv)
{
	t_struct global;

	t_map_res 	map_res;
	t_colors	colors;
	t_textures	texures;
	t_sprites	sprites_pars;

	global.map = map_res;
	global.colors = &colors;
	global.textures = &texures;
	global.sprites = &sprites_pars;


	get_zero(&global);
	pars(&global, argv);
	direction_sight(&global);
	func_func_baby(&global);			// prosto check
	// global.map.pos_x = 10;
	// global.map.pos_y = 16;

	global.map.every_dist = malloc(sizeof(double) * global.map.width);
	global.mlx = mlx_init();
	global.mlx_win = mlx_new_window(global.mlx, global.map.width, global.map.height, "cub3D");
	global.data.img = mlx_new_image(global.mlx, global.map.width, global.map.height);
	global.data.addr = mlx_get_data_addr(global.data.img, &global.data.bpp, &global.data.length, &global.data.end);
	textures_draw(&global);
	draw(&global);
	mlx_hook(global.mlx_win, 2, 1L << 0, &press_key, &global);
	mlx_key_hook(global.mlx_win, &release_key, &global);
	mlx_loop_hook(global.mlx, &key_hook, &global);
	mlx_put_image_to_window(global.mlx, global.mlx_win, global.data.img, 0, 0);
	write(1, "\033[0;32mcub3D open!\033[0m\n", 23);
	mlx_loop(global.mlx);
}

// 1111111111111111111111111
// 1000000000000000000000001
// 1011000000000000000000001
// 1001000000000N00000000001
// 1000000000000000000000001
// 1000000000000000000000001
// 1000000000000000000000001
// 1000000000000000000000001
// 1000000000000000000000001
// 1000000000000000000000001
// 1000000000000000000101001
// 1000000000000000000000001
// 1111111111111111111111111

// 1111111111111111111111111
// 1000000000000000000000001
// 1000000000020000002000001
// 1000000000000000000000001
// 1000000000020000002000001
// 1000000N00000000000000001
// 1000000000000001000000001
// 1000000000000000000000001
// 1000011110000000000000001
// 1000011110000000002000001
// 1000000000000000000000011
// 1111111111111111111111111


// 1111111111111111111111111
// 1000000000000000000000001
// 1000000000000000000000001
// 1000000000000N00000000001
// 1000000000000000000000001
// 1000000000000000000000001
// 1000000000000000000000001
// 1000000000000000000000001
// 1000000000000000000000001
// 1000000000000000000000001
// 1000000000000000000000001
// 1000000000000000000000001
// 1111111111111111111111111
