/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 19:11:55 by rkyttala          #+#    #+#             */
/*   Updated: 2020/10/17 19:39:26 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	find_best_placement(t_game *game, int **matrix, t_piece *piece)
{
	int		y;
	int		x;

	y = -1;
	x = -1;
	while (++y < game->by)
	{
		while (++x < game->bx)
		{
			
		}
	}
}

int			place_piece(t_game *game, int **matrix, char **token)
{
	t_piece	piece;

	piece = scan_token(token, game->p);
	if (!find_best_placement(game, matrix, piece))
		return (0);

}
