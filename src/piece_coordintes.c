/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 15:49:54 by rkyttala          #+#    #+#             */
/*   Updated: 2020/09/11 18:23:21 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static t_piece	new_piece(char c)
{
	if (!(piece = (t_piece *)malloc(sizeof(t_piece))))
		return (0);
	piece->c = c + 32;
	piece->next = NULL;
	return (piece);
}

static void		find_placement(t_piece *piece, char **token, char c)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (token[y][x] != '\0')
	{
		while(token[y])
		{
			if (token[y][x] == '*')
			{
				piece->x = x;
				piece->y = y;
				if (!(piece->next = new_piece(c)))
					return ;
				piece = piece->next;
			}
			y++;
		}
		x++;
		y = 0;
	}
}

t_piece			*scan_token(char **token, char c)
{
	t_piece	*piece;
	t_piece *head;
	int		i;

	piece = new_piece(c);
	head = piece;
	find_placement(piece, token, c);
	i = 0;
	while (token[i])
	{
		free(token[i]);
		token[i] = NULL;
		i++;
	}
	return (head);
}
