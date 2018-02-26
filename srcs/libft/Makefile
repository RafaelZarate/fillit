
NAME = libft.a

FLAGS = -Wall -Werror -Wextra -c

SRC = *.c

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(SRC)
	ar rcs $(NAME) *.o
	ranlib $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all