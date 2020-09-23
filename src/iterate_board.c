/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterate_board.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 11:39:51 by rkyttala          #+#    #+#             */
/*   Updated: 2020/09/23 14:31:54 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	weigh_cells(t_game *game, int **matrix)
{

}

void	weigh_board(t_game *game, char **board, int **matrix)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (board[y])
	{
		while (board[y][x] != '\0')
		{
			if (board[y][x] == game->p || board[y][x] == game->p + 32)
				matrix[y][x] = -1;
			else if (board[y][x] == game->v || board[y][x] == game->v + 32)
				matrix[y][x] = 100;
			x++;
		}
		y++;
		x = 0;
	}
	weigh_cells(game, matrix);
}
