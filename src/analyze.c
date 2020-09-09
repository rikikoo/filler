/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:08:03 by rkyttala          #+#    #+#             */
/*   Updated: 2020/09/09 10:20:44 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int	read_token(t_game *game)
{

}

int			read_board(t_game *game)
{
	char	**board;
	char	**token;
	int		i;
	int		ret;

	i = 0;
	if (!(board = (char **)malloc(sizeof(char *) * game->by + 2)))
		return (-1);
	board[game->by + 1] = NULL;
	while (ret = get_next_line(0, &board[i]))
	{
		if (ret == -1)
			return (ret);
		i++;
		if (i == game->y + 1)
			break ;
	}
	if (read_token(game) == -1)
		return (-1);
}
