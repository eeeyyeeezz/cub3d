# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/18 18:58:37 by gmorra            #+#    #+#              #
#    Updated: 2021/02/17 16:08:36 by gmorra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = gcc

CFLAGS = -Wall -Wextra -Werror

COMPILE_SRC =  src/get_next_line_cub/*.c parser/*.c src/libft/*.c

FRAMEWORK = -Lmlx -lmlx -framework OpenGL -framework AppKit

# COLORS

RED = "\033[0;31m"
BLUE = "\033[0;34m"
YELLOW = "\033[0;33m"
WHITE = "\033[1;37m"
GREEN = "\033[0;32m"
PURPLE = "\033[0;35m"
GRAY = "\033[1;30m"
NORMAL = "\033[0m"

# COLORS

# RUN:
# 	${CC} -g ${COMPILE_SRC} libmlx.dylib -o $(NAME) && ./cub3D map.cub

RUN:
	@echo $(RED)"Compiling $(NAME)..."$(NORMAL)
	@${CC} -g main.c $(COMPILE_SRC) libmlx.dylib -o $(NAME)
	@echo $(YELLOW)"Compile Completed!"$(NORMAL)
	@./cub3D map.cub

COMPILE:
	./cub3D map.cub
