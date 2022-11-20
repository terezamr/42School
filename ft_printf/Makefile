# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 12:41:51 by mvicente          #+#    #+#              #
#    Updated: 2022/11/20 17:39:52 by mvicente         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = ft_printf.c ft_hex.c ft_itoa.c ft_putnbr.c ft_strlen.c ft_strchr.c

OBJ = $(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
			ar rcs $(NAME) $(OBJ)

clean:
			$(RM) $(OBJ) $(B_OBJ)

fclean:	clean
			$(RM) $(NAME)

re:	fclean $(NAME)
