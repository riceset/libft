CC = gcc
NAME = libft.a
# CFLAGS = -Wall -Wextra -Werror -I includes
CFLAGS = -I includes
SRCS = $(wildcard ft_*.c)
OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
