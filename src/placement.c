/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 19:11:55 by rkyttala          #+#    #+#             */
/*   Updated: 2020/12/11 19:49:10 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int		get_sum(t_game *game, int **matrix, t_piece *piece)
{
	int		overlap;
	int		sum;

	overlap = 0;
	sum = 0;
	while (piece->next != NULL)
	{
		if (game->posy + piece->y > game->by - 1)
			return (0);
		if (game->posx + piece->x < 0 || game->posx + piece->x > game->bx)
			return (0);
		if (matrix[piece->y + game->posy][piece->x + game->posx] == PLAYER)
			overlap++;
		if (overlap > 1 || \
		matrix[piece->y + game->posy][piece->x + game->posx] == VERSUS)
			return (0);
		if (matrix[piece->y + game->posy][piece->x + game->posx] < VERSUS && \
		matrix[piece->y + game->posy][piece->x + game->posx] > PLAYER && \
		overlap < 2)
			sum = sum + matrix[piece->y][piece->x];
		piece = piece->next;
	}
	return (!overlap ? 0 : sum);
}

static void		find_highest_sum(t_game *game, int **matrix, t_piece *coords)
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
				game->vy = game->posy;
				game->vx = game->posx;
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
	t_piece	*head;
	t_piece *tmp;

	if (!(head = ((t_piece *)malloc(sizeof(t_piece)))))
		return (NULL);
	tmp = head;
	y_offset = piece->y;
	x_offset = piece->x;
	while (piece->next != NULL)
	{
		tmp->y = piece->y - y_offset;
		tmp->x = piece->x - x_offset;
		piece = piece->next;
		if (!(tmp->next = new_cell()))
			return (NULL);
		tmp = tmp->next;
	}
	return (head);
}

int				place_piece(t_game *game, int **matrix, char **token)
{
	t_piece	*piece;
	t_piece *coords;

	piece = scan_token(token);
	coords = conv_coord_to_relative(piece);
	game->posy = -1;
	game->posx = -1;
	find_highest_sum(game, matrix, coords);
	print_coordinates(game, piece);
	free_coords(piece);
	free_coords(coords);
	/*
	** free token, delete matrix content
	*/
	return (1);
}
