# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/11 10:23:10 by ahamdaou          #+#    #+#              #
#    Updated: 2020/03/12 11:38:19 by ahamdaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d.a

EXE = cub3d

LIBFTOB = libft/*.o
GET_NEXT_LINEOB = get_next_line/*.o
MAPOB = map/*.o
LLOB = linkedlist/*.o

GCC = gcc -Wall -Werror -Wextra \
	  -fsanitize=address \
	  -I /usr/local/include \
	  -L /usr/local/lib -lmlx \
	  -framework OpenGL -framework AppKit \

CC = gcc -Wall -Werror -Wextra

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
	$(ARCHIVE) $(NAME) $(LIBFTOB) $(GET_NEXT_LINEOB) $(MAPOB) $(LLOB)
	$(GCC) $(MCF) $(NAME) -o $(EXE)

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
	$(RM) $(NAME) $(EXE)
	$(RM)r a.out*

re: fclean all
