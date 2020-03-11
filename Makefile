# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/11 10:23:10 by ahamdaou          #+#    #+#              #
#    Updated: 2020/03/11 11:02:49 by ahamdaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

LIBFTOB = libft/*.o
GET_NEXT_LINEOB = get_next_line/*.o
MAPOB = map/*.o
LLOB = linkedlist/*.o

GCC = gcc -Wall -Werror -Wextra -I /usr/local/include -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

MAKE = make -C

MCF =	cub3d.c \
		helpers.c \

MOF =	${MCF:.c=.o}

ARCHIVE = ar rc

RM = rm -f

all: $(NAME)

$(NAME):
	$(MAKE) libft all
	$(MAKE) get_next_line all
	$(MAKE) map all
	$(MAKE) linkedlist all
	$(GCC) -c $(MCF)
	$(ARCHIVE) $(NAME) $(MOF) $(LIBFTOB) $(GET_NEXT_LINEOB) $(MAPOB) $(LLOB)

clean:
	$(MAKE) libft clean
	$(MAKE) get_next_line clean
	$(MAKE) map clean
	$(MAKE) linkedlist clean
	$(RM) $(MOF)

fclean: clean
	$(MAKE) libft fclean
	$(MAKE) get_next_line fclean
	$(MAKE) map fclean
	$(MAKE) linkedlist fclean
	$(RM) $(NAME)
	$(RM)r a.out*

re: fclean all
