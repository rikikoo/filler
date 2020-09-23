/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 16:11:48 by rkyttala          #+#    #+#             */
/*   Updated: 2020/09/17 14:13:37 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <sys/types.h>
# include <sys/uio.h>
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
}				t_game;

typedef struct	s_pieces
{
	int				x;
	int				y;
	char			c;
	struct s_pieces	*next;
}				t_piece;

int				get_dimensions(char *line, t_game *game, int board);
char			**read_board(t_game *game);
char			**read_token(t_game *game);
t_piece			*scan_token(char **token, char c);
#endif
