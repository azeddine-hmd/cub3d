# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/28 10:16:47 by ahamdaou          #+#    #+#              #
#    Updated: 2021/01/02 18:28:33 by ahamdaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libmap.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra \
		 #-g \
		 -fsanitize=address \

SRC = map.c \
	  fill_directions.c \
	  fill_map_first.c \
	  fill_map_second.c \
	  fill_map.c \
	  map_information.c \
	  map_extension.c \
	  sprite.c \
	  map_helper.c \
	  map_wall.c \

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
