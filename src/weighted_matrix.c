/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weighted_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 11:39:51 by rkyttala          #+#    #+#             */
/*   Updated: 2020/10/02 22:21:08 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void		weigh_row(t_game *game, int **matrix, int row, int col)
{
	int		x;
	int		val;

	x = col;
	val = matrix[row][col] - 1;
	while (--x >= 0)
	{
		if (matrix[row][x] >= 0 && matrix[row][x] < VERSUS)
			matrix[row][x] = val;
		val--;
		if (matrix[row][x] == VERSUS)
			val = game->value;
	}
	x = col;
	val = matrix[row][col] - 1;
	while (++x < game->by)
	{
		if (matrix[row][x] >= 0 && matrix[row][x] < VERSUS)
			matrix[row][x] = val;
		val--;
		if (matrix[row][x] == VERSUS)
			val = game->value;
	}
}

static void		weights(t_game *game, int **matrix, int row, int col)
{
	int		y;
	int		val;

	y = row;
	val = game->value;
	weigh_row(game, matrix, y, col);
	while (--y >= 0)
	{
		if (matrix[y][col] >= 0 && matrix[y][col] < VERSUS)
			matrix[y][col] = val;
		weigh_row(game, matrix, y, col);
		val--;
		if (matrix[y][col] == VERSUS)
			val = game->value;
	}
	y = row;
	val = game->value;
	while (++y < game->by)
	{
		if (matrix[y][col] >= 0 && matrix[y][col] < VERSUS)
			matrix[y][col] = val;
		weigh_row(game, matrix, y, col);
		val--;
		if (matrix[y][col] == VERSUS)
			val = game->value;
	}
}

static void		mark_players(t_game *game, char **board, int **matrix)
{
	int		y;
	int		x;

	y = 1;
	x = 0;
	while (y <= game->by)
	{
		while (board[y][x] != '\0')
		{
			if (board[y][x] == game->p || board[y][x] == game->p + 32)
				matrix[y - 1][x] = PLAYER;
			else if (board[y][x] == game->v || board[y][x] == game->v + 32)
				matrix[y - 1][x] = VERSUS;
			x++;
		}
		y++;
		x = 0;
	}
}

void			weigh_board(t_game *game, char **board, int **matrix)
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
// delete below until next comment
	ft_printf("\n");
	for (y = 0; y < game->by ; y++)
	{
		for (x = 0; x < game->bx; x++)
			ft_printf("%d\t", matrix[y][x]);
		ft_printf("\n");
	}
// delete until here
}
