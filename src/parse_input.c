/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:08:03 by rkyttala          #+#    #+#             */
/*   Updated: 2020/12/01 19:25:16 by rkyttala         ###   ########.fr       */
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
		return (0);
	if (get_dimensions(line, game, 0) == -1)
		return (0);
	free(line);
	if (!(token = (char **)malloc(sizeof(char *) * game->ty + 1)))
		return (0);
	token[game->ty] = NULL;
	i = 0;
	while ((ret = get_next_line(0, &token[i])))
	{
		if (ret == -1)
			return (0);
		i++;
		if (i == game->ty)
			break ;
	}
	return (token);
}

/*
** On the first call of read_board a 2d char array is created according to
** previously acquired dimensions and the arrays are filled with what's given.
** On subsequent calls the arrays are over-written by the new board.
** The copied board is returned for further analysis.
*/
char		**read_board(t_game *game)
{
	char	**board;
	int		i;
	int		ret;

	board = NULL;
	i = 0;
	if (!game->ty || !game->tx)
	{
		if (!(board = (char **)malloc(sizeof(char *) * game->by + 2)))
			return (0);
		board[game->by + 1] = NULL;
	}
	while ((ret = get_next_line(0, &board[i])))
	{
		if (ret == -1)
			return (0);
		i++;
		if (i == game->by + 1)
			break ;
	}
	return (board);
}
