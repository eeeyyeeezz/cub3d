# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/18 18:58:37 by gmorra            #+#    #+#              #
#    Updated: 2021/01/29 14:49:45 by gmorra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = gcc

CFLAGS = -Wall -Wextra -Werror

COMPILE_SRC = -g *.c parser/*.c src/get_next_line_cub/*.c src/libft/*.c

FRAMEWORK = -Lmlx -lmlx -framework OpenGL -framework AppKit

RUN:
	${CC} ${COMPILE_SRC} ${FRAMEWORK} -o $(NAME) && ./cub3D map.cub
