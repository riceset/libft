# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/29 02:25:48 by tkomeno           #+#    #+#              #
#    Updated: 2022/05/06 04:07:21 by tkomeno          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFLAGS = -Wall -Wextra -Werror -I includes

MANDATORY = ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_strlen.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c

BONUS = ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c

SRCS = $(addprefix srcs/,$(MANDATORY))
BSRCS = $(addprefix srcs/bonus/,$(BONUS))

OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)

CC = gcc
AR = ar -rc

ifdef WITH_BONUS
	OBJS += $(BOBJS)
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

bonus:
	@make all WITH_BONUS=TRUE

clean:
	$(RM) $(OBJS) $(BOBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test: all
	$(CC) -g tests.c libft.a -o tests
	@./tests

bclean: fclean
	$(RM) tests
	$(RM) -r tests.dSYM

debug: test
	lldb tests

norm:
	@norminette -R CheckForbiddenSourceHeader $(SRCS)
	@norminette -R CheckDefine includes/*.h

.PHONY: all clean fclean re bonus all test bclean
