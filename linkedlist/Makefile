# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/27 14:49:07 by ahamdaou          #+#    #+#              #
#    Updated: 2020/03/05 23:11:57 by ahamdaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

G = gcc -Wall -Wextra -Werror

SRC = linkedlist.c \
	  linkedlist_utils.c \
	  allocation.c \
	  error.c \

NAME = linkedlist.a

O =	${SRC:.c=.o}

all: $(NAME)

$(NAME):
	$(G) -c $(SRC)
	ar rc $(NAME) $(O)
	ranlib $(NAME)

clean:
	rm -f $(O) $(OB)

fclean: clean
	rm -f $(NAME)

re:	fclean all
