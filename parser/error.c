/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 13:12:06 by gmorra            #+#    #+#             */
/*   Updated: 2021/02/28 15:09:24 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void		ft_error(int error)
{
	if (error == 1)
		ft_putstr("Error\nWrong resolution arguments\n");
	if (error == 2)
		ft_putstr("Error\nResolution params wrong\n");
	if (error == 3)
		ft_putstr("Error\nCeilling arguments wrong\n");
	if (error == 4)
		ft_putstr("Error\nRGB arguments wrong\n");
	if (error == 5)
		ft_putstr("Error\nMore/less commas that required or spaces beetween arguments\n");
	if (error == 6)
		ft_putstr("Error\nCeilling arguments wrong\n");
	if (error == 7)
		ft_putstr("Error\nWrong north texture\n");
	if (error == 8)
		ft_putstr("Error\nWrong south texture\n");
	if (error == 9)
		ft_putstr("Error\nWrong east texture\n");
	if (error == 10)
		ft_putstr("Error\nWrong west texture\n");
	if (error == 11)
		ft_putstr("Error\nWrong sprite texture\n");
	if (error == 12)
		ft_putstr("Error\nMap is not closed\n");
	if (error == 13)
		ft_putstr("Error\nNo player is on map or too many\n");
	if (error == 14)
		ft_putstr("Error\nMap is not in the end of the .cub\n");
	if (error == 15)
		ft_putstr("Error\nSpaces inside the map\n"); 
	exit(0);
}

