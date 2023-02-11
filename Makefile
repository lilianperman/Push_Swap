
CC = cc
FLAGS = -Wall -Wextra -Werror
NAME = push_swap
LIBFT = ./libft/libft.a
CLIBFT = make -C libft clean
FCLIBFT = make -C libft fclean
SRC = ./source/sort_med.c ./source/movements.c ./source/sort_big.c ./source/push_swap.c ./source/utils.c ./source/stack_handler.c ./source/sort_short.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC)
	make -C ./libft
	$(CC) $(FLAGS) $(SRC) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJ)
	$(CLIBFT)

fclean:
	rm -f $(NAME)
	$(FCLIBFT)

re: fclean all

.PHONY: all clean fclean re
