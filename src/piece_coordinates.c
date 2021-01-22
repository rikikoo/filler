/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_coordinates.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 15:49:54 by rkyttala          #+#    #+#             */
/*   Updated: 2021/01/22 17:37:06 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

t_piece	*new_cell(void)
{
	t_piece	*piece;

	if (!(piece = (t_piece *)malloc(sizeof(t_piece))))
		return (NULL);
	piece->y = 0;
	piece->x = 0;
	piece->next = NULL;
	return (piece);
}

void	conv_coord_to_relative(t_piece *piece, t_piece *coords)
{
	int	y_offset;
	int	x_offset;

	y_offset = piece->y;
	x_offset = piece->x;
	while (piece->next != NULL)
	{
		coords->y = piece->y - y_offset;
		coords->x = piece->x - x_offset;
		if (!(coords->next = new_cell()))
			return ;
		piece = piece->next;
		coords = coords->next;
	}
	coords->next = NULL;
}

void	find_coordinates(char **token, t_piece *piece, int rows)
{
	int	y;
	int	x;

	y = -1;
	x = -1;
	while (++y < rows)
	{
		while (token[y][++x] != '\0')
		{
			if (token[y][x] == '*')
			{
				piece->y = y;
				piece->x = x;
				if (!(piece->next = new_cell()))
					return ;
				piece = piece->next;
			}
		}
		x = -1;
	}
	piece->next = NULL;
}
