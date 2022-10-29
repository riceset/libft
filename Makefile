# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/29 02:25:48 by tkomeno           #+#    #+#              #
#    Updated: 2022/10/29 01:44:35 by tkomeno          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

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

BONUS =		ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c

SRCS_PATH = ./sources/
BONUS_PATH = ./sources/bonus/
INCLUDES_PATH = ./includes/

INCLUDES = -I $(INCLUDES_PATH)

SRCS = $(addprefix $(SRCS_PATH),$(MANDATORY))
BSRCS = $(addprefix $(BONUS_PATH),$(BONUS))

OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)

JSON = compile_commands.json

GREEN = \033[32m
CLEAR_COLOR = \033[0m

PRINT = printf
PRINT_DONE = $(PRINT) "$(GREEN)[done!]$(CLEAR_COLOR)\r"
PRINT_CLEANED = $(PRINT) "$(GREEN)[cleaned!]$(CLEAR_COLOR)\r"

CC = gcc
AR = ar -rc

CFLAGS = -Wall -Wextra -Werror $(INCLUDES)

ifdef WITH_BONUS
	OBJS += $(BOBJS)
endif

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@$(PRINT_DONE)

bonus:
	@$(MAKE) WITH_BONUS=TRUE

clean:
	@$(RM) $(OBJS) $(BOBJS) $(JSON)
	@$(PRINT_CLEANED)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
