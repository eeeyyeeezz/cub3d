/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 14:42:47 by gmorra            #+#    #+#             */
/*   Updated: 2021/03/13 15:14:44 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

typedef	struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_strlen(const char *s);
int					ft_strnstr(char *big, char *little);
int					ft_ft_strnstr(char *big, char *little);
int					ft_strncmp(char *s1, char *s2, unsigned int n);
int					ft_atoi(const char *str);
int					ft_isdigit(int c);
int					ft_isletter_trash(int c);
int					ft_isspaces(char word);
int					ft_isalpha(int c);

void				*ft_calloc(size_t count, size_t size);
char				*ft_strdup(const char *str);

int					ft_strchr(char *line, char c);
char				*ft_substr(char const *s, int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				**ft_split(char const *s, char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char *s);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

#endif
