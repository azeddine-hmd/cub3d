# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/27 14:49:07 by ahamdaou          #+#    #+#              #
#    Updated: 2020/12/22 02:05:07 by ahamdaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = liblinkedlist.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra \

SRC = linkedlist.c \
	  linkedlist_utils.c \
	  allocation.c \
	  error.c \
	  swap.c \
	  utils.c \

OBJ = ${SRC:.c=.o}

all: $(NAME)

$(NAME):
	@ $(CC) $(CFLAGS) -c $(SRC)
	@ ar rc $(NAME) $(OBJ)

clean:
	@ rm -f $(OBJ)

fclean: clean
	@ rm -f $(NAME)

re:	fclean all
