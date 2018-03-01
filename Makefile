MAKE = make -C
NAME = fillit
LIB = libft/
CFLAGS = -Wall -Wextra -Werror
CC = gcc

#When compiling. you need to add your .a lib
CFILES = $(LIB)/libft.a \
		 main.c \
         validate_input.c \
		 parse_input.c \
		 solve.c \
		 utilities_1.c \
         utilities_2.c 

#These options are here in case the lib needs to be recompiled.
#LIBM, LIBC, LIBF will run rules re, clean and fclean inside the libft folder
LIBM = $(MAKE) $(LIB) re
LIBC = $(MAKE) $(LIB) clean
LIBF = $(MAKE) $(LIB) fclean
OBJECTS = $(CFILES:.c=.o)

all: $(NAME)

$(NAME):
	@$(LIBM)
	@$(CC) $(CFLAGS) -I. -o $(NAME) $(CFILES)

clean:
	@$(LIBC)
	@/bin/rm -f $(OBJECTS) fillit.o

fclean:
	@$(LIBF)
	@/bin/rm -f $(OBJECTS) $(NAME)

re: fclean all