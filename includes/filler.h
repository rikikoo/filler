/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 16:11:48 by rkyttala          #+#    #+#             */
/*   Updated: 2020/12/11 19:55:00 by rkyttala         ###   ########.fr       */
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
	int		sum;
	int		vy;
	int		vx;
	int		posy;
	int		posx;
}				t_game;

typedef struct	s_piece
{
	int				x;
	int				y;
	struct s_piece	*next;
}				t_piece;

char			**read_board(t_game *game);
char			**read_token(t_game *game);
int				get_player_character(t_game *game);
int				get_dimensions(char *line, t_game *game, int is_board);
void			fill_matrix(t_game *game, int **matrix, char **board);
int				place_piece(t_game *game, int **matrix, char **token);
t_piece			*scan_token(char **token);
t_piece			*new_cell(void);
void			print_coordinates(t_game *game, t_piece *piece);
void			free_coords(t_piece *coords);
void			free_token(char **token);
#endif
