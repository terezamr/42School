# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 12:41:51 by mvicente          #+#    #+#              #
#    Updated: 2023/03/14 11:04:57 by mvicente         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = pipex.c lists.c ft_split.c aux.c arguments.c strings.c

SRC_BONUS = pipex_bonus.c lists_bonus.c ft_split_bonus.c free_bonus.c arguments_bonus.c aux_bonus.c pipe_bonus.c strings_bonus.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

BONUS_PATH = bonus/

all:	$(NAME)	

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus:		$(addprefix $(BONUS_PATH), $(OBJ_BONUS))
			$(CC) $(CFLAGS) $(addprefix $(BONUS_PATH), $(OBJ_BONUS)) -o $(NAME)

clean:
			$(RM) $(OBJ) $(addprefix $(BONUS_PATH), $(OBJ_BONUS))

fclean:	clean
			$(RM) $(NAME)

re:	fclean all
