# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/18 18:58:37 by gmorra            #+#    #+#              #
#    Updated: 2021/01/30 16:46:08 by gmorra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = gcc

CFLAGS = -Wall -Wextra -Werror

PUTIN = -c -D GL_SILENCE_DEPRECATION

COMPILE_SRC = *.c parser/*.c src/get_next_line_cub/*.c src/libft/*.c

FRAMEWORK = -Lmlx -lmlx -framework OpenGL -framework AppKit

RUN:
	${CC} -g ${COMPILE_SRC} libmlx.dylib -o $(NAME) && ./cub3D map.cub

COMPILE:
	./cub3D map.cub
