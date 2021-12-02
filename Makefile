SRC =	push_swap.c\
		algo_100.c\
		algo_500.c\
		algo.c\
		checkers.c\
		list_utils.c\
		list_utils2.c\
		memory.c\
		operations.c\
		utils.c\

NAME = push_swap

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = clang

CFLAGS = -Wall -Wextra -Werror

OBJ_DIR = obj
SRC_DIR = srcs
INC_DIR = includes

OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

.c.o:
	${CC} ${CFLAGS} -c$< -o ${<:.c=.o}

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
		${CC} $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)
		@echo $(NAME) : Created !

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | .gitignore
		@mkdir -p $(OBJ_DIR)
		${CC} $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

.gitignore:
		@echo $(NAME) > .gitignore

clean:
	make -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo ".o deleted"

fclean:	clean
	make -C $(LIBFT_DIR) fclean
	@rm -rf $(NAME)
	@echo "[$(NAME)]: deleted"

re: fclean all

.PHONY: all, clean, fclean, re
