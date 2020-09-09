/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 16:08:14 by rkyttala          #+#    #+#             */
/*   Updated: 2020/09/09 16:23:19 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
** by = board rows
** bx = board columns
** c = player character ('O' or 'X')
** ty = token rows
** tx = token columns
*/
static void	init_game(t_game *game)
{
	game->by = 0;
	game->bx = 0;
	game->c = 0;
	game->ty = 0;
	game->tx = 0;
}

/*
** since the only number on the first line that the filler sends to the player
** is the player number, it's easy to check whether we are 1 or 2; 'O' or 'X'
*/
static int	get_player_character(t_game *game)
{
	char	*line;
	int		ret;

	ret = get_next_line(0, &line);
	if (ret == -1)
		return (-1);
	if (ft_strchr(line, '1'))
		game->c = 'O';
	else
		game->c = 'X';
	free(line);
	return (0);
}

/*
** - initialize game data struct
** - read first two lines for player character and board dimensions
** - in a loop, until the end of game:
**	-- read board situation
**	-- read given token
**	-- place token (i.e. calculate position of piece and output its coordinates)
*/
int			main(void)
{
	t_game	*game;
	char	*line;
	char	**board;
	char	**token;

	if (!(game = (t_game *)malloc(sizeof(t_game))))
		return (-1);
	init_game(game);
	if (get_player_character(game) == -1)
		return (-1);
	if (get_next_line(0, &line) == -1)
		return (0);
	if (get_dimensions(line, game, 1) == -1)
		return (-1);
// TODO: don't pass line to read_board, because it is free'd in get_dimensions
	while (1)
	{
		board = read_board(game, line);
		token = read_token(game);
		find_placement(game, board, token);
	}
	free(game);
	return (0);
}
