#!/bin/bash

# compiling and executing
make re
gcc -Wall -Wextra -Werror -g *.c */*.c
./a.out
