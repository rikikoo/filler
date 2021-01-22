/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:40:24 by rkyttala          #+#    #+#             */
/*   Updated: 2021/01/22 20:27:55 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	free_list(t_piece *node)
{
	t_piece	*tmp;

	while (node != NULL)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
	free(node);
}

void	free_arrays(char **arr, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		if (arr[i])
		{
			free(arr[i]);
		}
		i++;
	}
	free(arr);
}
