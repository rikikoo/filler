/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 16:08:14 by rkyttala          #+#    #+#             */
/*   Updated: 2020/09/09 12:09:18 by rkyttala         ###   ########.fr       */
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
	char	*str;
	int		ret;

	ret = get_next_line(0, &str);
	if (ret == -1)
		return (-1);
	if (ft_strchr(str, '1'))
		game->c = 'O';
	else
		game->c = 'X';
	free(str);
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
	char	*str;

	if (!(game = (t_game *)malloc(sizeof(t_game))))
		return (-1);
	init_game(game);
	if (get_player_character(game) == -1)
		return (-1);
	while (1)
	{
		if (game->bx = 0)
		{
			if (get_next_line(0, &str) == -1)
				return (-1);
			if (get_dimensions(str, game, 1) == -1)
				return (-1);
		}
		if (read_board(game) == -1)
			return (-1);
		if (read_token(game) == -1)
			return (-1);
		place_piece(game);
	}
	free(game);
	return (0);
}
