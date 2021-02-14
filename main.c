# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <math.h>
# include <unistd.h>


#define screenWidth 1920
#define screenHeight 1080
#define mapWidth 24
#define mapHeight 24
#define texWidth 64
#define texHeight 64

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

typedef		struct s_whole
{
	t_data		data;
	t_data		textures_data;
	t_map_res	map;
	void 		*mlx;
	void 		*mlx_win;
	int			step_x;
	int			step_y;
	float		dir_x;
	float		dir_y;
	float		plane_x;
	float		plane_y;

}					t_struct;


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

static	void		my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void			textures_draw(t_struct *global)
{
	global->textures_data.img = mlx_xpm_file_to_image(global->mlx, "textures/south.xpm", 10, 10);
	


}

void			draw(t_struct *global)
{
	int x;

	x = 0;
	while(x < screenWidth)
	{
		//calculate ray position and direction
		double cameraX = 2 * x / (double)screenWidth - 1; //x-coordinate in camera space
		double rayDirX = global->dir_x + global->plane_x * cameraX;
		double rayDirY = global->dir_y + global->plane_y * cameraX;
		//which box of the map we're in
		int mapX = (int)global->map.pos_x;
		int mapY = (int)global->map.pos_y;

		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;

		//length of ray from one x or y-side to next x or y-side
		double deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
		double deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));

		double perpWallDist;

		//what direction to step in x or y-direction (either +1 or -1)
		// int stepX;
		// int stepY;

		int hit = 0; 		//was there a wall hit?
		int side; 			//was a NS or a EW wall hit?

		//calculate step and initial sideDist

		if(rayDirX < 0)
		{
			global->step_x = -1;
			sideDistX = (global->map.pos_x - mapX) * deltaDistX;
		}
		else
		{
			global->step_x = 1;
			sideDistX = (mapX + 1.0 - global->map.pos_x) * deltaDistX;
		}
		if(rayDirY < 0)
		{
			global->step_y = -1;
			sideDistY = (global->map.pos_y - mapY) * deltaDistY;
		}
		else
		{
			global->step_y = 1;
			sideDistY = (mapY + 1.0 - global->map.pos_y) * deltaDistY;
		}
	 	//perform DDA
	 	while (hit == 0)
	 	{
	 	  //jump to next map square, OR in x-direction, OR in y-direction
			if(sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += global->step_x;
				side = 0;
			}
		else
		{
			sideDistY += deltaDistY;
			mapY += global->step_y;
			side = 1;
		}
		//Check if ray has hit a wall
		if(worldMap[mapX][mapY] > 0) hit = 1;
		}
		//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
		if(side == 0)
			perpWallDist = (mapX - global->map.pos_x + (1 - global->step_x) / 2) / rayDirX;
		else
			perpWallDist = (mapY - global->map.pos_y + (1 - global->step_y) / 2) / rayDirY;

		//Calculate height of line to draw on screen
		int lineHeight = (int)(screenHeight / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + screenHeight / 2;
		if(drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + screenHeight / 2;
		if(drawEnd >= screenHeight)
			drawEnd = screenHeight - 1;
		int y = 0;

		double wallX; //where exactly the wall was hit

		if(side == 0)
			wallX = global->map.position_x + perpWallDist * rayDirY;
		else
			wallX = global->map.position_y + perpWallDist * rayDirX;
		wallX -= floor((wallX));

		//x coordinate on the texture
		int texX = (int)wallX * (double)texWidth;
		if(side == 0 && rayDirX > 0)
			texX = texWidth - texX - 1;
		if(side == 1 && rayDirY < 0)
				texX = texWidth - texX - 1;

		// TODO: an integer-only bresenham or DDA like algorithm could make the texture coordinate stepping faster
		// How much to increase the texture coordinate per screen pixel
		double step = 1.0 * texHeight / lineHeight;
		// Starting texture coordinate
		double texPos = (drawStart - screenHeight / 2 + lineHeight / 2) * step;

		while (y < screenHeight)
		{
			if (y >= drawStart && y <= drawEnd)
			{
				if (side == 0)				// S N
				{
					if (global->step_x > 0)
						my_mlx_pixel_put(&global->data, x, y, 0xFF0000);
					else if (global->step_x < 0)
						my_mlx_pixel_put(&global->data, x, y, 0x00FF00);
				}
				if (side == 1)				// W E
				{
					if (global->step_y > 0)
						my_mlx_pixel_put(&global->data, x, y, 0x0000FF);
					else if (global->step_y < 0)
						my_mlx_pixel_put(&global->data, x, y, 0xFFFFFF);
				}
			}
			y++;
		}
		x++;
	}
}

int			key_hook(int keycode, t_struct *global)
{
	float moveSpeed = 0.5;
	float rotationSpeed = 0.1;
	double rotSpeed = 0.2;

	mlx_destroy_image(global->mlx, global->data.img);
	printf("%d!\n", keycode);
	if (keycode == 53) // esc
		exit(0);
	if (keycode == 13)		// up
	{
		if(worldMap[(int)(global->map.pos_x + global->dir_x * moveSpeed)][(int)(global->map.pos_y)] == 0)
			global->map.pos_x += global->dir_x * moveSpeed;
		if(worldMap[(int)(global->map.pos_x)][(int)(global->map.pos_x + global->dir_y * moveSpeed)] == 0)
			global->map.pos_y += global->dir_y * moveSpeed;
	}
	if (keycode == 1)		// down
	{
		if(worldMap[(int)(global->map.pos_x + global->dir_x * moveSpeed)][(int)(global->map.pos_y)] == 0)
			global->map.pos_x -= global->dir_x * moveSpeed;
		if(worldMap[(int)(global->map.pos_x)][(int)(global->map.pos_x + global->dir_y * moveSpeed)] == 0)
			global->map.pos_y -= global->dir_y * moveSpeed;
	}
	if (keycode == 2)		// right
	{
		if(worldMap[(int)(global->map.pos_x + global->dir_y * moveSpeed)][(int)(global->map.pos_y)] == 0)
			global->map.pos_x += global->dir_y * moveSpeed;
		if(worldMap[(int)(global->map.pos_x)][(int)(global->map.pos_y - global->dir_x * moveSpeed)] == 0)
			global->map.pos_y -= global->dir_x * moveSpeed;

	}
	if (keycode == 0)		// left
	{
		if(worldMap[(int)(global->map.pos_x - global->dir_y * moveSpeed)][(int)(global->map.pos_y)] == 0)
			global->map.pos_x -= global->dir_y * moveSpeed;
		if(worldMap[(int)(global->map.pos_x)][(int)(global->map.pos_y + global->dir_x * moveSpeed)] == 0)
			global->map.pos_y += global->dir_x * moveSpeed;
	}
	if (keycode == 40)				// 'k'
	{
		if(worldMap[(int)(global->map.pos_x + global->dir_x * moveSpeed)][(int)(global->map.pos_y)] == 0)
			global->dir_x += global->dir_x * moveSpeed;
		if(worldMap[(int)(global->map.pos_x)][(int)(global->map.pos_x + global->dir_y * moveSpeed)] == 0)
			global->dir_y += global->dir_y * moveSpeed;
	}
	if (keycode == 37)			// 'l'
	{
		if(worldMap[(int)(global->map.pos_x + global->dir_x * moveSpeed)][(int)(global->map.pos_y)] == 0)
			global->dir_x -= global->dir_x * moveSpeed;
		if(worldMap[(int)(global->map.pos_x)][(int)(global->map.pos_x + global->dir_y * moveSpeed)] == 0)
			global->dir_y -= global->dir_y * moveSpeed;
	}
	if (keycode == 123)		// left rotate
	{
		//   both camera direction and camera plane must be rotated
		double oldDirX = global->dir_x;
		global->dir_x = global->dir_x * cos(rotSpeed) - global->dir_y * sin(rotSpeed);
		global->dir_y = oldDirX * sin(rotSpeed) + global->dir_y * cos(rotSpeed);
		double oldPlaneX = global->plane_x;
		global->plane_x = global->plane_x * cos(rotSpeed) - global->plane_y * sin(rotSpeed);
		global->plane_y = oldPlaneX * sin(rotSpeed) + global->plane_y * cos(rotSpeed);
	}
	if (keycode == 124)		// right rotate
	{
		//  both camera direction and camera plane must be rotated
		double oldDirX = global->dir_x;
		global->dir_x = global->dir_x * cos(-rotSpeed) - global->dir_y * sin(-rotSpeed);
		global->dir_y = oldDirX * sin(-rotSpeed) + global->dir_y * cos(-rotSpeed);
		double oldPlaneX = global->plane_x;
		global->plane_x = global->plane_x * cos(-rotSpeed) - global->plane_y * sin(-rotSpeed);
		global->plane_y = oldPlaneX * sin(-rotSpeed) + global->plane_y * cos(-rotSpeed);
	}
	if (keycode == 12)			// q
		moveSpeed += 0.1;
	if (keycode == 14)			// e
		moveSpeed -= 0.1;
	global->data.img = mlx_new_image(global->mlx, screenWidth, screenHeight);
	global->data.addr = mlx_get_data_addr(global->data.img, &global->data.bpp, &global->data.length, &global->data.end);
	draw(global);
	mlx_put_image_to_window(global->mlx, global->mlx_win, global->data.img, 0, 0);
	return (1);
}


int		main(int argc, char **argv)
{
	t_struct global;

	global.map.pos_x = 22;
	global.map.pos_y = 12;
	global.dir_x = -1;
	global.dir_y = 0;
	global.plane_x = 0;
	global.plane_y = 0.66;
	double time = 0;
	double oldTime = 0;

	if (global.map.side == 'N')
		global.dir_x = -1;
	if (global.map.side == 'S')
		global.dir_x = -1;
	if (global.map.side == 'W')
		global.dir_x = -1;
	if (global.map.side == 'W')
		global.dir_x = -1;

	global.mlx = mlx_init();
	global.mlx_win = mlx_new_window(global.mlx, screenWidth, screenHeight, "cub3D");
	global.data.img = mlx_new_image(global.mlx, screenWidth, screenHeight);
	global.data.addr = mlx_get_data_addr(global.data.img, &global.data.bpp, &global.data.length, &global.data.end);
	draw(&global);
	mlx_hook(global.mlx_win, 2, 1L<<0, key_hook, &global);
	mlx_put_image_to_window(global.mlx, global.mlx_win, global.data.img, 0, 0);
	write(1, "\033[0;32mcub3D open!\033[0m\n", 30);
	mlx_loop(global.mlx);
}


	// if (keycode == 2)		// right
	// {
	// 	if(worldMap[(int)(global->map.pos_x + global->dir_x * moveSpeed)][(int)(global->map.pos_y)] == 0)
	// 		global->dir_x -= global->dir_x * moveSpeed;
	// }			rofl
