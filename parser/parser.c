/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 16:47:50 by gmorra            #+#    #+#             */
/*   Updated: 2021/01/22 21:17:24 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void		pars(t_struct *global, char *line)
{
	if (ft_strchr(line, 'R') == 1)
		pars_resolution(line, global);
	else if (ft_strchr(line, 'C') == 1)
		pars_ceilling(line, global);
	else if (ft_strchr(line, 'F') == 1)
		pars_floor(line, global);
	else if (ft_strnstr(line, "NO") == 1)
		pars_north(line, global);

}
