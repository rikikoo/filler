/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 16:11:48 by rkyttala          #+#    #+#             */
/*   Updated: 2020/10/17 19:32:41 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# define PLAYER -1
# define VERSUS 1000
/*
# include <sys/types.h>
# include <sys/uio.h>
*/
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "../libft/includes/libft.h"

typedef struct	s_gamedata
{
	int		by;
	int		bx;
	char	p;
	char	v;
	int		ty;
	int		tx;
	int		py;
	int		px;
}				t_game;

typedef struct	s_piece
{
	int				x;
	int				y;
	char			c;
	struct s_pieces	*next;
}				t_piece;

char			**read_board(t_game *game);
char			**read_token(t_game *game);
int				get_player_character(t_game *game);
int				get_dimensions(char *line, t_game *game, int is_board);
void			weigh_board(t_game *game, int **matrix, char **board);
int				place_piece(t_game *game, int **matrix, char **token);
t_piece			scan_token(char **token, char c);
#endif
