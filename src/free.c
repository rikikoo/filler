/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:40:24 by rkyttala          #+#    #+#             */
/*   Updated: 2021/01/10 19:05:59 by rkyttala         ###   ########.fr       */
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
	free(tmp->next);
	free(tmp);
}

void	free_arrays(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		if (arr[i])
		{
			free(arr[i]);
			arr[i] = NULL;
		}
		i++;
	}
	free(arr[i]);
}
