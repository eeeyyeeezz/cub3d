/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 15:35:28 by gmorra            #+#    #+#             */
/*   Updated: 2021/02/19 19:45:46 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

#define texWidth 64
#define texHeight 64
#define mapWidth  24
#define mapHeight  24

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

static void		get_zero(t_struct *global)
{
	global->map.width = 0;
	global->map.height = 0;
	global->map.pos_x = 0;
	global->map.pos_y = 0;
	global->map.is_player = '!';
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
}

static	void	get_not_zero(t_struct *global)
{
	global->draw.plane_x = 0;
	global->draw.plane_y = 0.66;
	global->draw.move_speed = 0.5;
	global->draw.rot_speed = 0.3;
	global->draw.dir_x = -1;
	global->draw.dir_y = 0;
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
	for (int i = 0; global->cub_map[i] != '\0'; i++)
		printf("eto map [%s]\n", global->cub_map[i]);
}

static	void		my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

static	unsigned int		my_mlx_pixel_take(t_data *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->length + x * (data->bpp / 8));
	return (*(unsigned int*)dst);
}

static	void			textures_draw(t_struct *global)
{
	int width;
	int height;

	global->textures_north.img = mlx_xpm_file_to_image(global->mlx, "textures/north.xpm", &width, &height);
	global->textures_north.addr = mlx_get_data_addr(global->textures_north.img, &global->textures_north.bpp,
		&global->textures_north.length, &global->textures_north.end);
	global->textures_south.img = mlx_xpm_file_to_image(global->mlx, "textures/south.xpm", &width, &height);
	global->textures_south.addr = mlx_get_data_addr(global->textures_south.img, &global->textures_south.bpp,
		&global->textures_south.length, &global->textures_south.end);
	global->textures_east.img = mlx_xpm_file_to_image(global->mlx, "textures/east.xpm", &width, &height);
	global->textures_east.addr = mlx_get_data_addr(global->textures_east.img, &global->textures_east.bpp,
		&global->textures_east.length, &global->textures_east.end);
	global->textures_west.img = mlx_xpm_file_to_image(global->mlx, "textures/west.xpm", &width, &height);
	global->textures_west.addr = mlx_get_data_addr(global->textures_west.img, &global->textures_west.bpp,
		&global->textures_west.length, &global->textures_west.end);

	global->sprite.img = mlx_xpm_file_to_image(global->mlx, "textures/barrel.xpm", &width, &height);
	global->sprite.addr = mlx_get_data_addr(global->sprite.img, &global->sprite.bpp,
		&global->sprite.length, &global->sprite.end);
}

#pragma region ROTATE
void			left_rotate(t_struct *global, int keycode)
{
	double speed = global->draw.rot_speed;
	double oldDirX = global->draw.dir_x;
	if (keycode == 123)
	{
		global->draw.dir_x = global->draw.dir_x * cos(speed) - global->draw.dir_y * sin(speed);
		global->draw.dir_y = oldDirX * sin(speed) + global->draw.dir_y * cos(speed);
		double oldPlaneX = global->draw.plane_x;
		global->draw.plane_x = global->draw.plane_x * cos(speed) - global->draw.plane_y * sin(speed);
		global->draw.plane_y = oldPlaneX * sin(speed) + global->draw.plane_y * cos(speed);
	}
}

void			right_rotate(t_struct *global, int keycode)
{
	double speed = global->draw.rot_speed;
	double oldDirX = global->draw.dir_x;

	if (keycode == 124)
	{
		global->draw.dir_x = global->draw.dir_x * cos(-speed) - global->draw.dir_y * sin(-speed);
		global->draw.dir_y = oldDirX * sin(-speed) + global->draw.dir_y * cos(-speed);
		double oldPlaneX = global->draw.plane_x;
		global->draw.plane_x = global->draw.plane_x * cos(-speed) - global->draw.plane_y * sin(-speed);
		global->draw.plane_y = oldPlaneX * sin(-speed) + global->draw.plane_y * cos(-speed);
	}
}
#pragma endregion ROTATE


#pragma region MOVE


void			up_down(t_struct *global, int keycode)
{
	double moveSpeed = global->draw.move_speed;

	if (keycode == 13)
	{
		if(worldMap[(int)(global->map.pos_x + global->draw.dir_x * moveSpeed)][(int)(global->map.pos_y)] == 0)
			global->map.pos_x += global->draw.dir_x * moveSpeed;
		if(worldMap[(int)(global->map.pos_x)][(int)(global->map.pos_x + global->draw.dir_y * moveSpeed)] == 0)
			global->map.pos_y += global->draw.dir_y * moveSpeed;
	}
	if (keycode == 1)
	{
		if(worldMap[(int)(global->map.pos_x + global->draw.dir_x * moveSpeed)][(int)(global->map.pos_y)] == 0)
			global->map.pos_x -= global->draw.dir_x * moveSpeed;
		if(worldMap[(int)(global->map.pos_x)][(int)(global->map.pos_x + global->draw.dir_y * moveSpeed)] == 0)
			global->map.pos_y -= global->draw.dir_y * moveSpeed;
	}
}

void			right_left(t_struct *global, int keycode)
{
	double moveSpeed = global->draw.move_speed;

	if (keycode == 2)
	{
		if(worldMap[(int)(global->map.pos_x + global->draw.dir_y * moveSpeed)][(int)(global->map.pos_y)] == 0)
			global->map.pos_x += global->draw.dir_y * moveSpeed;
		if(worldMap[(int)(global->map.pos_x)][(int)(global->map.pos_y - global->draw.dir_x * moveSpeed)] == 0)
			global->map.pos_y -= global->draw.dir_x * moveSpeed;

	}
	if (keycode == 0)
	{
		if(worldMap[(int)(global->map.pos_x - global->draw.dir_y * moveSpeed)][(int)(global->map.pos_y)] == 0)
			global->map.pos_x -= global->draw.dir_y * moveSpeed;
		if(worldMap[(int)(global->map.pos_x)][(int)(global->map.pos_y + global->draw.dir_x * moveSpeed)] == 0)
			global->map.pos_y += global->draw.dir_x * moveSpeed;
	}
}
#pragma endregion MOVE

void			go_fast(t_struct *global, int keycode)
{
	if (keycode == 12)
		global->draw.move_speed += + 0.1;
	if (keycode == 14 && global->draw.move_speed >= 0.1)
		global->draw.move_speed -= 0.1;
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

#pragma region ifs

static	void			first_ifs(t_struct *global)
{
	if(global->draw.ray_dir_x < 0)
	{
		global->draw.step_x = -1;
		global->draw.side_dist_x = (global->map.pos_x - global->draw.map_x) * global->draw.delta_dist_x;
	}
	else
	{
		global->draw.step_x = 1;
		global->draw.side_dist_x = (global->draw.map_x + 1.0 - global->map.pos_x) * global->draw.delta_dist_x;
	}
	if(global->draw.ray_dir_y < 0)
	{
		global->draw.step_y = -1;
		global->draw.side_dist_y = (global->map.pos_y - global->draw.map_y) * global->draw.delta_dist_y;
	}
	else
	{
		global->draw.step_y = 1;
		global->draw.side_dist_y = (global->draw.map_y + 1.0 - global->map.pos_y) * global->draw.delta_dist_y;
	}
}

static	void			second_ifs(t_struct *global)
{
	while (global->draw.hit == 0)
	{
		if(global->draw.side_dist_x < global->draw.side_dist_y)
		{
			global->draw.side_dist_x += global->draw.delta_dist_x;
			global->draw.map_x += global->draw.step_x;
			global->draw.side = 0;
		}
	else
	{
		global->draw.side_dist_y += global->draw.delta_dist_y;
		global->draw.map_y += global->draw.step_y;
		global->draw.side = 1;
	}
	if(worldMap[global->draw.map_x][global->draw.map_y] > 0)
		global->draw.hit = 1;
	}
	if(global->draw.side == 0)
		global->draw.perp_wall_dist = (global->draw.map_x - global->map.pos_x + (1 - global->draw.step_x) / 2) / global->draw.ray_dir_x;
	else
		global->draw.perp_wall_dist = (global->draw.map_y - global->map.pos_y + (1 - global->draw.step_y) / 2) / global->draw.ray_dir_y;
	global->draw.line_height = (int)(global->map.height / global->draw.perp_wall_dist);
	global->draw.draw_start = -global->draw.line_height / 2 + global->map.height / 2;
}

static	void			third_ifs(t_struct *global)
{
	if(global->draw.draw_start < 0)
		global->draw.draw_start = 0;
	global->draw.draw_end = global->draw.line_height / 2 + global->map.height / 2;
	if(global->draw.draw_end >= global->map.height)
		global->draw.draw_end = global->map.height - 1;
	if(global->draw.side == 0)
		global->draw.wall_x = global->map.pos_x + global->draw.perp_wall_dist * global->draw.ray_dir_y;
	else
		global->draw.wall_x = global->map.pos_y + global->draw.perp_wall_dist * global->draw.ray_dir_x;
	global->draw.wall_x -= floor((global->draw.wall_x));
	global->draw.tex_x = (int)(global->draw.wall_x * (double)(texWidth));
	if(global->draw.side == 0 && global->draw.ray_dir_x > 0)
		global->draw.tex_x = texWidth - global->draw.tex_x - 1;
	if(global->draw.side == 1 && global->draw.ray_dir_y < 0)
		global->draw.tex_x = texWidth - global->draw.tex_x - 1;
	global->draw.step = 1.0 * texHeight / global->draw.line_height;
	global->draw.tex_pos = (global->draw.draw_start - global->map.height / 2 + global->draw.line_height / 2) * global->draw.step;
}

#pragma endregion ifs

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
		second_ifs(global);
		third_ifs(global);

		while (y < global->map.height)
		{
			if (y >= 0 && y <= global->draw.draw_start)
				my_mlx_pixel_put(&global->data, x, y, 0xFFFFFF);
			if (y >= global->draw.draw_start && y <= global->draw.draw_end)
			{
				int texY = (int)global->draw.tex_pos & (texHeight - 1);
				global->draw.tex_pos += global->draw.step;

				if (global->draw.side == 0)
				{
					if (global->draw.step_x > 0)
					{
						unsigned int color = my_mlx_pixel_take(&global->textures_north, global->draw.tex_x, texY);
						my_mlx_pixel_put(&global->data, x, y, color);
					}
					else if (global->draw.step_x < 0)
					{
						unsigned int color = my_mlx_pixel_take(&global->textures_south, global->draw.tex_x, texY);
						my_mlx_pixel_put(&global->data, x, y, color);

					}
				}
				if (global->draw.side == 1)
				{
					if (global->draw.step_y > 0)
					{
						unsigned int color = my_mlx_pixel_take(&global->textures_west, global->draw.tex_x, texY);
						my_mlx_pixel_put(&global->data, x, y, color);
					}
					else if (global->draw.step_y < 0)
					{
						unsigned int color = my_mlx_pixel_take(&global->textures_east, global->draw.tex_x, texY);
						my_mlx_pixel_put(&global->data, x, y, color);
					}
				}
			}
			if (y >= global->draw.draw_end && y <= global->map.height)
				my_mlx_pixel_put(&global->data, x, y, 0x12376d);
			y++;
		}
	x++;
	}
	// for(int i = 0; i < numSprites; i++)
    // {
    //   spriteOrder[i] = i;
    //   spriteDistance[i] = ((posX - sprite[i].x) * (posX - sprite[i].x) + (posY - sprite[i].y) * (posY - sprite[i].y)); //sqrt not taken, unneeded
    // }
    // sortSprites(spriteOrder, spriteDistance, numSprites);

    //after sorting the sprites, do the projection and draw them
	#pragma region Comment_Sprite
    for(int i = 0; i < /*numSprites*/1; i++)
    {
      //translate sprite position to relative to camera
      double spriteX = /*sprite[spriteOrder[i]].x*/5 - global->map.pos_x;
      double spriteY = /*sprite[spriteOrder[i]].y*/3 - global->map.pos_y;

      //transform sprite with the inverse camera matrix
      // [ planeX   dirX ] -1                                       [ dirY      -dirX ]
      // [               ]       =  1/(planeX*dirY-dirX*planeY) *   [                 ]
      // [ planeY   dirY ]                                          [ -planeY  planeX ]

      double invDet = 1.0 / (global->draw.plane_x * global->draw.dir_y - global->draw.dir_x * global->draw.plane_y); //required for correct matrix multiplication

      double transformX = invDet * (global->draw.dir_y * spriteX - global->draw.dir_x * spriteY);
      double transformY = invDet * (-global->draw.plane_y * spriteX + global->draw.plane_x * spriteY); //this is actually the depth inside the screen, that what Z is in 3D, the distance of sprite to player, matching sqrt(spriteDistance[i])

      int spriteScreenX = (int)((global->map.width / 2) * (1 + transformX / transformY));

      //parameters for scaling and moving the sprites
      #define uDiv 1
      #define vDiv 1
      #define vMove 0.0
      int vMoveScreen = (int)(vMove / transformY);

      //calculate height of the sprite on screen
      int spriteHeight = abs((int)(global->map.height / (transformY))) / vDiv; //using "transformY" instead of the real distance prevents fisheye
      //calculate lowest and highest pixel to fill in current stripe
      int drawStartY = -spriteHeight / 2 + global->map.height / 2 + vMoveScreen;
      if(drawStartY < 0) drawStartY = 0;
      int drawEndY = spriteHeight / 2 + global->map.height / 2 + vMoveScreen;
      if(drawEndY >= global->map.height) drawEndY = global->map.height - 1;

      //calculate width of the sprite
      int spriteWidth = abs((int)(global->map.height / (transformY))) / uDiv;
      int drawStartX = -spriteWidth / 2 + spriteScreenX;
      if(drawStartX < 0) drawStartX = 0;
      int drawEndX = spriteWidth / 2 + spriteScreenX;
      if(drawEndX >= global->map.width) drawEndX = global->map.width - 1;

      //loop through every vertical stripe of the sprite on screen
      for(int stripe = drawStartX; stripe < drawEndX; stripe++)
      {
        int texX = (int)(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * texWidth / spriteWidth) / 256;
        //the conditions in the if are:
        //1) it's in front of camera plane so you don't see things behind you
        //2) it's on the screen (left)
        //3) it's on the screen (right)
        //4) ZBuffer, with perpendicular distance
        if(transformY > 0 && stripe > 0 && stripe < global->map.width)//&& transformY < ZBuffer[stripe])
		{
	        for(int y = drawStartY; y < drawEndY; y++) //for every pixel of the current stripe
	        {
	          int d = (y-vMoveScreen) * 256 - global->map.height * 128 + spriteHeight * 128; //256 and 128 factors to avoid floats
	          int texY = ((d * texHeight) / spriteHeight) / 256;
	          unsigned int color = my_mlx_pixel_take(&global->sprite, texX, texY);/*texture[sprite[spriteOrder[i]].texture][texWidth * texY + texX];*/ //get current color from the texture
	          my_mlx_pixel_put(&global->sprite, texX, texY, color);
			//   if((color & 0x00FFFFFF) != 0)
			  	// buffer[y][stripe] = color; //paint pixel if it isn't black, black is the invisible color
	        }
		}
      }
	}
	#pragma endregion Comment_Sprite
}

int			key_hook(int keycode, t_struct *global)
{
	mlx_destroy_image(global->mlx, global->data.img);
	printf("%d!\n", keycode);
	if (keycode == 53) // esc
		exit(0);
	up_down(global, keycode);
	right_left(global, keycode);
	left_rotate(global, keycode);
	right_rotate(global, keycode);
	go_fast(global, keycode);
	global->data.img = mlx_new_image(global->mlx, global->map.width, global->map.height);
	global->data.addr = mlx_get_data_addr(global->data.img, &global->data.bpp, &global->data.length, &global->data.end);
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
	global.map = map_res;
	global.colors = &colors;
	global.textures = &texures;

	get_not_zero(&global);
	get_zero(&global);
	pars(&global, argv);
	func_func_baby(&global);			// prosto check
	global.map.pos_x = 10;
	global.map.pos_y = 12;

	global.mlx = mlx_init();
	global.mlx_win = mlx_new_window(global.mlx, global.map.width, global.map.height, "cub3D");
	global.data.img = mlx_new_image(global.mlx, global.map.width, global.map.height);
	global.data.addr = mlx_get_data_addr(global.data.img, &global.data.bpp, &global.data.length, &global.data.end);
	textures_draw(&global);
	draw(&global);
	mlx_hook(global.mlx_win, 2, 1L<<0, key_hook, &global);
	mlx_put_image_to_window(global.mlx, global.mlx_win, global.data.img, 0, 0);
	write(1, "\033[0;32mcub3D open!\033[0m\n", 23);
	mlx_loop(global.mlx);
}
