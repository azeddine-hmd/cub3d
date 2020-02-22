NAME = cub3d.a

LIBFTOB = libft/*.o

GCC = gcc -Wall -Wextra -Werror

MAKE = make -C libft

MCF =	cub3d.c \
		get_next_line.c \
		get_next_line_utils.c \
		map.c \

MOF = ${MCF:.c=.o}

ARCHIVE = ar rc

RM = rm -f

all: $(NAME)

$(NAME):
	$(MAKE) all
	$(GCC) -c $(MCF)
	$(ARCHIVE) $(NAME) $(MOF) $(LIBFTOB)

clean:
	$(MAKE) clean
	$(RM) $(MOF)

fclean: clean
	$(MAKE) fclean
	$(RM) $(NAME)
	$(RM)r a.out*

re: fclean all
