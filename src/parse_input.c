/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:08:03 by rkyttala          #+#    #+#             */
/*   Updated: 2021/01/03 20:21:26 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void	store_dimensions(t_game *game, char *rows, char *columns, int board)
{
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
}

/*
** The format of the line is always "Plateau Y X\n" or "Piece Y X\n",
** where Y is row count and X is column count, thus reading only the digits
** from the line will get us our dimensions easily.
** Function's 3rd parameter "board" is set on call to true if we want to store
** the board's dimensions and false for the token's dimensions.
*/

int			get_dimensions(char *line, t_game *game, int is_board)
{
	int		i;
	int		j;
	char	*rows;
	char	*columns;

	i = 0;
	while (!ft_isdigit(line[i]) && line[i] != 0)
		i++;
	if (line[i] == '\0' || line[i] == '\n')
		return (-1);
	j = i;
	while (ft_isdigit(line[i]))
		i++;
	if (!(rows = ft_strsub(line, j, i - j)))
		return (-1);
	i++;
	j = i;
	while (ft_isdigit(line[i]))
		i++;
	if (!(columns = ft_strsub(line, j, i - j)))
		return (-1);
	store_dimensions(game, rows, columns, is_board);
	ft_liberator(2, &rows, &columns);
	return (0);
}

/*
** Since the only number on the first line that the filler sends to the player
** is the player number, it's easy to check whether we are 1 or 2; 'O' or 'X'
*/

int			get_player_character(t_game *game)
{
	char	*line;

	if (get_next_line(0, &line) == -1)
		return (-1);
	if (ft_strchr(line, '1'))
	{
		game->p = 'O';
		game->v = 'X';
	}
	else
	{
		game->p = 'X';
		game->v = 'O';
	}
	free(line);
	return (0);
}

/*
** read_token does basically the same thing as read_board with the exception
** that the token arrays have to be allocated memory on each call, because
** the tokens/pieces vary in size randomly.
*/

char		**read_token(t_game *game)
{
	char	**token;
	char	*line;
	int		i;
	int		ret;

	if (get_next_line(0, &line) == -1)
		return (NULL);
	if (get_dimensions(line, game, 0) == -1)
		return (NULL);
	free(line);
	if (!(token = (char **)malloc(sizeof(char *) * game->ty + 1)))
		return (NULL);
	token[game->ty] = NULL;
	i = 0;
	while ((ret = get_next_line(0, &token[i])))
	{
		if (ret == -1)
			return (NULL);
		i++;
		if (i == game->ty)
			break ;
	}
	return (token);
}

/*
** On the very first call of read_board we skip the first line, because we
** already read the board dimensions before going to the main loop.
** On subsequent calls we get the dimensions in the loop, so we have to read
** those as well, thus filling all arrays from the beginning.
**
** TODO:
** figure out how to skip the dimensions and column number rows.
*/

char		**read_board(t_game *game, char **board)
{
	int		i;
	int		ret;

	if (!game->ty || !game->tx)
	{
		i = 1;
		board[0] = strdup("0 0");
	}
	else
		i = 0;
	while ((ret = get_next_line(0, &board[i])))
	{
		if (ret == -1)
			return (NULL);
		i++;
		if (i == game->by + 2)
			break ;
	}
	return (board);
}
