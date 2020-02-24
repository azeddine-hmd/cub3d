NAME = cub3d.a

LIBFTOB = libft/*.o
GET_NEXT_LINEOB = get_next_line/*.o
MAPOB = map/*.o

GCC = gcc -Wall -Wextra -Werror

MAKE = make -C

MCF =	cub3d.c \
		linkedlist.c \

MOF =	${MCF:.c=.o}

ARCHIVE = ar rc

RM = rm -f

all: $(NAME)

$(NAME):
	$(MAKE) libft all
	$(MAKE) get_next_line all
	$(MAKE) map all
	$(GCC) -c $(MCF)
	$(ARCHIVE) $(NAME) $(MOF) $(LIBFTOB) $(GET_NEXT_LINEOB) $(MAPOB)
clean:
	$(MAKE) libft clean
	$(MAKE) get_next_line clean
	$(MAKE) map clean
	$(RM) $(MOF)

fclean: clean
	$(MAKE) libft fclean
	$(MAKE) get_next_line fclean
	$(MAKE) map fclean
	$(RM) $(NAME)
	$(RM)r a.out*

re: fclean all
