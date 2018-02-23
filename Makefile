
NAME = fillit

SRC = main.c

OBJ = $(SRC:.c=.o)

SRC_PATH = src/

SRC_POS = $(addprefix $(SRC_PATH), $(SRC))

MAIN = srcs/main.c

FLAGS = -Wall -Werror -Wextra

LIBFT = srcs/libft/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
				gcc $(FLAGS) $(OBJ) -o $(NAME) $(LIBFT)

$(OBJ): $(LIBFT)
				gcc $(FLAGS) -c $(SRC_POS)

$(LIBFT):
				make -C ./srcs/libft

clean:
				rm -f $(OBJ)

fclean: clean
				rm -f $(NAME)

re: fclean all