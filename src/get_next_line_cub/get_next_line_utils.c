/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 14:22:48 by gmorra            #+#    #+#             */
/*   Updated: 2020/11/23 17:41:59 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strjoin_new(char *s1, char *s2)
{
	char	*ptr_free;

	ptr_free = s1;
	if (!(s1 = ft_strjoin(s1, s2)))
		return (NULL);
	free(ptr_free);
	return (s1);
}

char        *ft_strchr_gnl(const char *s, int c)
{
    char    *temp;

    temp = (char *)s;
    while (*temp != c)
    {
        if (*temp == '\0')
            return (NULL);
        temp++;
    }
    return (temp);
}
