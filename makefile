# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/01 22:41:14 by lauragm           #+#    #+#              #
#    Updated: 2025/04/04 18:12:14 by lginer-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = clang
CFLAGS = -g -Wall -Werror -Wextra \
		-fsanitize=address,undefined \
		#-Wunreachable-code -Ofast \

LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = Printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

HEADERS = -I$(LIBFT) -I$(PRINTF_DIR)

SRCS = src/main.c src/check.c src/utils.c src/push.c src/rotate.c src/swap.c src/reverse_rotate.c\

OBJS = ${SRCS:.c=.o}

all: libft printf $(NAME)

libft:
	make -C $(LIBFT_DIR)

printf:
	@make -C $(PRINTF_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $< 
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(HEADERS) $(OBJS) $(LIBFT) $(PRINTF) $(LINK) -o $(NAME)
	@echo "Compiling Push_swap..."

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBFT_DIR)/*.o
	@make -C $(PRINTF_DIR) clean

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@make -C $(PRINTF_DIR) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, libft, printf