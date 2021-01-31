/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 17:13:47 by gmorra            #+#    #+#             */
/*   Updated: 2021/01/31 20:44:59 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

typedef		struct data
{
	void		*img;
	char		*addr;
	int			bpp;
	int			length;
	int			end;
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

	mlx_win = mlx_new_window(mlx, 2000, 900, "cub3D");
	data->img = mlx_new_image(mlx, 20, 20);

	fill_image(global, 20, 20);

}
