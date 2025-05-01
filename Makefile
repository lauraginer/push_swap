# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/01 22:41:14 by lauragm           #+#    #+#              #
#    Updated: 2025/04/30 21:47:28 by lginer-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -g -Wall -Werror -Wextra \
		# -fsanitize=address,undefined \
		#-Wunreachable-code -Ofast \

LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

HEADER = push_swap.h

PRINTF_DIR = Printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

HEADERS = -I$(LIBFT) -I$(PRINTF_DIR)

SRCS = 	src/main.c\
		src/check.c\
		src/utils.c\
		src/push.c\
		src/rotate.c\
		src/swap.c\
		src/reverse_rotate.c \
		src/stack.c \
		src/moves.c\
		src/indexs.c\
		src/costs.c\
		src/more_utils.c\
		src/final_step.c\

OBJS = ${SRCS:.c=.o}

all: libft printf $(NAME)

libft:
	@make -s all -C $(LIBFT_DIR)

printf:
	@make -s all -C $(PRINTF_DIR)

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