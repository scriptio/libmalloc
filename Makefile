##
## Makefile for malloc in /Users/scalp/projs/c/malloc
##
## Made by anthony scalisi
## <scalisia@gmail.com>
##
## Started on  Wed May  1 20:09:40 2013 anthony scalisi
## Last update Fri May  3 13:45:28 2013 anthony scalisi
##

NAME	=	libmy_malloc_$(HOSTTYPE).so
SRC	=	common.c			\
		malloc.c			\
		free.c				\
		realloc.c			\
	 	show_alloc_mem.c
OBJ	=	$(SRC:.c=.o)
CC	=	gcc
RM	=	rm -rf
CFLAGS	=	-W -Wall -ansi -pedantic -fpic -I./include -D$(HOSTTYPE)
LDFLAGS	=	-lc

$(NAME)	: 	$(OBJ)
		$(CC) -shared -o $(NAME) $(OBJ) $(LDFLAGS)
		ln -sf libmy_malloc_$(HOSTTYPE).so libmy_malloc.so

all	:	$(NAME)


.c.o	:
		$(CC) -c $(CFLAGS) $< -o $(<:.c=.o)

clean	:
		$(RM) *~ *#

fclean	:	clean
		$(RM) $(OBJ)

re	:	fclean all clean
