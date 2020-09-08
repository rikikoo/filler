/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:56:57 by rkyttala          #+#    #+#             */
/*   Updated: 2020/09/07 19:13:48 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*marea;

	marea = (char*)malloc(sizeof(char) * size);
	if (marea == NULL)
		return (0);
	else
	{
		ft_bzero(marea, size);
		return (marea);
	}
}
