/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 19:11:55 by rkyttala          #+#    #+#             */
/*   Updated: 2021/01/08 21:10:03 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int	get_sum(t_game *game, int **matrix, t_piece *piece)
{
	int		overlap;
	int		sum;

	overlap = 0;
	sum = 0;
	while (piece->next != NULL)
	{
		if (game->posy + piece->y >= game->by)
			return (0);
		if (game->posx + piece->x < 0 || game->posx + piece->x >= game->bx)
			return (0);
		if (matrix[piece->y + game->posy][piece->x + game->posx] == PLAYER)
			overlap++;
		if (overlap > 1 || \
			matrix[piece->y + game->posy][piece->x + game->posx] == VERSUS)
			return (0);
		if (matrix[piece->y + game->posy][piece->x + game->posx] < VERSUS && \
			matrix[piece->y + game->posy][piece->x + game->posx] > PLAYER && \
			overlap < 2)
			sum = sum + matrix[piece->y + game->posy][piece->x + game->posx];
		piece = piece->next;
	}
	return (!overlap ? 0 : sum);
}

static int	find_highest_sum(t_game *game, int **matrix, t_piece *coords)
{
	int		sum;
	t_piece	*head;

	head = coords;
	game->sum = 0;
	game->posy = -1;
	game->posx = -1;
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
	return (game->sum > 0 ? 1 : 0);
}

int			place_piece(t_game *game, int **matrix, char **token)
{
	t_piece	*piece;
	t_piece *coords;
	int		ret;

	piece = find_coordinates(token, -1, -1);
	coords = conv_coord_to_relative(piece);
	ret = find_highest_sum(game, matrix, coords);
	ft_printf("%d %d\n", game->vy - piece->y, game->vx - piece->x);
	free_list(piece);
	free_list(coords);
	free_arrays(token);
	return (ret);
}
