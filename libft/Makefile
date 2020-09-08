# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/22 11:43:31 by rkyttala          #+#    #+#              #
#    Updated: 2020/09/07 19:29:21 by rkyttala         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

ARCC = ar

ARFLAGS = rc

SOURCES = $(wildcard *.c) ft_printf/csp.c ft_printf/di.c ft_printf/octal.c \
			ft_printf/unsigned.c ft_printf/hexadecimal.c ft_printf/utils.c \
			ft_printf/ft_printf.c ft_printf/parsers.c ft_printf/validate.c \
			ft_printf/float.c

OBJECTS = $(SOURCES:.c=.o)

MAKEFLAGS += --silent

all: $(NAME)

$(NAME): $(OBJECTS)
	$(ARCC) $(ARFLAGS) $(NAME) $(OBJECTS)

$(OBEJCTS):
	$(CC) $(CFLAGS) -I includes -c $(SOURCES)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean
