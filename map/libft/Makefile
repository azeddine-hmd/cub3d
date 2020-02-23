# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/27 14:49:07 by ahamdaou          #+#    #+#              #
#    Updated: 2019/12/30 18:09:08 by ahamdaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

G = gcc -Wall -Wextra -Werror

SRC = ft_atoi.c ft_isprint.c ft_memset.c ft_strdup.c ft_strnstr.c \
ft_bzero.c ft_itoa.c ft_putchar_fd.c ft_strjoin.c ft_strrchr.c \
ft_calloc.c ft_memccpy.c ft_putendl_fd.c ft_strlcat.c ft_strtrim.c \
ft_isalnum.c ft_memchr.c ft_putnbr_fd.c ft_strlcpy.c ft_substr.c \
ft_isalpha.c ft_memcmp.c ft_putstr_fd.c ft_strlen.c ft_tolower.c \
ft_isascii.c ft_memcpy.c ft_split.c ft_strmapi.c ft_toupper.c \
ft_isdigit.c ft_memmove.c ft_strchr.c ft_strncmp.c ft_dec2hex.c \
ft_strtoupper.c \

NAME = libft.a

O = ft_atoi.o ft_isprint.o ft_memset.o ft_strdup.o ft_strnstr.o \
ft_bzero.o ft_itoa.o ft_putchar_fd.o ft_strjoin.o ft_strrchr.o \
ft_calloc.o ft_memccpy.o ft_putendl_fd.o ft_strlcat.o ft_strtrim.o \
ft_isalnum.o ft_memchr.o ft_putnbr_fd.o ft_strlcpy.o ft_substr.o \
ft_isalpha.o ft_memcmp.o ft_putstr_fd.o ft_strlen.o ft_tolower.o \
ft_isascii.o ft_memcpy.o ft_split.o ft_strmapi.o ft_toupper.o \
ft_isdigit.o ft_memmove.o ft_strchr.o ft_strncmp.o ft_dec2hex.o\
ft_strtoupper.o \

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
