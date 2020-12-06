/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_turn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:40:24 by rkyttala          #+#    #+#             */
/*   Updated: 2020/11/01 17:45:36 by rkyttala         ###   ########.fr       */
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
