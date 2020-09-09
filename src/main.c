/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 16:08:14 by rkyttala          #+#    #+#             */
/*   Updated: 2020/09/09 10:25:37 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void	init_game(t_game *game)
{
	game->by = 0;
	game->bx = 0;
	game->c = 0;
	game->ty = 0;
	game->tx = 0;
}

static int	get_player_character(t_game *game)
{
	char	*str;
	int		ret;

	ret = get_next_line(0, &str);
	if (ret == -1)
		return (-1);
	get_player_character(str, game);
	free(str);
	if (ft_strchr(str, '1'))
		game->c = 'O';
	else
		game->c = 'X';
}

static int	get_dimensions(char *str, t_game *game)
{
	int		i;
	int		j;
	char	*rows;
	char	*columns;

	i = 0;
	while (!ft_isdigit(str[i]) && str[i] != 0)
		i++;
	if (str[i] == '\0')
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
	game->y = ft_atoi(rows);
	game->x = ft_atoi(columns);
	ft_liberator(3, &str, &rows, &columns);
}

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
		if (game->by = 0)
		{
			if (get_next_line(0, &str) == -1)
				return (-1);
			if (get_dimensions(str, game) == -1)
				return (-1);
		}
		if (read_board(game) == -1)
			return (-1);
		place_piece(game);
	}
	free(game);
	return (0);
}
