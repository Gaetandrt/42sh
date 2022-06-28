##
## EPITECH PROJECT, 2021
## makefile for my_sifleinfo
## File description:
## Makefile
##

CC		=	gcc

CFLAGS	=	-W -Wall -Wextra -Iinclude/

SRC		=	$(wildcard *.c) \
			$(wildcard src/*.c) \
			$(wildcard lib/*.c) \
			$(wildcard env/*.c) \
			$(wildcard lib_operators/*.c)

OBJ		=	$(SRC:.c=.o)

TARGET	=	42sh

all:	$(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(TARGET)
	rm -f a.out

re: fclean all