
NAME = fillit

SRC = main.c \
		validate_input.c \
		parse_input.c \
		solve.c \
		utility_functs.c \
		utilities2.c

OBJ = $(SRC:.c=.o)

SRC_PATH = srcs/

SRC_POS = $(addprefix $(SRC_PATH), $(SRC))

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
					make clean -C ./srcs/libft

fclean: clean
				rm -f $(NAME)
					make fclean -C ./srcs/libft

re: fclean all