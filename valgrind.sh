#!/bin/bash

# compiling and executing
make re && clear; gcc -Wall -Wextra -Werror -g *.c */*.c
clear; valgrind --leak-check=yes ./a.out
make -s fclean
