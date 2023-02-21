CC=gcc
# CFLAGS=-Wall -Wextra -Werror
FLAGS=-lreadline

NAME=minishell

SRC_DIR=libft
SRC=$(SRC_DIR)/ft_putchar_fd.c \
	$(SRC_DIR)/ft_putendl_fd.c \
	$(SRC_DIR)/ft_putstr_fd.c \
	$(SRC_DIR)/ft_split.c \
	$(SRC_DIR)/ft_strcmp.c \
	$(SRC_DIR)/ft_strdup.c \
	$(SRC_DIR)/ft_strlen.c \
	$(SRC_DIR)/ft_substr.c \
	$(SRC_DIR)/ft_strstr.c \
	$(SRC_DIR)/ft_strchr.c \
	builtins/ft_cd.c \
	builtins/ft_echo.c \
	utils.c \
	display_prompt.c \
	splitting.c \
	main.c

OBJ_DIR=obj
OBJ=$(SRC:%.c=$(OBJ_DIR)/%.o)

INCLUDE=libft/libft.h minishell.h

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(FLAGS)

$(OBJ_DIR)/%.o: %.c $(INCLUDE)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	rm -rf $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
