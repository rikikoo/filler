/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_coordinates.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 15:49:54 by rkyttala          #+#    #+#             */
/*   Updated: 2020/12/18 20:31:19 by rkyttala         ###   ########.fr       */
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

t_piece	*find_coordinates(char **token, int y, int x)
{
	t_piece *piece;
	t_piece *head;

	if (!(piece = new_cell()))
		return (NULL);
	head = NULL;
	while (token[++y] != NULL)
	{
		while (token[y][++x] != '\0')
		{
			if (token[y][x] == '*')
			{
				piece->y = y;
				piece->x = x;
				if (!(piece->next = new_cell()))
					return (NULL);
				if (!head)
					head = piece;
				piece = piece->next;
			}
		}
		x = -1;
	}
	piece = NULL;
	return (head);
}
