NAME = libftprintf.a

SRC = ft_printf.c ft_print_char.c ft_print_string.c ft_putptr.c ft_putnbr.c ft_puthex.c\

OBJ = $(SRC:.c=.o)

CFLAGS = -g -Wall -Wextra -Werror

CC = clang

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: re
	$(CC) $(CFLAGS) main.c $(NAME) -o test
	./test

.PHONY: all clean fclean re test