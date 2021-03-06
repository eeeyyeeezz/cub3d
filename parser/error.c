/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 13:12:06 by gmorra            #+#    #+#             */
/*   Updated: 2021/03/06 13:08:40 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static	void	static_exit(void)
{
	system("killall afplay");
	exit(0);
}

static	void	ft_error_two(int error)
{
	if (error == 12)
		ft_putstr("Error\nMap is not closed\n");
	else if (error == 13)
		ft_putstr("Error\nNo player is on map or too many\n");
	else if (error == 14)
		ft_putstr("Error\nMap is not in the end of the .cub\n");
	else if (error == 15)
		ft_putstr("Error\nSpaces inside the map\n");
	else if (error == 16)
		ft_putstr("Error\nSome trash in the .cub\n");
	else if (error == 17)
		ft_putstr("Error\nNo .cub\n");
	else if (error == 18)
		ft_putstr("Error\nSome error fix bro\n");
	else if (error == 19)
		ft_putstr("Error\nSpaces\n");
	else if (error == 20)
		ft_putstr("Error\nNo xpm expansion\n");
	else if (error == 21)
		ft_putstr("Error\nFloor arguments wrong\n");
	else if (error == 22)
		ft_putstr("Error\nTextures wrong\n");
	else if (error == 23)
		ft_putstr("Error\nTrash in map\n");
	static_exit();
}

void			ft_error(int error)
{
	if (error == 1)
		ft_putstr("Error\nWrong resolution arguments\n");
	else if (error == 2)
		ft_putstr("Error\nResolution params wrong\n");
	else if (error == 3)
		ft_putstr("Error\nCeilling arguments wrong\n");
	else if (error == 4)
		ft_putstr("Error\nRGB arguments wrong\n");
	else if (error == 5)
		ft_putstr("Error\nCommas\n");
	else if (error == 6)
		ft_putstr("Error\nCeilling arguments wrong\n");
	else if (error == 7)
		ft_putstr("Error\nWrong north texture\n");
	else if (error == 8)
		ft_putstr("Error\nWrong south texture\n");
	else if (error == 9)
		ft_putstr("Error\nWrong east texture\n");
	else if (error == 10)
		ft_putstr("Error\nWrong west texture\n");
	else if (error == 11)
		ft_putstr("Error\nWrong sprite texture\n");
	ft_error_two(error);
	static_exit();
}
