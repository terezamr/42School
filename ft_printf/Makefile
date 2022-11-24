# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 12:41:51 by mvicente          #+#    #+#              #
#    Updated: 2022/11/24 13:58:42 by mvicente         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = ft_printf.c ft_aux.c ft_hex.c ft_unsigned.c ft_ptr.c		

OBJ = $(SRC:.c=.o)

LIBFT = ft_isascii.c ft_isprint.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
		ft_tolower.c ft_toupper.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
		ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
		ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_striteri.c \
		ft_memchr.c ft_memcmp.c ft_strdup.c ft_calloc.c ft_itoa.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_strmapi.c
		
LOBJS = $(LIBFT:.c=.o)

LB_PATH	 = libft/

all:	$(NAME)

$(NAME):	$(OBJ) $(addprefix $(LB_PATH), $(LOBJS))
			ar rcs $(NAME) $(OBJ) $(addprefix $(LB_PATH), $(LOBJS))

clean:
			$(RM) $(OBJ) $(addprefix $(LB_PATH), $(LOBJS))

fclean:	clean
			$(RM) $(NAME)

re:	fclean $(NAME)
