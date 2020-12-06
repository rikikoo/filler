/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_coordinates.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 15:49:54 by rkyttala          #+#    #+#             */
/*   Updated: 2020/12/06 21:31:51 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static t_piece	*new_cell(char c)
{
	t_piece		*piece;

	if (!(piece = (t_piece *)malloc(sizeof(t_piece))))
		return (NULL);
	piece->c = c + 32;
	piece->next = NULL;
	return (piece);
}

static void		find_coordinates(t_piece *piece, char **token, char c)
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
				if (!(piece->next = new_cell(c)))
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

/*
** TODO:
** for some strange reason the list has one extra node,
** which will linger in memory and might cause leaks?
*/
t_piece			*scan_token(char **token, char c)
{
	t_piece	*piece;
	t_piece *head;

	if (!(piece = ((t_piece *)malloc(sizeof(t_piece)))))
		return (NULL);
	piece->c = c;
	piece->next = NULL;
	head = piece;
	find_coordinates(piece, token, c);
	return (head);
}
