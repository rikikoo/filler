/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 16:08:14 by rkyttala          #+#    #+#             */
/*   Updated: 2020/09/08 18:26:20 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	get_player(char *str, t_game *game)
{
	if (ft_strnstr(str, PLAYER_NAME, ft_strlen(str)))
		game->c = 'O';
	else
		game->c = 'X';
}

void	get_dimensions(char *str, t_game *game)
{
	int		i;
	int		j;
	char	*rows;
	char	*columns;

	i = 0;
	while (!ft_isdigit(str[i]) && str[i] != 0)
		i++;
	if (str[i] == '\0')
		return ;
	j = i;
	while (ft_isdigit(str[i]))
		i++;
	if (!(rows = ft_strsub(str, j, i - j)))
		return ;
	i++;
	j = i;
	while (ft_isdigit(str[i]))
		i++;
	if (!(columns = ft_strsub(str, j, i - j)))
		return ;
	game->y = ft_atoi(rows);
	game->x = ft_atoi(columns);
}

void	read_instructions(t_game *game)
{
	char	**inst;
	int		i;

	if (!(inst = (char **)malloc(sizeof(char *) * 4)))
		return ;
	inst[3] = NULL;
	i = 0;
	while (i <= 2)
	{
		if ((get_next_line(0, &inst[i])) <= 0)
			return ;
		i++;
	}
	get_player(inst[0], game);
	get_dimensions(inst[2], game);
}

int		main(void)
{
	char	**board;
	t_game	*game;

	if (!(game = (t_game *)malloc(sizeof(t_game))))
		return (-1);
	read_instructions(game);
}
