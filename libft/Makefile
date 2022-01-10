# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schung <schung@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/12 17:50:47 by schung            #+#    #+#              #
#    Updated: 2022/01/10 20:12:45 by schung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADERS = ../headers/

TEMP_PATH = temp_folder/

SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
	  ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c  ft_strlcat.c \
	  ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
	  ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
	  ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
	  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c get_next_line.c \
	  ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
	  ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
	  ft_lstmap_bonus.c ft_strequal.c ft_strcmp.c

OBJ = ${SRC:.c=.o}
CFLAGS = -Wall -Werror -Wextra
CC = gcc $(CFLAGS)
LIB = ar rc $(NAME)
RANLIB = ranlib $(NAME)
REMOVE = rm -f
OBJ_PATH = temp_folder/

$(patsubst %,$(OBJ_PATH)%,%.o): %.c
	$(CC) -I ${HEADERS} -c $< -o $@

all: $(NAME)

$(NAME): $(patsubst %,$(OBJ_PATH)%,$(OBJ))
	$(LIB) $?
	@$(RANLIB)
	@echo "[INFO] Library [$(NAME)] created"

clean:
	@$(REMOVE) $(OBJ) $(OBJ_BONUS)
	@echo "[INFO] Removed libft objects"

fclean: clean
	@$(REMOVE) $(NAME)
	@echo "[INFO] Libft and objects removed "

re: fclean all

.PHONY: all clean fclean re
