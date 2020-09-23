/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 16:08:14 by rkyttala          #+#    #+#             */
/*   Updated: 2020/09/23 12:54:15 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
** by = board rows
** bx = board columns
** p = player character ('O' or 'X')
** v = versus player character ('O' or 'X')
** ty = token rows
** tx = token columns
*/
static void	init_game(t_game *game)
{
	game->by = 0;
	game->bx = 0;
	game->p = 0;
	game->v = 0;
	game->ty = 0;
	game->tx = 0;
}


int		**init_matrix(t_game *game)
{
	int		y;
	int		x;
	int		**matrix;

	y = 0;
	if (!(matrix = (int **)malloc(sizeof(int*) * game->by)))
		return (0);
	while (y < game->by)
	{
		if (!(matrix[y] = (int *)malloc(sizeof(int) * game->bx)))
			return (0);
		y++;
	}
	y = -1;
	x = -1;
	while (++y < game->by)
	{
		while (++x < game->bx)
			matrix[y][x] = 0;
		x = -1;
	}
	return (matrix);
}

/*
** - initialize game data struct
** - read first two lines for player character and board dimensions
** - initialize an int representation of the board, filled with zeroes
** - in a loop, until the end of game:
**	-- read board situation
**	-- read given token
**	-- place token (i.e. calculate position of piece and output its coordinates)
*/
int			main(void)
{
	t_game	*game;
	char	*line;
	char	**board;
	char	**token;
	int		**matrix;

	if (!(game = (t_game *)malloc(sizeof(t_game))))
		return (-1);
	init_game(game);
	if (get_player_character(game) == -1)
		return (-1);
	if (get_next_line(0, &line) == -1)
		return (-1);
	if (get_dimensions(line, game, 1) == -1)
		return (-1);
	matrix = init_matrix(game);
	while (1)
	{
		board = read_board(game);
		token = read_token(game);
		weigh_board(game, board, &matrix);
		place_piece(game, matrix, board, token));
	}
	free(game);
	return (0);
}
