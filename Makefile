# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/11 10:23:10 by ahamdaou          #+#    #+#              #
#    Updated: 2020/12/04 14:54:59 by ahamdaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

LIB = libcub3d.a

# include internal objects
LIBFT_OBJ = libft/*.o
GET_NEXT_LINE_OBJ = get_next_line/*.o
MAP_OBJ = game_map/*.o
LL_OBJ = linkedlist/*.o

CC = gcc

CFLAGS = -Wall -Werror -Wextra \
	  -I /usr/local/include \
	  -L /usr/local/lib -lmlx \
	  -framework OpenGL -framework AppKit \
	  -fsanitize=address \
	  -O3 \
	  -g \

MAKE = make -C

SRC = cub3d.c \
	  vars.c \
	  game.c \
	  map_methods.c \
	  collision.c \
	  input.c \
	  player_methods.c \
	  player.c \
	  projection.c \
	  rays.c \
	  utils.c \
	  txt.c \
	  txt_helper.c \
	  math_helper.c \
	  draw.c \
	  mlx_helper.c \
	  rays_helper.c \
	  rays_methods.c \
	  sprite_methods.c \

OBJ = ${SRC:.c=.o}

all: $(NAME)

$(NAME):
	$(MAKE) libft all
	$(MAKE) get_next_line all
	$(MAKE) game_map all
	$(MAKE) linkedlist all
	ar rc $(LIB) $(LIBFT_OBJ) $(GET_NEXT_LINE_OBJ) $(MAP_OBJ) $(LL_OBJ)
	$(CC) $(CFLAGS) $(SRC) $(LIB) -o $(NAME)

clean:
	$(MAKE) libft clean
	$(MAKE) get_next_line clean
	$(MAKE) game_map clean
	$(MAKE) linkedlist clean
	rm -rf $(OBJ)

fclean: clean
	$(MAKE) libft fclean
	$(MAKE) get_next_line fclean
	$(MAKE) game_map fclean
	$(MAKE) linkedlist fclean
	rm -rf $(NAME) $(LIB) cub3d.dSYM # remove 'cub3d.dSYM' later

re: fclean all
