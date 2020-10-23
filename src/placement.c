/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 19:11:55 by rkyttala          #+#    #+#             */
/*   Updated: 2020/10/23 20:10:26 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	get_placement_value(t_game *game, int **matrix, t_piece *piece)
{
	while (piece)
	{
		if (matrix[piece->y][piece->x] == PLAYER)
			overlap++;
		if (matrix[piece->y][piece->x] == '.' && overlap < 2)
			piece = piece->next;
		if (overlap > 1 || matrix[piece->y][piece->x] == VERSUS)
		{
			overlap = 0;
			break ;
		}
	}
}

static int	find_best_placement(t_game *game, int **matrix, t_piece *piece)
{
	int		sum;
	t_piece	*head;

	head = piece;
	while (++game->posy < game->by)
	{
		while (++game->posx < game->bx)
		{
			sum = get_placement_value(game, matrix, piece);
			if (sum > game->sum)
			{
				game->sum = sum;
				game->vy = y;
				game->vx = x;
			}
			piece = head;
		}
		game->posx = -1;
	}
}

int			place_piece(t_game *game, int **matrix, char **token)
{
	t_piece	piece;

	piece = scan_token(token, game->p);
	game->posy = -1;
	game->posx = -1;
	if (!find_best_placement(game, matrix, piece))
		return (0);
	else
		print_coordinates(piece);
	/*
	** free piece & token, delete matrix content
	*/
	return (1);
}
