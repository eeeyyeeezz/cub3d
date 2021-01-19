/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 14:22:48 by gmorra            #+#    #+#             */
/*   Updated: 2020/11/23 17:47:34 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char		*ft_strdup(const char *str)
{
	char *dup_str;
	char *p;

	dup_str = malloc(ft_strlen(str) + 1);
	p = dup_str;
	if (dup_str == NULL)
		return (NULL);
	while (*str)
		*(p++) = *(str++);
	*p = '\0';
	return (dup_str);
}

size_t		ft_strlen(const char *s)
{
	int a;

	a = 0;
	while (s[a] != 0)
		a++;
	return (a);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*new_string;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	new_string = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (new_string == NULL)
		return (NULL);
	while (*s1)
		new_string[i++] = *s1++;
	while (*s2)
		new_string[i++] = *s2++;
	new_string[i] = '\0';
	return (new_string);
}

char		*ft_strjoin_new(char *s1, char *s2)
{
	char	*ptr_free;

	ptr_free = s1;
	if (!(s1 = ft_strjoin(s1, s2)))
		return (NULL);
	free(ptr_free);
	return (s1);
}

char		*ft_strchr(const char *s, int c)
{
	char	*temp;

	temp = (char *)s;
	while (*temp != c)
	{
		if (*temp == '\0')
			return (NULL);
		temp++;
	}
	return (temp);
}
