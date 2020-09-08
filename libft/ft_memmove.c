/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 20:26:47 by rkyttala          #+#    #+#             */
/*   Updated: 2020/09/07 19:14:08 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		tmp[len + 1];

	i = 0;
	if ((!dst && !src) || !len)
		return (dst);
	if (len > 32767)
		return (dst);
	else
	{
		while (i < len)
		{
			tmp[i] = ((char*)src)[i];
			i++;
		}
		i = 0;
		while (i < len)
		{
			((char*)dst)[i] = tmp[i];
			i++;
		}
	}
	return ((char*)dst);
}
