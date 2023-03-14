# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 12:41:51 by mvicente          #+#    #+#              #
#    Updated: 2023/03/14 10:27:44 by mvicente         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = pipex.c lists.c ft_split.c aux.c arguments.c strings.c

SRC_BONUS = pipex_bonus.c lists.c ft_split.c aux.c arguments.c aux2.c strings.c pipes_bonus.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all:	$(NAME)	

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus:		$(OBJ_BONUS)
			$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME)

clean:
			$(RM) $(OBJ) $(OBJ_BONUS)

fclean:	clean
			$(RM) $(NAME)

re:	fclean all
