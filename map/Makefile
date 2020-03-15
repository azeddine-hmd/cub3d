# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/27 14:49:07 by ahamdaou          #+#    #+#              #
#    Updated: 2020/03/14 20:41:51 by ahamdaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

G = gcc -Wall -Wextra -Werror

SRC = map.c \
	  fill_map_first.c \
	  fill_map_second.c \
	  fill_map_third.c \
	  map_wall.c \
	  fill_directions.c \
	  fill_map.c \
	  check_allfilled.c \
	  map_utils.c \
	  map_norm.c \

NAME = map.a

O = ${SRC:.c=.o}

all: $(NAME)

$(NAME):
	$(G) -c $(SRC)
	ar rc $(NAME) $(O)

clean:
	rm -f $(O) $(OB)

fclean: clean
	rm -f $(NAME)

re:	fclean all
