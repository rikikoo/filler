/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_turn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:40:24 by rkyttala          #+#    #+#             */
/*   Updated: 2020/12/11 20:25:51 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	print_coordinates(t_game *game, t_piece *piece)
{
	int		y;
	int		x;

	y = game->vy - piece->y;
	x = game->vx - piece->x;
	ft_printf("%d %d\n", y, x);
}

void	free_coords(t_piece *coords)
{
	t_piece	*tmp;

	while (coords->next != NULL)
	{
		tmp = coords;
		coords = coords->next;
		free(tmp);
	}
	tmp = coords;
	free(tmp);
}

void	free_token(char **token)
{
	int		i;

	i = 0;
	while (token[i])
	{
		free(token[i]);
		i++;
	}
}
