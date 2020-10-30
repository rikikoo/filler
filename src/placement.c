/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 19:11:55 by rkyttala          #+#    #+#             */
/*   Updated: 2020/10/30 19:46:46 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int		get_sum(t_game *game, int **matrix, t_piece *piece)
{
	int		overlap;
	int		sum;

	overlap = 0;
	sum = 0;
	while (piece)
	{
		if (game->posy + piece->y > game->by - 1)
			return (0);
		if (game->posx + piece->x < 0 || game->posx + piece->x > game->bx)
			return (0);
		if (matrix[piece->y][piece->x] == PLAYER)
			overlap++;
		if (overlap > 1 || matrix[piece->y][piece->x] == VERSUS)
			return (0);
		if (matrix[piece->y][piece->x] < VERSUS && \
			matrix[piece->y][piece->x] > PLAYER && overlap < 2)
			sum = sum + matrix[piece->y][piece->x];
		piece = piece->next;
	}
	return (sum);
}

static int		find_highest_sum(t_game *game, int **matrix, t_piece *coords)
{
	int		sum;
	t_piece	*head;

	head = coords;
	while (++game->posy < game->by)
	{
		while (++game->posx < game->bx)
		{
			sum = get_sum(game, matrix, coords);
			if (sum > game->sum)
			{
				game->sum = sum;
				game->vy = y;
				game->vx = x;
			}
			coords = head;
		}
		game->posx = -1;
	}
}

static t_piece	*conv_coord_to_relative(t_piece *piece)
{
	int		y_offset;
	int		x_offset;
	t_piece	head;

	head = piece;
	y_offset = piece->y;
	x_offset = piece->x;
	while (piece)
	{
		piece->y = piece->y - y_offset;
		piece->x = piece->x - x_offset;
		piece = piece->next;
	}
	return (head);
}

int				place_piece(t_game *game, int **matrix, char **token)
{
	t_piece	*piece;
	t_piece	*coords;

	piece = scan_token(token, game->p);
	coords = conv_coord_to_relative(piece);
	game->posy = -1;
	game->posx = -1;
	find_highest_sum(game, matrix, coords);
	print_coordinates(piece);
	/*
	** free piece & token, delete matrix content
	*/
	return (1);
}
