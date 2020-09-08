/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 11:11:07 by rkyttala          #+#    #+#             */
/*   Updated: 2020/09/07 19:16:29 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*sub;

	i = 0;
	sub = (char*)malloc(sizeof(char) * len + 1);
	if (sub == NULL)
		return (0);
	else
	{
		while (i < len)
		{
			sub[i] = s[start];
			start++;
			i++;
		}
		sub[i] = '\0';
		return (sub);
	}
}
