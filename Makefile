# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schung <schung@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/01 15:57:27 by schung            #+#    #+#              #
#    Updated: 2022/01/15 18:56:10 by schung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

NAME_BONUS = pipex_bonus

HEADER = headers/pipex.h headers/pipex_bonus.h

SRC = pipex.c pipex_utils.c

OBJ = ${SRC:.c=.o}

SRC_B = bonus/pipex_bonus.c bonus/pipex_utils_bonus.c bonus/pipex_errors_bonus.c 

OBJ_B = ${SRC_B:.c=.o}

CFLAGS = -Wall -Werror -Wextra

CC = gcc $(CFLAGS)

LIB = ar rc $(NAME)

RANLIB = ranlib $(NAME)

REMOVE = rm -f

%.o: %.c $(HEADER)
	$(CC) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@$(CC) $(OBJ) -Llibft -lft -o $(NAME)
	@echo "$(RED)[INFO] [$(NAME)] created"

bonus: $(OBJ_B)
	@make -C libft
	$(CC) $(OBJ_B) -Llibft -lft -o $(NAME_BONUS)
	@echo "$(RED)[INFO] [$(NAME_BONUS)] created"

clean:
	@$(REMOVE) $(OBJ)
	@$(REMOVE) $(OBJ_B)
	@echo "[INFO] Removed pipex objects"

fclean: clean
	@$(REMOVE) $(NAME) $(NAME_BONUS)
	@make fclean -C libft
	@echo "[INFO] Pipex and objects removed "

re: fclean all

.PHONY: all clean fclean re

#COLOURS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m