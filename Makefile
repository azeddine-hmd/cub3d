# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/11 10:23:10 by ahamdaou          #+#    #+#              #
#    Updated: 2020/12/16 04:09:03 by ahamdaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

LIBS = libft/libft.a \
	   get_next_line/libget_next_line.a \
	   linkedlist/liblinkedlist.a \
	   game_map/libmap.a \

CC = clang

CFLAGS = -Wall -Werror -Wextra \
	  -I /usr/local/include \
	  -L /usr/local/lib -lmlx \
	  -framework OpenGL -framework AppKit \

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
	  txt.c \
	  txt_helper.c \
	  math_helper.c \
	  draw.c \
	  mlx_helper.c \
	  rays_helper.c \
	  rays_methods.c \
	  sprite_methods.c \
	  audio.c \
	  screenshot.c \
	  binding.c \
	  protection.c \
	  movement.c \
	  projection_helper.c \
	  cast.c \
	  horz_intersection.c \
	  vert_intersection.c \
	  release_sprites.c \

OBJ = ${SRC:.c=.o}

MAKE = make -C

all: $(NAME)

$(NAME):
	@ $(MAKE) libft
	@ $(MAKE) get_next_line
	@ $(MAKE) game_map
	@ $(MAKE) linkedlist
	@ $(CC) $(CFLAGS) $(SRC) $(LIBS) -o $(NAME)

clean:
	@ $(MAKE) libft clean
	@ $(MAKE) get_next_line clean
	@ $(MAKE) game_map clean
	@ $(MAKE) linkedlist clean
	@ rm -rf $(OBJ)

fclean: clean
	@ $(MAKE) libft fclean
	@ $(MAKE) get_next_line fclean
	@ $(MAKE) game_map fclean
	@ $(MAKE) linkedlist fclean
	@ rm -rf $(NAME)

re: fclean all
