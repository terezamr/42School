# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 12:41:51 by mvicente          #+#    #+#              #
#    Updated: 2022/10/26 15:16:09 by mvicente         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I .

RM = rm -f

SRC = $(wildcard *.c)

OBJ = $(SRC:.c=.o)

#B = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
#ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

#B = $(wildcard *.c)

B_OBJ = $(B:.c=.o)

all:	$(NAME)

bonus:	$(B_OBJ)
			ar rcs $(NAME) $(B_OBJ)

$(NAME):	$(OBJ)
			ar rcs $(NAME) $(OBJ)

clean:
			$(RM) $(OBJ) $(B_OBJ)

fclean:	clean
			$(RM) $(NAME)

re:	fclean $(NAME)

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJ)