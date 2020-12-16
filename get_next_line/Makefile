# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/28 10:17:13 by ahamdaou          #+#    #+#              #
#    Updated: 2020/12/16 04:26:31 by ahamdaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libget_next_line.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror \

SRC = get_next_line.c \
	  get_next_line_utils.c \

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
