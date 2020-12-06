# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/08 18:21:14 by rkyttala          #+#    #+#              #
#    Updated: 2020/12/01 20:16:32 by rkyttala         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c parse_input.c weighted_matrix.c piece_coordinates.c placement.c

OBJ = $(SRC_NAME:%.c=%.o)

SRC_DIR = src/

OBJ_DIR = obj/

INC = includes/

HEADER = filler.h

LIB = ../libft/libft.a

FLAGS = -Wall -Wextra -Werror

NAME = rkyttala.filler

all: $(NAME)

$(NAME): $(OBJ)
	make -C ../libft/
	gcc $(prefix )

$(OBJ):
	mkdir $(OBJ_DIR)
	gcc -c $(FLAGS) $(prefix: SRC_DIR)
