# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/11 10:23:10 by ahamdaou          #+#    #+#              #
#    Updated: 2020/12/24 16:27:57 by ahamdaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = gcc

CFLAGS = -Wall -Werror -Wextra \
	  -I /usr/local/include \
	  -L /usr/local/lib -lmlx \
	  -framework OpenGL -framework AppKit \
	  -fsanitize=address \
	  -g \

LIBS = libft/libft.a \
	   get_next_line/libget_next_line.a \
	   linkedlist/liblinkedlist.a \
	   game_map/libmap.a \

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
	  screenshot.c \
	  binding.c \
	  protection.c \
	  movement.c \
	  projection_helper.c \
	  cast.c \
	  horz_intersection.c \
	  vert_intersection.c \
	  release_sprites.c \
	  bonus_binding.c \
	  audio.c \
	  options.c \
	  run.c \

OBJ = ${SRC:.c=.o}

BNSRC = bonus_activation.c \

BNOBJ = ${BNSRC:.c=.o}

MAKE = make -C

all: $(NAME)

$(NAME):
	@ $(MAKE) libft
	@ $(MAKE) get_next_line
	@ $(MAKE) game_map
	@ $(MAKE) linkedlist
	@ $(CC) $(CFLAGS) $(SRC) bonus_disactivation.c $(LIBS) -o $(NAME)

bonus:
	@ $(MAKE) libft
	@ $(MAKE) get_next_line
	@ $(MAKE) game_map
	@ $(MAKE) linkedlist
	@ $(CC) $(CFLAGS) $(SRC) $(BNSRC) $(LIBS) -o $(NAME)

clean:
	@ $(MAKE) libft clean
	@ $(MAKE) get_next_line clean
	@ $(MAKE) game_map clean
	@ $(MAKE) linkedlist clean
	@ rm -rf $(OBJ) $(BNOBJ) bonus_disactivation.o cub3D.dSYM # remove later

fclean: clean
	@ $(MAKE) libft fclean
	@ $(MAKE) get_next_line fclean
	@ $(MAKE) game_map fclean
	@ $(MAKE) linkedlist fclean
	@ rm -rf $(NAME)

re: fclean all
