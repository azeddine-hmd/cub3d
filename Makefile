NAME = cub3d.a

LIBFTOB = map/libft/*.o

GCC = gcc -Wall -Wextra -Werror

MAKE = make -C map/libft

MCF =	cub3d.c \
		map/map.c \
		map/fill_map_first.c \
		map/fill_map_second.c \
		map/get_next_line/get_next_line.c \
		map/get_next_line/get_next_line_utils.c \

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
