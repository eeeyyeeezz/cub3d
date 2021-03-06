# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/18 18:58:37 by gmorra            #+#    #+#              #
#    Updated: 2021/03/06 18:56:06 by gmorra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = gcc

CFLAGS = -Wall -Wextra -Werror

HEADERS = cub3d.h src/get_next_line_cub/get_next_line.h src/libft/libft.h

PARSER_SRC = parser/ceiling.c parser/error.c parser/error_two.c\
parser/floor.c parser/map.c parser/parser.c parser/resolution.c\
parser/resolution_two.c parser/sprite.c parser/textures.c\

COMPILE_SRC = src/direction_sight.c src/draw.c src/first_draw_while.c src/first_ifs.c\
src/fourth_ifs.c src/ft_close.c src/get_next_line_cub/get_next_line.c src/get_next_line_cub/get_next_line_utils.c\
src/get_zero.c src/init_all.c src/key_hook.c src/movement.c src/get_sprites_right.c\
src/rotate.c src/screenshot.c src/sort_sprites.c src/textures_draw.c src/my_mlx_pixel_put.c\

SRC_LIBFT =  src/libft/ft_atoi.c src/libft/ft_isalpha.c src/libft/ft_isdigit.c src/libft/ft_substr.c\
src/libft/ft_strdup.c src/libft/ft_strjoin.c src/libft/ft_strlen.c src/libft/ft_strnstr.c\
src/libft/ft_split.c src/libft/ft_strchr.c src/libft/ft_isspaces.c src/libft/ft_putstr.c\

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
MARK = "U+2713"

# COLORS

OBJ = $(COMPILE_SRC:.c=.o)
OBJ_2 = $(PARSER_SRC:.c=.o)
OBJ_3 = $(SRC_LIBFT:.c=.o)

all: ${NAME}

${NAME}: ${OBJ} ${OBJ_2} ${OBJ_3} ${HEADERS}
	@echo ${RED}"Assembly mlx..."${NORMAL}
	@${MAKE} -C ./mlx
	@echo ${YELLOW}"Assembling Completed!"${NORMAL}
	@echo ${RED}"Compiling ${NAME}..."${NORMAL}
	@${CC} ${CFLAGS} -g -o ${NAME} ${FRAMEWORK} -Imlx main.c ${PARSER_SRC} ${COMPILE_SRC} ${SRC_LIBFT} libmlx.dylib
	@echo ${GREEN}"Compile Completed!"${NORMAL}

RUN:
	@./cub3D maps/map.cub

WRONG_MAPS:
	./cub3D maps/wrong_resolution.cub
	./cub3D maps/wrong_floor.cub
	./cub3D maps/wrong_texture.cu

MAKE_SCREENSHOT:
	@echo ${RED}"Making screenshot..."${NORMAL}
	@${CC} -g -o ${NAME} ${FRAMEWORK} -Imlx main.c ${PARSER_SRC} ${COMPILE_SRC} ${SRC_LIBFT} libmlx.dylib
	@echo ${YELLOW}"Compile Completed!"${NORMAL}
	@echo ${GREEN}"Check for .bmp"${NORMAL}
	@./cub3D maps/map.cub --save

NORM:
	@norminette_old ${SRC_LIBFT} ${PARSER_SRC} ${COMPILE_SRC} ${HEADERS}

DESTROY:
	@rm -rf *.dSYM
	@echo ${RED}"ALL DSYM IS DESTROYED"${NORMAL}

COMPILE:
	./cub3D map.cub

clean:
	@rm -f ${OBJ} ${OBJ_2} ${OBJ_3}
	@printf ${GREEN}"Clean is done ✅\n"${NORMAL}

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
