# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schung <schung@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/01 15:57:27 by schung            #+#    #+#              #
#    Updated: 2021/12/26 20:22:25 by schung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

HEADER = headers/fractol.h	

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

$(NAME): $(OBJ)
	@$(CC) -I $(HEADER) $(OBJ) -L../libft -lft -o $(NAME)
	@echo "[INFO] Pipex [$(NAME)] created"

clean:
	@$(REMOVE) $(OBJ)
	@echo "[INFO] Removed objects"

fclean: clean
	@$(REMOVE) $(NAME)
	@echo "[INFO] Pipex and objects removed "

re: fclean all

.PHONY: all clean fclean re 