/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 16:47:50 by gmorra            #+#    #+#             */
/*   Updated: 2021/01/22 17:35:50 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		pars(t_struct *global, char *line)
{
	int i;

	i = 0;
	if (ft_strchr(line, 'R'))
		pars_resolution(line, global);
	else if (ft_strchr(line, 'C'))
	{
		printf("im good\n");
		pars_ceilling(line, global);
	}
	// printf("zahod\n");
}
