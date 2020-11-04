# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/28 10:16:47 by ahamdaou          #+#    #+#              #
#    Updated: 2020/11/04 20:05:57 by ahamdaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = map.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

SRC = map.c \
	  fill_directions.c \
	  fill_map_first.c \
	  fill_map_second.c \
	  fill_map_third.c \
	  fill_map.c \
	  map_helper.c \
	  map_information.c \
	  map_norm.c \
	  map_utils.c \
	  map_wall.c \
	  check_allfilled.c \
	  map_extension.c \

OBJ = ${SRC:.c=.o}

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
