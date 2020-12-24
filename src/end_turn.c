/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_turn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:40:24 by rkyttala          #+#    #+#             */
/*   Updated: 2020/12/18 20:42:16 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	free_list(t_piece *coords)
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
