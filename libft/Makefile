# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/27 14:49:07 by ahamdaou          #+#    #+#              #
#    Updated: 2020/03/14 14:50:46 by ahamdaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

G = gcc -Wall -Wextra -Werror

SRC = ft_atoi.c \
	  ft_isprint.c \
	  ft_memset.c \
	  ft_strdup.c \
	  ft_strnstr.c \
	  ft_strstr.c \
	  ft_bzero.c \
	  ft_itoa.c \
	  ft_putchar_fd.c \
	  ft_strjoin.c \
	  ft_strrchr.c \
	  ft_calloc.c \
	  ft_memccpy.c \
	  ft_putendl_fd.c \
	  ft_strlcat.c \
	  ft_strtrim.c \
	  ft_isalnum.c \
	  ft_memchr.c \
	  ft_putnbr_fd.c \
	  ft_strlcpy.c \
	  ft_substr.c \
	  ft_isalpha.c \
	  ft_memcmp.c \
	  ft_putstr_fd.c \
	  ft_putstr.c \
	  ft_strlen.c \
	  ft_tolower.c \
	  ft_isascii.c \
	  ft_memcpy.c \
	  ft_split.c \
	  ft_strmapi.c \
	  ft_toupper.c \
	  ft_isdigit.c \
	  ft_memmove.c \
	  ft_strchr.c \
	  ft_strncmp.c \
	  ft_strcmp.c \
	  ft_dec2hex.c \
	  ft_strtoupper.c \
	  ft_isstrdigit.c \
	  ft_onlyspaces.c \
	  ft_countchar.c \

NAME = libft.a

O = ${SRC:.c=.o}

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
