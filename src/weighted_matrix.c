/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weighted_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 11:39:51 by rkyttala          #+#    #+#             */
/*   Updated: 2021/01/03 18:28:37 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void		weigh_row(t_game *game, int **matrix, int row, int col)
{
	int		x;
	int		val;

	x = col;
	val = matrix[row][col] - 1;
	while (--x >= 0 && val > 0)
	{
		if (matrix[row][x] >= 0 && matrix[row][x] < VERSUS)
			matrix[row][x] = val;
		val--;
		if (matrix[row][x] == VERSUS)
			val = VERSUS - 1;
	}
	x = col;
	val = matrix[row][col] - 1;
	while (++x < game->bx && val > 0)
	{
		if (matrix[row][x] >= 0 && matrix[row][x] < VERSUS)
			matrix[row][x] = val;
		val--;
		if (matrix[row][x] == VERSUS)
			val = VERSUS - 1;
	}
}

static void		weights(t_game *game, int **matrix, int row, int col)
{
	int		y;
	int		val;

	y = row + 1;
	val = VERSUS - 1;
	while (--y >= 0 && val > 0)
	{
		if (matrix[y][col] >= 0 && matrix[y][col] < VERSUS)
			matrix[y][col] = val;
		weigh_row(game, matrix, y, col);
		val--;
		if (matrix[y][col] == VERSUS)
			val = VERSUS - 1;
	}
	y = row;
	val = VERSUS - 1;
	while (++y < game->by && val > 0)
	{
		if (matrix[y][col] >= 0 && matrix[y][col] < VERSUS)
			matrix[y][col] = val;
		weigh_row(game, matrix, y, col);
		val--;
		if (matrix[y][col] == VERSUS)
			val = VERSUS - 1;
	}
}

/*
** Row index (y) starts from 2 because first rows aren't a part of the game area
**
** Column index (x) starts from 4, because we assume every line to be numbered
** 000, 001, 002, 003,... followed by a space.
** Program breaks if this format is not respected.
**
** TODO:
** make board reading work on arbitrary formats?
*/

static void		mark_players(t_game *game, char **board, int **matrix)
{
	int		y;
	int		x;

	y = 2;
	x = 4;
	while (y <= game->by + 1)
	{
		while (board[y][x] != '\0')
		{
			if (board[y][x] == game->p || board[y][x] == game->p + 32)
				matrix[y - 2][x - 4] = PLAYER;
			else if (board[y][x] == game->v || board[y][x] == game->v + 32)
				matrix[y - 2][x - 4] = VERSUS;
			x++;
		}
		y++;
		x = 0;
	}
}

void			fill_matrix(t_game *game, int **matrix, char **board)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	mark_players(game, board, matrix);
	while (y < game->by)
	{
		while (x < game->bx)
		{
			if (matrix[y][x] == VERSUS)
				weights(game, matrix, y, x);
			x++;
		}
		y++;
		x = 0;
	}
}
