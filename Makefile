NAME = push_swap
HEAD = push_swap.h
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = push_swap.c ft_swap.c ft_printf.c ft_printf.utils.c\
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
