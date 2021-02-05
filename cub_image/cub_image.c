/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 17:13:47 by gmorra            #+#    #+#             */
/*   Updated: 2021/02/05 16:35:00 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <unistd.h>

typedef		struct data
{
	void		*img;
	char		*addr;
	int 		bpp;
	int 		length;
	int 		end;
}
					data;


static	void		my_mlx_pixel_put(data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void 		fill_image(data *data, int width, int height)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < height)
	{
		while (j < width)
		{
			my_mlx_pixel_put(data, j, i, 0xFF0000);
			j++;
		}
		i++;
		j = 0;
	}
}

int			main(void)
{
	void 	*mlx;
	void	*mlx_win;
	data	data;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "image3D");
	data.img = mlx_new_image(mlx, 500, 500);
	data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.length, &data.end);
	fill_image(&data, 500, 500);
	mlx_put_image_to_window(mlx, mlx_win, data.img, 0, 0);
	write(1, "open\n", 6);
	mlx_loop(mlx);
}

// typedef struct  s_data {
//     void        *img;
//     char        *addr;
//     int         bits_per_pixel;
//     int         line_length;
//     int         endian;
// }               t_data;

// int             main(void)
// {
//     void    *mlx;
//     void    *mlx_win;
//     t_data  img;

//     mlx = mlx_init();
//     mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
//     img.img = mlx_new_image(mlx, 1920, 1080);
//     img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
//                                  &img.endian);
//     mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
//     mlx_loop(mlx);
// }
