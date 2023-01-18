# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 12:41:51 by mvicente          #+#    #+#              #
#    Updated: 2023/01/18 15:19:58 by mvicente         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

MLX_PATH	= minilib-x/
MLX_NAME	= libmlx.a
MLX			= $(MLX_PATH)$(MLX_NAME)

SRC = main.c aux.c fractals.c window.c events.c
OBJ = $(SRC:.c=.o)
LDLIBS = -g -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm

all:	$(MLX) $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@
	
$(MLX):
	make -sC $(MLX_PATH)

$(NAME):	$(OBJ)
			$(CC) $(OBJ) $(LDLIBS) $(MLX) -o $(NAME)

clean:
			$(RM) $(OBJ)

fclean:	clean
			$(RM) $(NAME)

re:	fclean all
