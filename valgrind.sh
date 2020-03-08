#!/bin/bash

# compiling and executing
gcc -Wall -Wextra -Werror *.c */*.c -g
valgrind --leak-check=full ./a.out
