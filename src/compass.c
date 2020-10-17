/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compass.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 13:54:04 by rkyttala          #+#    #+#             */
/*   Updated: 2020/10/13 19:21:47 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
**static void	check_surroundings(t_game *g, int **mat, int y, int x)
**{
**	if (y - 1 >= 0 && mat[y - 1][x] != VERSUS && mat[y - 1][x] > g->val)
**	{
**		g->val = mat[y - 1][x];
**		g->vy = y - 1;
**		g->vx = x;
**	}
**	if (y + 1 < g->by && mat[y + 1][x] != VERSUS && mat[y + 1][x] > g->val)
**	{
**		g->val = mat[y + 1][x];
**		g->vy = y + 1;
**		g->vx = x;
**	}
**	if (x - 1 >= 0 && mat[y][x - 1] != VERSUS && mat[y - 1][x] > g->val)
**	{
**		g->val = mat[y][x - 1];
**		g->vx = x - 1;
**		g->vy = y;
**	}
**	if (x + 1 < g->bx && mat[y][x + 1] != VERSUS && mat[y + 1][x] > g->val)
**	{
**		g->val = mat[y][x + 1];
**		g->vx = x + 1;
**		g->vy = y;
**	}
**}
*/

static void		check_surroundings(t_game *g, int **mat, int y, int x)
{
	int		val;

	val = 0;
	g->py = y;
	g->px = x;
	if (y - 1 >= 0 && mat[y - 1][x] != VERSUS && mat[y - 1][x] > val)
	{
		val = mat[y - 1][x];
		g->dir = -1;
	}
	if (y + 1 < g->by && mat[y + 1][x] != VERSUS && mat[y + 1][x] > val)
	{
		val = mat[y + 1][x];
		g->dir = 1;
	}
	if (x - 1 >= 0 && mat[y][x - 1] != VERSUS && mat[y - 1][x] > val)
	{
		val = mat[y][x - 1];
		g->dir = -2;
	}
	if (x + 1 < g->bx && mat[y][x + 1] != VERSUS && mat[y + 1][x] > val)
	{
		val = mat[y][x + 1];
		g->dir = 2;
	}
}

/*
** goes through all the surrounding (above, below, left and right) cells of
** the player-filled cells
*/
static void	find_likely_pos(t_game *game, int **matrix)
{
	int		y;
	int		x;

	y = -1;
	x = -1;
	while (++y < game->by)
	{
		while (++x < game->bx)
		{
			if (matrix[y][x] == PLAYER)
				check_surroundings(game, matrix, y, x);
		}
		x = -1;
	}
}

int			compass(t_game *game, int **matrix, char **token)
{
	int		ret;
	int		y;
	int		x;
	t_piece	piece;

	find_likely_pos(game, matrix);
	piece = scan_token(token, game->p);
	y = game->py;
	x = game->px;
	while (y >= 0 && y < game->by)
	{
		while (x >= 0 && x < game->bx)
		{
			ret = place_piece(game, matrix, token);
			if (!ret)
		}
	}
	while (--game->ty >= 0)
	{
		free(token[game->ty]);
		token[game->ty] = NULL;
	}
	return (ret);
}
