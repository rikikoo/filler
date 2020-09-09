/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:08:03 by rkyttala          #+#    #+#             */
/*   Updated: 2020/09/09 12:11:14 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
** The format of the line is always "Plateau Y X\n" or "Piece Y X\n",
** where Y is row count and X is column count, thus reading only the digits
** from the line will get us our dimensions easily.
*/
int		get_dimensions(char *str, t_game *game, int board)
{
	int		i;
	int		j;
	char	*rows;
	char	*columns;

	i = 0;
	while (!ft_isdigit(str[i]) && str[i] != 0)
		i++;
	if (str[i] == '\0' || str[i] == '\n')
		return (-1);
	j = i;
	while (ft_isdigit(str[i]))
		i++;
	if (!(rows = ft_strsub(str, j, i - j)))
		return (-1);
	i++;
	j = i;
	while (ft_isdigit(str[i]))
		i++;
	if (!(columns = ft_strsub(str, j, i - j)))
		return (-1);
	if (board)
	{
		game->by = ft_atoi(rows);
		game->bx = ft_atoi(columns);
	}
	else
	{
		game->ty = ft_atoi(rows);
		game->tx = ft_atoi(columns);
	}
	ft_liberator(3, &str, &rows, &columns);
	return (0);
}

int		read_token(t_game *game)
{
	char	**token;
	char	*str;

	if (get_next_line(0, &str) == -1)
		return (-1);
	get_dimensions(str, game, 0);
}

int		read_board(t_game *game)
{
	char	**board;
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
	return (0);
}
