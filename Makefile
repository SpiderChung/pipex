# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schung <schung@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/01 15:57:27 by schung            #+#    #+#              #
#    Updated: 2022/01/10 20:30:23 by schung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

FOREIGN_TARGETS = libft/libft.a

HEADER = headers/pipex.h	

SRC = pipex.c pipex_utils.c

OBJ = ${SRC:.c=.o}

CFLAGS = -Wall -Werror -Wextra

CC = gcc $(CFLAGS)

LIB = ar rc $(NAME)

RANLIB = ranlib $(NAME)

REMOVE = rm -f

%.o: %.c $(HEADER)
	$(CC) -I $(HEADER) -c $< -o $@

all: $(NAME) $(HEADER)

$(NAME): $(OBJ) $(FOREIGN_TARGETS)
	@$(CC) -I $(HEADER) $(OBJ) -Llibft -lft -o $(NAME)
	@echo "[INFO] [$(NAME)] created"

$(FOREIGN_TARGETS):
	@make -C $(dir $@) $(notdir $@)

clean:
	@$(REMOVE) $(OBJ)
	@echo "[INFO] Removed pipex objects"

fclean: clean
	@$(REMOVE) $(NAME)
	@make fclean -C libft
	@echo "[INFO] Pipex and objects removed "

re: fclean all

.PHONY: all clean fclean re $(FOREIGN_TARGETS)