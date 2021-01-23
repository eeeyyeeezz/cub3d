# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/18 18:58:37 by gmorra            #+#    #+#              #
#    Updated: 2021/01/23 16:08:36 by gmorra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = gcc

CFLAGS = -Wall -Wextra -Werror

COMPILE_SRC = -g main.c parser/*.c src/get_next_line/*.c src/libft/*.c

FRAMEWORK = -Lmlx -lmlx -framework OpenGL -framework AppKit

RUN:
	${CC} ${CFLAGS} ${COMPILE_SRC} ${FRAMEWORK} -o $(NAME) && ./cub3D map.cub
