
NAME        = push_swap

# Liste de vos sources
SRC         = push_swap.c utils.c mini_fonctions.c
OBJ         = $(SRC:.c=.o)

# Répertoires d'inclusions
INCLUDES    = -I./include -I./libft -I./ft_printf

# Dossiers des bibliothèques
LIBFT_DIR           = ./libft
FT_PRINTF_DIR       = ./ft_printf

LIBFT       = $(LIBFT_DIR)/libft.a
FT_PRINTF   = $(FT_PRINTF_DIR)/ft_printf.a

# Compilation
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror

.PHONY: all clean fclean re

# Règles de compilation
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(FT_PRINTF) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Compilation des bibliothèques externes
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

# Règles de nettoyage
clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

