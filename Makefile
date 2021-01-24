# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/08 18:21:14 by rkyttala          #+#    #+#              #
#    Updated: 2021/01/24 19:36:19 by rkyttala         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Thanks to Neyl JABER (https://stackexchange.com/users/16329214/xenos)
# from the 42 network for this Makefile template.

S = src/
O = obj/
I = includes/

SRC =	$Smain.c \
		$Sparse_input.c \
		$Sweighted_matrix.c \
		$Spiece_coordinates.c \
		$Splacement.c \
		$Sfree.c

OBJ = $(SRC:$S%=$O%.o)

INC = $I

LIB = ../libft/libft.a

CCOMP = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = rkyttala.filler

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ../libft/
	$(CCOMP) $(CFLAGS) $^ $(LIB) -o $@ -I $(INC)

$O:
	@mkdir -p $@

$(OBJ): | $O

$(OBJ): $O%.o: $S%
	$(CCOMP) $(CFLAGS) -c $< -o $@ -I $(INC)

cleanobj:
	rm $(wildcard $(OBJ))

cleanobjdir: cleanobj
	rm -rf $O

clean: cleanobjdir

fclean: clean
	rm -f $(NAME)

re: fclean all
