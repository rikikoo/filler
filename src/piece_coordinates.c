/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_coordinates.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 15:49:54 by rkyttala          #+#    #+#             */
/*   Updated: 2020/12/08 20:25:22 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void	find_coordinates(t_piece *piece, char **token)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (token[y] != NULL)
	{
		while (token[y][x] != '\0')
		{
			if (token[y][x] == '*')
			{
				piece->x = x;
				piece->y = y;
				if (!(piece->next = new_cell()))
					return ;
				piece = piece->next;
			}
			x++;
		}
		y++;
		x = 0;
	}
	piece = NULL;
}

t_piece		*new_cell(void)
{
	t_piece		*piece;

	if (!(piece = (t_piece *)malloc(sizeof(t_piece))))
		return (NULL);
	piece->next = NULL;
	return (piece);
}

/*
** TODO:
** for some strange reason the list has one extra node,
** which will linger in memory and might cause leaks?
*/
t_piece		*scan_token(char **token)
{
	t_piece	*piece;
	t_piece *head;

	if (!(piece = ((t_piece *)malloc(sizeof(t_piece)))))
		return (NULL);
	piece->next = NULL;
	head = piece;
	find_coordinates(piece, token);
	return (head);
}
