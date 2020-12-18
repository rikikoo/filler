/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 19:11:55 by rkyttala          #+#    #+#             */
/*   Updated: 2020/12/18 20:30:45 by rkyttala         ###   ########.fr       */
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
			sum = sum + matrix[piece->y + game->posy][piece->x + game->posx];
		piece = piece->next;
	}
	return (!overlap ? 0 : sum);
}

static void		find_highest_sum(t_game *game, int **matrix, t_piece *coords)
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
}

static t_piece	*conv_coord_to_relative(t_piece *piece)
{
	int		y_offset;
	int		x_offset;
	t_piece	*head;
	t_piece *tmp;

	y_offset = piece->y;
	x_offset = piece->x;
	if (!(tmp = new_cell()))
		return (NULL);
	head = NULL;
	while (piece->next != NULL)
	{
		tmp->y = piece->y - y_offset;
		tmp->x = piece->x - x_offset;
		if (!head)
			head = tmp;
		if (!(tmp->next = new_cell()))
			return (NULL);
		piece = piece->next;
		tmp = tmp->next;
	}
	tmp = NULL;
	return (head);
}

int				place_piece(t_game *game, int **matrix, char **token)
{
	t_piece	*piece;
	t_piece *coords;

	piece = find_coordinates(token, -1, -1);
	coords = conv_coord_to_relative(piece);
	find_highest_sum(game, matrix, coords);

/* begin debug print */
	for (int i = 0; i < game->by; i++)
	{
		for (int j = 0; j < game->bx; j++)
			ft_printf("%d\t", matrix[i][j]);
		ft_printf("\n");
	}
	ft_printf("\n");
/* end debug print */

	print_coordinates(game, piece);
	free_list(piece);
	free_list(coords);
	return (1);
}
