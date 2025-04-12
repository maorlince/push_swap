NAME = ft_printf.a
HEAD = ft_printf.h
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c ft_printf.utils.c\
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
